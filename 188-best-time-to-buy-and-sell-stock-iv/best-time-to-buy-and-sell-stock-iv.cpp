#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxProfit(int k, vector<int> &prices) {
    // same state management
    // here manage k states for buy and sell
    // DP[k][2] // 0 buy and 1 sell
    // base -> 0 -> INT_MIN, and 1 -> 0
    int n = prices.size();
    vector<pair<int, int>> dp(k);
    for (auto &d : dp) {
      d.first = INT_MIN;
      d.second = 0;
    }
    for (auto p : prices) {
      for (int i = 0; i < k; i++) {
        dp[i].first = max(dp[i].first, i == 0 ? 0 - p : dp[i - 1].second - p);
        dp[i].second = max(dp[i].second, dp[i].first + p);
      }
    }
    return dp[k - 1].second;
  }
};