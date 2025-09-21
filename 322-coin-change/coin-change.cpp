#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int coinChange(vector<int> &coins, int amount) {
    vector<long long> dp(amount + 1, -1);
    dp[0] = 0;
    for (int i = 0; i <= amount; i++) {
      if (dp[i] == -1)
        continue;
      for (auto c : coins)
        if (1LL * c + i <= amount)
          if (dp[c + i] == -1)
            dp[c + i] = 1 + dp[i];
          else
            dp[c + i] = min(dp[c + i], 1 + dp[i]);
    }
    return dp[amount] >= INT_MAX ? -1 : dp[amount];
  }
};
