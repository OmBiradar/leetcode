#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxProfit(vector<int>& prices) {
    // here at most 2 seperate transactions (no intermix)
    // if 1 up hill trend then 1 transaction
    // if 2 or more hills then 2
    // if more than 2 then choose best 2
    // simple?
    // problem when b1 < b2 < s1 < s2
    // more profit can be made but greedily we ignore this
    // the greedy isn't programmable too because we
    // know only 1 stopping condition
    // missing out on potential profit
    // something to check all states (DP again XD)
    // clever but technique soln
    // states
    int b1 = INT_MIN, s1 = 0, b2 = INT_MIN, s2 = 0;
    for (auto p : prices) {
      b1 = max(b1, 0 - p);
      s1 = max(s1, p + b1);
      b2 = max(b2, s1 - p);
      s2 = max(s2, b2 + p);
    }
    return s2;
  }
};