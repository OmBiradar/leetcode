#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int longestCommonSubsequence(string text1, string text2) {
    int n = text1.size(), m = text2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    // dp where LCS = dp[i][j] considering text1[:i] and text2[1:j]
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
      dp[i][0] = 0;
    }
    for (int j = 0; j < m; j++) {
      dp[0][j] = 0;
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        // when equal, then prev + 1 else just best of both worlds
        if (text1[i - 1] == text2[j - 1]) {
          dp[i][j] = max(dp[i][j], 1 + dp[i - 1][j - 1]);
        } else {
          dp[i][j] = max(dp[i][j], max(dp[i - 1][j], dp[i][j - 1]));
        }
      }
    }
    return dp[n][m];
  }
};