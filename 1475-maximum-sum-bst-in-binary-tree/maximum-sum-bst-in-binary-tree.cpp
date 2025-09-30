#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

/**
 * Definition for a binary tree node.
 */
class Solution {
public:
    // This structure will hold the package of information for each node.
    // { is_bst, min_val, max_val, sum }
    struct NodeInfo {
        bool is_bst;
        int min_val;
        int max_val;
        int sum;
    };

    int max_sum = 0;

    NodeInfo postOrderTraversal(TreeNode* node) {
        // Base case: A null node is a valid BST with sum 0.
        // min_val is set high and max_val is set low to be easily overwritten.
        if (!node) {
            return {true, INT_MAX, INT_MIN, 0};
        }

        // Get info from left and right children
        NodeInfo left_info = postOrderTraversal(node->left);
        NodeInfo right_info = postOrderTraversal(node->right);

        // Check if the current node can be the root of a valid BST
        if (left_info.is_bst && right_info.is_bst &&
            node->val > left_info.max_val &&
            node->val < right_info.min_val) {
            
            // It's a valid BST. Calculate the new sum.
            int current_sum = node->val + left_info.sum + right_info.sum;
            
            // Update the global maximum sum found so far.
            max_sum = max(max_sum, current_sum);

            // Return the new info package for the parent.
            return {
                true,
                min(node->val, left_info.min_val),
                max(node->val, right_info.max_val),
                current_sum
            };
        }

        // If it's not a valid BST, propagate failure upwards.
        return {false, 0, 0, 0};
    }

    int maxSumBST(TreeNode* root) {
        postOrderTraversal(root);
        return max_sum > 0 ? max_sum : 0; // The problem asks for 0 if no positive sum BST exists.
    }
};