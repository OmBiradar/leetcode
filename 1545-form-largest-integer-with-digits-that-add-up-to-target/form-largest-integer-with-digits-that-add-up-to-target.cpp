#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string largestNumber(vector<int> &cost, int target) {
    // largest possible number considering budget of i is dp[i]
    vector<string> dp(target + 1, "#");
    dp[0] = "";
    for (int t = 1; t <= target; t++) {
      // for each budget, try to put a digit in front of prev
      // answers obtained
      for (int d = 9; d >= 1; d--) {
        int c = cost[d - 1];
        // if curr budget is >= cost
        if (t >= c && dp[t - c] != "#") {
          string candidate = char(d + '0') + dp[t - c];
          // if either the dp is empty
          // or our cur number is better than prev answers
          if (dp[t] == "#" || candidate.size() > dp[t].size() ||
              (candidate.size() == dp[t].size() && candidate > dp[t])) {
            dp[t] = candidate;
          }
        }
      }
    }
    return dp[target] == "#" ? "0" : dp[target];
  }
};