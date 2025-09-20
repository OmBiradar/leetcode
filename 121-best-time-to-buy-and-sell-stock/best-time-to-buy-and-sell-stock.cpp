#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int low = -1, mx = 0;
    for (auto p : prices) {
      if (low != -1) {
        if (p - low > mx)
          mx = p - low;
      }
      if (low == -1)
        low = p;
      low = min(low, p);
    }
    return mx;
  }
};