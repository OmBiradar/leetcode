#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.push_back(1);
        int n = nums.size();
        for (int i = n - 2; i >= 0; i--)
            swap(nums[i + 1], nums[i]);
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i < n - len + 1; i++) {
                int j = i + len - 1;
                for (int k = i + 1; k < j; k++) {
                    int cur = dp[i][k] + dp[k][j] + nums[i] * nums[k] * nums[j];
                    dp[i][j] = max(dp[i][j], cur);
                }
            }
        }
        return dp[0][n-1];
    }
};
