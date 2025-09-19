#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int cherryPickup(vector<vector<int>> &grid) {
    // starts at left and right top cornor
    // simple : we want max of next moves
    // 3 moves per robot
    // 9 possible combinations for 2 robots
    int n = grid.size(), m = grid[0].size();
    // memo for faster lower max calculations and avoid repeated lower max
    // calculations
    int memo[70][70][70];
    memset(memo, -1, sizeof(memo));
    function<int(int, int, int)> solve = [&](int row, int c1, int c2) {
      if (c1 < 0 || c2 < 0 || c1 >= m || c2 >= m || row >= n)
        return INT_MIN;
      if (memo[row][c1][c2] != -1)
        return memo[row][c1][c2];
      int cur = c1 == c2 ? grid[row][c1] : grid[row][c1] + grid[row][c2];
      if (row + 1 == n)
        return cur;
      int mx = INT_MIN;
      for (int C1 = c1 - 1; C1 <= c1 + 1; C1++)
        for (int C2 = c2 - 1; C2 <= c2 + 1; C2++) {
          mx = max(mx, solve(row + 1, C1, C2));
        }
      return memo[row][c1][c2] = cur + mx;
    };
    return solve(0, 0, m - 1);
  }
};