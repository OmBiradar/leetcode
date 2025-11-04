class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int cur = 0, sum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (2 * cur == sum - nums[i]) {
                return i;
            }
            cur += nums[i];
        }
        return -1;
    }
};