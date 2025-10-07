#include <bits/stdc++.h>
using namespace std;

class TreeAncestor {
public:
    vector<vector<int>> parent;
    int LOG;

    int bitcount(int n) {
        int cnt = 0;
        while ((1 << cnt) <= n) cnt++;
        return cnt;
    }

    TreeAncestor(int n, vector<int>& par) {
        LOG = bitcount(n);
        parent.assign(n, vector<int>(LOG, -1));

        for (int i = 0; i < n; i++) {
            parent[i][0] = par[i];
        }

        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i < n; i++) {
                int p = parent[i][j - 1];
                if (p != -1)
                    parent[i][j] = parent[p][j - 1];
            }
        }
    }

    int getKthAncestor(int node, int k) {
        for (int j = 0; j < LOG; j++) {
            if (k & (1 << j)) {
                node = parent[node][j];
                if (node == -1) return -1;
            }
        }
        return node;
    }
};
