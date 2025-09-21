#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int change(int amount, vector<int> &coins) {
    // to count number of ways to make the amount
    // unique ways only
    vector<unsigned long long> dp(amount + 1, 0);
    dp[0] = 1; // 1 way to make 0 total amount
    for (auto c : coins) {
      for (int i = c; i <= amount; i++) {
        dp[i] += dp[i - c];
      }
    }
    return dp[amount];
  }
};


// #include <vector>
// #include <numeric>

// class Solution {
// public:
//   int change(int amount, std::vector<int>& coins) {
//     std::vector<unsigned int> dp(amount + 1, 0);
//     dp[0] = 1;
//     for (int coin : coins) {
//       for (int i = coin; i <= amount; ++i) {
//         dp[i] += dp[i - coin];
//       }
//     }
//     return dp[amount];
//   }
// };