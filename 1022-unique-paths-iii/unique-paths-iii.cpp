#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int cnt = 0;
  int st_x, st_y, n, m;
  vector<vector<int>> GRID;
  int uniquePathsIII(vector<vector<int>> &grid) {
    GRID = grid;
    n = grid.size(), m = grid[0].size();
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 0)
          cnt++;
        else if (grid[i][j] == 1)
          st_x = i, st_y = j, cnt++;
      }
    return COUNT(st_x, st_y, 0);
  }
  int COUNT(int x, int y, int cur) {
    if (x < 0 || y < 0 || x >= n || y >= m || GRID[x][y] == -1)
      return 0;
    if (GRID[x][y] == 2)
      return cnt == cur ? 1 : 0;
    int val = GRID[x][y];
    GRID[x][y] = -1;                     // travelled
    int ans = COUNT(x, y + 1, cur + 1) + // explore 4 dirs
              COUNT(x, y - 1, cur + 1) + COUNT(x + 1, y, cur + 1) +
              COUNT(x - 1, y, cur + 1);
    GRID[x][y] = val; // not considered now
    if (x == st_x && y == st_y)
      GRID[x][y] = 1;
    return ans;
  }
};