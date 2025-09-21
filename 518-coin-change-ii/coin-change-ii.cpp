#include <vector>
#include <numeric>

class Solution {
public:
  int change(int amount, std::vector<int>& coins) {
    // dp[i] will store the number of combinations to make amount i.
    // The size is amount + 1 to handle amounts from 0 to 'amount'.
    // We use a vector of unsigned int to be safe against overflow for
    // intermediate values, as the number of combinations can grow large.
    std::vector<unsigned int> dp(amount + 1, 0);

    // Base case: There is exactly one way to make an amount of 0,
    // which is by choosing no coins.
    dp[0] = 1;

    // Iterate through each available coin denomination.
    for (int coin : coins) {
      // For each coin, update the dp array. We start from the coin's value
      // because we can't make an amount smaller than the coin itself.
      for (int i = coin; i <= amount; ++i) {
        // The number of ways to form amount 'i' is the sum of:
        // 1. The number of ways to form 'i' without using the current 'coin' (already in dp[i]).
        // 2. The number of ways to form 'i - coin' (which is dp[i - coin]),
        //    to which we can add the current 'coin'.
        dp[i] += dp[i - coin];
      }
    }

    // The final answer is the number of ways to make the target 'amount'.
    return dp[amount];
  }
};