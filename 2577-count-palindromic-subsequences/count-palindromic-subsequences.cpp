class Solution {
public:
    int countPalindromes(string s) {
        const int MOD = 1e9 + 7;
        int n = s.size();

        vector<vector<long long>> pre2(10, vector<long long>(10, 0));
        vector<vector<long long>> pre1(n + 1, vector<long long>(10, 0));
        vector<vector<long long>> suf2(10, vector<long long>(10, 0));
        vector<vector<long long>> suf1(n + 1, vector<long long>(10, 0));

        // prefix single digit counts
        for (int i = 0; i < n; i++) {
            pre1[i + 1] = pre1[i];
            pre1[i + 1][s[i] - '0']++;
        }

        // suffix single digit counts
        for (int i = n - 1; i >= 0; i--) {
            suf1[i] = suf1[i + 1];
            suf1[i][s[i] - '0']++;
        }

        // prefix 2-length subsequence counts
        vector<vector<long long>> pre2dp(n + 1, vector<long long>(100, 0));
        for (int i = 0; i < n; i++) {
            if (i > 0) pre2dp[i + 1] = pre2dp[i];
            int x = s[i] - '0';
            for (int y = 0; y < 10; y++) {
                pre2dp[i + 1][y * 10 + x] += pre1[i][y];
            }
        }

        // suffix 2-length subsequence counts
        vector<vector<long long>> suf2dp(n + 1, vector<long long>(100, 0));
        for (int i = n - 1; i >= 0; i--) {
            if (i < n - 1) suf2dp[i] = suf2dp[i + 1];
            int x = s[i] - '0';
            for (int y = 0; y < 10; y++) {
                suf2dp[i][x * 10 + y] += suf1[i + 1][y];
            }
        }

        long long ans = 0;
        for (int i = 2; i < n - 2; i++) {
            for (int a = 0; a < 10; a++) {
                for (int b = 0; b < 10; b++) {
                    ans = (ans + pre2dp[i][a * 10 + b] * suf2dp[i + 1][b * 10 + a]) % MOD;
                }
            }
        }

        return ans;
    }
};
