#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  long long maximumProfit(vector<int> &prices, int k) {
    // DP state
    // [i][k][state]
    // i for ith day
    // k for kth movement
    // state for either nothing (5 star khao) (0) or normal (1) or short(2)
    const long long INF = 1e18;
    long long n = prices.size();
    vector<vector<vector<long long>>> dp(
        n, vector<vector<long long>>(k + 1, vector<long long>(3, -INF)));
    // base base base
    dp[0][0][0] = 0;
    dp[0][0][1] = -prices[0];
    dp[0][0][2] = prices[0];
    for (long long i = 1; i < n; i++) {
      for (long long j = 0; j <= k; j++) {
        // update all states
        // dp[i][j][0];
        dp[i][j][0] = dp[i - 1][j][0];
        if (j > 0) {
          dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j - 1][1] + prices[i]);
          dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j - 1][2] - prices[i]);
        }
        // dp[i][j][1];
        dp[i][j][1] = dp[i - 1][j][1];
        dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j][0] - prices[i]);
        // dp[i][j][2];
        dp[i][j][2] = dp[i - 1][j][2];
        dp[i][j][2] = max(dp[i][j][2], dp[i - 1][j][0] + prices[i]);
      }
    }
    long long mx_profit = 0;
    for (int j = 0; j <= k; j++) {
      mx_profit = max(mx_profit, dp[n - 1][j][0]);
    }
    return mx_profit;
  }
};