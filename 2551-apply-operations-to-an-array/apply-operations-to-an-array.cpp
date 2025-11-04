class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: Apply the given operations
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1] && nums[i] != 0) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }

        // Step 2: Shift non-zeros to the front
        vector<int> result;
        result.reserve(n);

        for (int x : nums) {
            if (x != 0) result.push_back(x);
        }

        // Fill remaining with zeros
        while (result.size() < n) result.push_back(0);

        return result;
    }
};
