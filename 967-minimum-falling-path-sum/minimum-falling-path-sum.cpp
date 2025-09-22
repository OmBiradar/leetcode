#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minFallingPathSum(vector<vector<int>> &matrix) {
    // intuition based matrix dp
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
      dp[0][i] = matrix[0][i];
    for (int i = 1; i < m; i++)
      for (int j = 0; j < n; j++)
        dp[i][j] = matrix[i][j] +
                   min({j == 0 ? INT_MAX : dp[i - 1][j - 1], dp[i - 1][j],
                        j == n - 1 ? INT_MAX : dp[i - 1][j + 1]});
    return *min_element(dp.back().begin(), dp.back().end());
  }
};