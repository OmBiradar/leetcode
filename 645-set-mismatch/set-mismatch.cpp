#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> findErrorNums(vector<int> &nums) {
    vector<bool> freq(nums.size(), 0);
    int dup = -1;
    for (auto x : nums) {
      if (freq[x]) {
        dup = x;
      } else
        freq[x] = true;
    }
    int mis = -1;
    for (int i = 1; i <= nums.size(); i++)
      if (!freq[i]) {
        mis = i;
        break;
      }
    return {dup, mis};
  }
};