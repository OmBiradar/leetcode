#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minDistance(string w1, string w2) {
    int n = w1.size(), m = w2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MAX));
    // dp[i][j] = min ops to get s[:i] == t[:j] true
    // base cases
    dp[0][0] = 0;
    for (int i = 0; i <= n; i++)
      dp[i][0] = i;
    for (int j = 0; j <= m; j++)
      dp[0][j] = j;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) {
        // update dp[i][j]
        // if (s[i-1] == t[j-1]) then dp[i-1][j-1]
        // else max of dp[i-1][j] (add) and dp[i][j-1] (remove)
        if (w1[i - 1] == w2[j - 1])
          dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
        else
          dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
      }
    return dp[n][m];
  }
};