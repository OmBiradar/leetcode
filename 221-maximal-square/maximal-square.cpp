#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maximalSquare(vector<vector<char>> &matrix) {
    int m = matrix.size(), n = matrix[0].size();
    // maitain counts of 1's in rectangle form
    // using dp
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    int mx_size = 0;
    for (int i = 1; i <= m; i++)
      for (int j = 1; j <= n; j++)
        if (matrix[i - 1][j - 1] == '1') {
          dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
          mx_size = max(mx_size, dp[i][j]);
        }
    return mx_size * mx_size;
  }
};