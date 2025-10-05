#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        if (n == 0) return {};
        int m = heights[0].size();
        vector<vector<bool>> pacific(n, vector<bool>(m, false)), atlantic(n, vector<bool>(m, false));
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        function<void(int, int, vector<vector<bool>>&)> dfs = [&](int i, int j, vector<vector<bool>>& vis) {
            vis[i][j] = true;
            for (auto [dx, dy] : dirs) {
                int ni = i + dx, nj = j + dy;
                if (ni < 0 || nj < 0 || ni >= n || nj >= m) continue;
                if (vis[ni][nj]) continue;
                if (heights[ni][nj] < heights[i][j]) continue;
                dfs(ni, nj, vis);
            }
        };
        // Pacific borders
        for (int j = 0; j < m; j++) dfs(0, j, pacific);
        for (int i = 0; i < n; i++) dfs(i, 0, pacific);
        // Atlantic borders
        for (int j = 0; j < m; j++) dfs(n - 1, j, atlantic);
        for (int i = 0; i < n; i++) dfs(i, m - 1, atlantic);
        vector<vector<int>> results;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pacific[i][j] && atlantic[i][j]) results.push_back({i, j});
            }
        }
        return results;
    }
};