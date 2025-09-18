#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target) {
    // dp n^3
    long long cnt = 0;
    int n = matrix.size(), m = matrix[0].size();
    for (int i = 0; i < n; i++) {
      // starting 2 points on ith row
      vector<int> S_col(m, 0);
      for (int r = i; r < n; r++) {
        for (int j = 0; j < m; j++)
          S_col[j] += matrix[r][j];
        unordered_map<int, int> seen;
        seen[0] = 1; // 0 seen 1 times
        long long cur = 0;
        for (int j = 0; j < m; j++) {
          cur += S_col[j];
          if (seen.count(cur - target)) {
            cnt += seen[cur - target];
          }
          seen[cur]++;
        }
      }
    }
    return cnt;
  }
};