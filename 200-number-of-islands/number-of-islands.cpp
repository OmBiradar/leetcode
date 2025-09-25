#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int numIslands(vector<vector<char>> &grid) {
    int n = grid.size(), m = grid[0].size();
    int cnt = 0;
    function<void(int x, int y)> traverse = [&](int x, int y) {
      if (x < 0 || y < 0 || x >= n || y >= m)
        return;
      if (grid[x][y] == '1')
        grid[x][y] = '0';
      else
        return;
      vector<int> dx = {0, 0, 1, -1}, dy = {1, -1, 0, 0};
      for (int i = 0; i < 4; i++) {
        traverse(x + dx[i], y + dy[i]);
      }
    };
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (grid[i][j] == '1')
          cnt += 1, traverse(i, j);
    return cnt;
  }
};