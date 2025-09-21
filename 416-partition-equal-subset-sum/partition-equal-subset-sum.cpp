class Solution {
public:
    bool canPartition(vector<int>& nums) {
        long long S = accumulate(nums.begin(), nums.end(), 0LL);
        if (S % 2) return false;
        S /= 2;
        // form S from the remaining elements
        sort(nums.begin(), nums.end());
        vector< bool> dp(S + 1, false);
        dp[0] = true;
        for (auto n : nums) {
            for (int i = S; i >= n; i--) {
                if (dp[i - n]) {
                    dp[i] = true;
                }
            }
        }
        return dp[S];
    }
};