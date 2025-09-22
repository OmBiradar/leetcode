#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int longestPalindromeSubseq(string s) {
    string t(s.rbegin(), s.rend());
    int n = s.size();
    // simple trick -> first reverse
    // then find the longest common subsequence
    // that has to be palindromic so return that
    // return LIS
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) {
        if (s[i - 1] == t[j - 1])
          dp[i][j] = 1 + dp[i - 1][j - 1];
        else
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    return dp[n][n];
  }
};
