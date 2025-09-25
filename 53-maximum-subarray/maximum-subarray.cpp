#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int mx = nums[0], cur = nums[0];
    int n = nums.size();
    for (int i = 1; i < n; i++) {
      cur = max(nums[i], cur + nums[i]);
      mx = max(cur, mx);
    }
    return mx;
  }
};