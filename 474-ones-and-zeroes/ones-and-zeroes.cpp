class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        // 3d dp actually
        // dp[i][j][k]
        // i -> till i string
        // j, k -> string has j zeros and k ones
        // but we need update only j and k
        // so removing i won't matter that much
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int k = 0; k < strs.size(); k++) {
            int cnt0 = 0, cnt1 = 0;
            for (auto c : strs[k]) if (c == '1') cnt1++;
            else cnt0++;
            for (int i = m; i >= cnt0; i--) {
                for (int j = n; j >= cnt1; j--) {
                    dp[i][j] = max(dp[i][j], 1 + dp[i - cnt0][j - cnt1]);
                }
            }
        }
        return dp[m][n];
    }
};