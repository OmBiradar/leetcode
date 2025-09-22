#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int findNumberOfLIS(vector<int> &nums) {
    int n = nums.size();
    // looks like dp normal solution and counting the end points of the
    // sequences
    vector<int> dp(n, 1), counts(n, 1);
    int cnt = n;
    for (int i = 1; i < n; i++)
      for (int j = i - 1; j >= 0; j--)
        if (nums[i] > nums[j])
          if (dp[j] + 1 > dp[i]) {
            dp[i] = dp[j] + 1;
            counts[i] = counts[j];
            dp[i] = max(dp[i], dp[j] + 1);
          } else if (dp[j] + 1 == dp[i]) {
            counts[i] += counts[j];
          }
    int mx_len = *max_element(dp.begin(), dp.end());
    int ans = 0;
    for (int i = 0; i < n; i++)
      if (dp[i] == mx_len)
        ans += counts[i];
    return ans;
  }
};