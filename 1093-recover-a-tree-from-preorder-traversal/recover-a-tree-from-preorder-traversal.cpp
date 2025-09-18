#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

class Solution {
public:
  vector<pair<int, int>> nodes; // depth, value
  int idx = 0;                  // parser for nodes vector above
  TreeNode *recoverFromPreorder(string traversal) {
    long long n = traversal.size();
    for (int i = 0; i < n; i++) {
      int d = i;
      // get depth
      for (; d < n; d++) {
        if (traversal[d] != '-')
          break;
      }
      d--;
      int ne = d + 1;
      for (; ne < n; ne++) {
        if (!(traversal[ne] >= '0' && traversal[ne] <= '9'))
          break;
      }
      ne--;
      int num = stoi(traversal.substr(d + 1, ne - d));
      nodes.push_back({d - i + 1, num});
      i = ne;
    }
    return build(0);
  }
  TreeNode *build(int depth) {
    if (idx >= nodes.size() || nodes[idx].first != depth)
      return nullptr;
    TreeNode *root = new TreeNode(nodes[idx++].second);
    root->left = build(depth + 1);
    root->right = build(depth + 1);

    return root;
  }
};