#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        // forgot mod before
        int MOD = 1e9 + 7;
        // things to note:
        // dependent only on interval (l, r) distance
        int m = r - l + 1;
        // every moment is either up or down
        // chaining from previous moves
        // counting dp problem in 2D 
        vector<vector<int>> up(n, vector<int>(m, 0));
        // really short hand
        auto down = up;
        // every thing is a starting point at first
        for (int i = 0; i < m; i++)
            up[0][i] = 1, down[0][i] = 1;
        // fill using simple logic
        for (int i = 1; i < n; i++) {
            // prefix sum (using just 1 variable)
            int prefix_sum = 0;
            for (int j = 0; j < m; j++) {
                down[i][j] = prefix_sum;
                prefix_sum = (prefix_sum + up[i-1][j]) % MOD;
            }
            prefix_sum = 0;
            for (int j = m - 1; j >= 0; j--) {
                up[i][j] = prefix_sum;
                prefix_sum = (prefix_sum + down[i-1][j]) % MOD;
            }
        }
        int total = 0;
        for (int j = 0; j < m; j++)
            total = ((total + up[n-1][j]) % MOD + down[n-1][j]) % MOD;
        return total;
    }
};
