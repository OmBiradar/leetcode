#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int numSubarrayProductLessThanK(vector<int> &nums, int k) {
    int l = 0, r = 0;
    long long cur = 1;
    int cnt = 0;
    int n = nums.size();
    for (int r = 0; r < n; r++) {
      cur *= nums[r];
      while (cur >= k && l < r) {
        cur /= nums[l];
        l++;
      }
      if (cur < k)
        cnt += (r - l + 1);
    }
    return cnt;
  }
};