#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  long long cnt = 0, TARGET;
  void solve(vector<int> &nums, long long cur, int idx) {
    if (idx == nums.size()) {
      if (cur == TARGET)
        cnt++;
      return;
    }
    solve(nums, cur + nums[idx], idx + 1);
    solve(nums, cur - nums[idx], idx + 1);
  }
  int findTargetSumWays(vector<int> &nums, int target) {
    // the length of nums is just 20 at max
    // bit mask dp
    TARGET = target;
    solve(nums, 0, 0);
    return cnt;
  }
};