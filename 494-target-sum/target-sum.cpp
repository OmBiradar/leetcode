// #include <bits/stdc++.h>
// using namespace std;
//
// class Solution {
// public:
//   long long cnt = 0, TARGET;
//   void solve(vector<int> &nums, long long cur, int idx) {
//     if (idx == nums.size()) {
//       if (cur == TARGET)
//         cnt++;
//       return;
//     }
//     solve(nums, cur + nums[idx], idx + 1);
//     solve(nums, cur - nums[idx], idx + 1);
//   }
//   int findTargetSumWays(vector<int> &nums, int target) {
//     // the length of nums is just 20 at max
//     // bit mask dp
//     TARGET = target;
//     solve(nums, 0, 0);
//     return cnt;
//   }
// };

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int findTargetSumWays(vector<int> &nums, int target) {
    // DP approach
    // Knapsack DP
    // If suppose s1 be the +ve numbers, and s2 be the -ve numbers
    // then toal = s1 + s2
    // target = s1 - s2
    // s1 = (total + target) / 2
    // find if s1 is possible to make or not
    // use dp and find
    // early eliminate if (total + target) % 2 == 1
    // or if abs(target) > total
    long long total = accumulate(nums.begin(), nums.end(), 0LL);
    if (total < 1LL * abs(target))
      return 0;
    long long S1 = total + target;
    if (S1 % 2)
      return 0;
    S1 /= 2;
    vector<long long> dp(S1 + 1, 0);
    dp[0] = 1;
    for (auto num : nums) {
      for (int i = S1; i >= num; i--)
        dp[i] = dp[i] + dp[i - num];
    }
    return dp[S1];
  }
};
