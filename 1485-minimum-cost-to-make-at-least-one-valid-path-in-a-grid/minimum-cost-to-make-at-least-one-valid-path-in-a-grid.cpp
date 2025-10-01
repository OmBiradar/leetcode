#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<ll>> dist(m, vector<ll>(n, INT_MAX));
        deque<pair<int, int>> dq;
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        dist[0][0] = 0;
        dq.push_front({0, 0});
        while(!dq.empty()) {
            pair<int, int> cur = dq.front();
            dq.pop_front();
            int r = cur.first, c = cur.second;
            if (r == m - 1 && c == n - 1)
                return dist[r][c];
            for (int i = 0; i < 4; i++) {
                int nr = r + dirs[i][0], nc = c + dirs[i][1];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    int cost = grid[r][c] == i + 1 ? 0 : 1;
                    if (dist[r][c] + cost < dist[nr][nc]) {
                        dist[nr][nc] = dist[r][c] + cost;
                        if (cost == 0)
                            dq.push_front({nr, nc});
                        else
                            dq.push_back({nr, nc});
                    }
                }
            }
        }
        return -1;
    }
};
