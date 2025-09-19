#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minNumberOperations(vector<int> &target) {
    // every uphill needs to be bulid
    // from where to where is a complex topic
    // but here just count, and we can easily
    int ans = target[0];
    for (int i = 1; i < target.size(); i++) {
      ans += target[i] - target[i - 1] > 0 ? target[i] - target[i - 1] : 0;
    }
    return ans;
  }
};