#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int canCross(vector<int> &stones) {
    if (stones[1] - stones[0] != 1)
      return false;
    unordered_map<int, unordered_set<int>> dp;
    for (int s : stones)
      dp[s] = {};
    dp[stones[1]].insert(1);
    for (int i = 1; i < stones.size(); i++) {
      for (int k : dp[stones[i]]) {
        for (int k_u = k - 1; k_u <= k + 1; k_u++) {
          if (k_u > 0)
            if (dp.count(stones[i] + k_u))
              dp[stones[i] + k_u].insert(k_u);
        }
      }
    }
    return dp[stones.back()].empty() ? false : true;
  }
};