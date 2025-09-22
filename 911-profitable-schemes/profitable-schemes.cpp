#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int profitableSchemes(int n, int minProfit, vector<int> &group,
                        vector<int> &profit) {
    // job i gives profit[i] and required group[i] pepole
    // given that the group has only n members
    // what number of ways to get atleast minProfit profit ?
    vector<vector<int>> dp(n + 1, vector<int>(minProfit + 1, 0));
    // dp[g][p] = number of ways to get exactly g people to generate p profit
    dp[0][0] = 1;
    // MOD
    const int MOD = 1e9 + 7;
    // empty set of crimes requires 0 members = 0 profit
    for (int k = 0; k < group.size(); k++) {
      int g_k = group[k];
      int p_k = profit[k];
      for (int g = n; g >= g_k; g--) {
        for (int p = minProfit; p >= 0; p--) {
          dp[g][min(p + p_k, minProfit)] =
              (dp[g][min(p + p_k, minProfit)] + dp[g - g_k][p]) % MOD;
        }
      }
    }
    long long total = 0;
    for (int g = 0; g <= n; g++) {
      total = (total + dp[g][minProfit]) % MOD;
    }
    return total;
  }
};