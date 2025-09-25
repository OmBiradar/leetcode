#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int subarraysWithKDistinct(vector<int> &nums, int k) {
    int n = nums.size();
    function<int(int)> maxK = [&](int K) {
      map<int, int> f;
      int l = 0;
      int cnt = 0;
      for (int r = 0; r < n; r++) {
        f[nums[r]]++;
        while (f.size() > K) {
          f[nums[l]]--;
          if (f[nums[l]] == 0)
            f.erase(nums[l]);
          l++;
        }
        cnt += r - l + 1;
      }
      return cnt;
    };
    return maxK(k) - maxK(k - 1);
  }
};