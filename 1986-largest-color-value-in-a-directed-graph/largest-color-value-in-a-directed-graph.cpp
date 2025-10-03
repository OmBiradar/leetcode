#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);
        for (auto e : edges) {
            graph[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }
        vector<vector<int>> dp(n, vector<int>(26, 0));
        queue<int> q;
        for (int i = 0; i < n; i++)
            if (indegree[i] == 0) {
                q.push(i);
                dp[i][colors[i] - 'a'] = 1;
            }
        int processed = 0, max_value = 0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            processed++;
            for (int c = 0; c < 26; c++)
                max_value = max(max_value, dp[node][c]);
            for (int neighbor : graph[node]) {
                for (int c = 0; c < 26; c++) {
                    int newCount = dp[node][c] + (c == colors[neighbor] - 'a' ? 1 : 0);
                    dp[neighbor][c] = max(dp[neighbor][c], newCount);
                }
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) q.push(neighbor);
            }
        }
        return processed == n ? max_value : -1;
    }
};
