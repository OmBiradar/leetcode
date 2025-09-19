#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int mergeStones(vector<int> &stones, int k) {
    // every move reduces size by k - 1
    // we need to reduce in total n - 1
    // moves = (n - 1) / (k - 1)
    // if not perfectly divisible, then no answer
    int n = stones.size();
    if ((n - 1) % (k - 1))
      return -1;
    // good thing to have
    vector<int> pref(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      pref[i] = pref[i - 1] + stones[i - 1];
    }
    // RaNgE Dp
    // DP[l][r][pile] -> cost to put (l, r) stones into pile piles
    vector<vector<vector<int>>> dp(
        n, vector<vector<int>>(n, vector<int>(k + 1, INT_MAX)));
    // base case
    // every (i, i) for pile = 1, is already there
    // so dp[i][i][1] = 0
    for (int i = 0; i < n; i++)
      dp[i][i][1] = 0;
    // 3 D meaning calculate in i, j, and p
    // for len = 2 to n increamently calculate
    for (int len = 2; len <= n; len++) {
      for (int i = 0; i <= n - len; i++) {
        int j = i + len - 1;
        for (int p = 2; p <= k; p++) {
          for (int m = i; m < j; m++) { // point of split (m is left side)
            if (dp[i][m][p - 1] != INT_MAX && dp[m + 1][j][1] != INT_MAX) {
              dp[i][j][p] = min(dp[i][j][p], dp[i][m][p - 1] + dp[m + 1][j][1]);
            }
          }
        }
        // as cost of stones were neglected
        if (dp[i][j][k] != INT_MAX)
          dp[i][j][1] = dp[i][j][k] + pref[j + 1] - pref[i];
      }
    }
    return dp[0][n - 1][1];
  }
};