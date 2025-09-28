class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> cnt(n), ans(n);
        for (auto e : edges) adj[e[0]].push_back(e[1]), adj[e[1]].push_back(e[0]);
        // assuming root as 0 always
        // first pass
        vector<bool> vis(n, false);
        function<void(int)> dfs1 = [&](int u) {
            vis[u] = true;
            cnt[u] = 1;
            for (auto& v : adj[u]) {
                if (!vis[v]) {
                    dfs1(v);
                    cnt[u] += cnt[v];
                    ans[u] += cnt[v] + ans[v];
                }
            }
        };
        dfs1(0);
        // for (auto c : cnt) cout << c << ' ';
        // cout << endl;
        // for (auto c : ans) cout << c << ' ';

        // implementing the 2nd pass
        // child inherits from parent
        // child should have information about parent
        // dfs by passing the info about parent
        // quite simple actually
        // lack of confidence actually
        vis.clear();
        vis = vector<bool>(n, false);
        function<void(int, int)> dfs2 = [&](int child, int parent) {
            if (parent != -1) {
                ans[child] = ans[parent] + (n - cnt[child]) - cnt[child];
            }
            vis[child] = true;
            for (auto v : adj[child]) {
                if (!vis[v])
                    dfs2(v, child);
            }
        };
        dfs2(0, -1);

        /* WARNING: I/O can sometimes result in TLE, better to comment before */

        // for (auto c : cnt) cout << c << ' ';
        // cout << endl;
        // for (auto c : ans) cout << c << ' ';

        return ans;
    }
};