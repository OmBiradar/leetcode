#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  const long long MOD = 1e9 + 7;
  int colorTheGrid(int m, int n) {
    // DP on profiles -> match profile which are compatible
    // cnt no of matches possible
    auto isValid = [&](int mask) {
      int prev = -1;
      for (int i = 0; i < m; i++) {
        if (mask % 3 == prev)
          return false;
        prev = mask % 3;
        mask /= 3;
      }
      return true;
    };
    vector<bool> valid(pow(3, m), false);
    for (int MASK = 0; MASK < valid.size(); MASK++) {
      valid[MASK] = isValid(MASK);
    }
    vector<vector<long long>> dp(pow(3, m), vector<long long>(n, 0));
    for (int mask = 0; mask < valid.size(); mask++) {
      if (valid[mask])
        dp[mask][0] = 1;
    }
    vector<vector<int>> match(valid.size());
    auto matching = [&](int m1, int m2) {
      for (int i = 0; i < m; i++) {
        int c1 = m1 % 3, c2 = m2 % 3;
        if (c1 == c2)
          return false;
        m1 /= 3, m2 /= 3;
      }
      return true;
    };
    for (int mask_1 = 0; mask_1 < valid.size(); mask_1++) {
      for (int mask_2 = 0; mask_2 < valid.size(); mask_2++) {
        if (!valid[mask_2] || !valid[mask_1])
          continue;
        if (matching(mask_1, mask_2)) {
          match[mask_2].push_back(mask_1);
        }
      }
    }
    for (int col = 1; col < n; col++) {
      for (int mask = 0; mask < valid.size(); mask++) {
        if (!valid[mask])
          continue;
        for (auto prev_mask : match[mask]) {
          dp[mask][col] = (dp[mask][col] + dp[prev_mask][col - 1]) % MOD;
        }
      }
    }
    long long ans = 0;
    for (int mask = 0; mask < valid.size(); mask++)
      ans = (ans + dp[mask][n - 1]) % MOD;
    return ans;
  }
};