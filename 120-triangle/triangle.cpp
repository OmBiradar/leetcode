#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minimumTotal(vector<vector<int>> &triangle) {
    int n = triangle.size();
    vector<vector<int>> dp = triangle;
    for (int i = 1; i < n; i++) {
      // i + 1 indices to update
      for (int j = 0; j <= i; j++) {
        if (j == 0)
          dp[i][j] += dp[i - 1][j];
        else if (j == i)
          dp[i][j] += dp[i - 1][j - 1];
        else
          dp[i][j] += min(dp[i - 1][j], dp[i - 1][j - 1]);
      }
    }
    return *min_element(dp.back().begin(), dp.back().end());
  }
};