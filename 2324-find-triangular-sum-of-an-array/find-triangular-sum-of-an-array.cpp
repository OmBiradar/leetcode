class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            int sz = n - 1 - i;
            vector<int> New_Nums(sz);
            for (int j = 0; j < sz; j++) {
                New_Nums[j] = (nums[j] + nums[j+1]) % 10;
            }
            swap(New_Nums, nums);
        }
        return nums[0];
    }
};