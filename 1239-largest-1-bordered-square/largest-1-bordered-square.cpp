class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> right(m, vector<int>(n, 0));
        vector<vector<int>> down(m, vector<int>(n, 0));

        // Compute consecutive ones to the right and down
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j] == 1) {
                    right[i][j] = 1 + (j + 1 < n ? right[i][j + 1] : 0);
                    down[i][j] = 1 + (i + 1 < m ? down[i + 1][j] : 0);
                }
            }
        }

        int maxLen = 0;

        // Try all possible top-left corners
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Try largest possible square from current cell
                for (int k = min(m - i, n - j); k > 0; k--) {
                    if (right[i][j] >= k && down[i][j] >= k &&
                        right[i + k - 1][j] >= k && down[i][j + k - 1] >= k) {
                        maxLen = max(maxLen, k);
                        break;  // no need to check smaller squares here
                    }
                }
            }
        }

        return maxLen * maxLen;
    }
};
