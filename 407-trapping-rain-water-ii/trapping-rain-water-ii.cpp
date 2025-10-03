#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size(), m = heightMap[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
        for (int i = 0; i < max(n, m); i++) {
            if (i < n) {
                pq.push({heightMap[i][0], i, 0});
                pq.push({heightMap[i][m-1], i, m-1});
                vis[i][0] = true;
                vis[i][m-1] = true;
            }
            if (i < m) {
                pq.push({heightMap[0][i], 0, i});
                pq.push({heightMap[n-1][i], n-1, i});
                vis[0][i] = true;
                vis[n-1][i] = true;
            }
        }
        int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int water = 0;
        while(!pq.empty()) {
            auto [height, x, y] = pq.top();
            pq.pop();
            for (int d = 0; d < 4; d++) {
                int nx = x + dirs[d][0], ny = y + dirs[d][1];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    if (vis[nx][ny]) continue;
                    vis[nx][ny] = true;
                    int cur_height = heightMap[nx][ny];
                    int max_level = max(height, cur_height);
                    water += max_level - cur_height;
                    pq.push({max_level, nx, ny});
                }
            }
        }
        return water;
    }
};
