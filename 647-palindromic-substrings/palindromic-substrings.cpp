#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int countSubstrings(string s) {
    // normally expand and count palindromes
    // but here we can do something with dp
    // dp[i][j] = true if it's a palindrome
    int n = s.size();
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    int cnt = 0;
    for (int i = 0; i < n; i++)
      dp[i][i] = true, cnt++;
    for (int len = 2; len <= n; len++)
      for (int i = 0; i <= n - len; i++) {
        int j = i + len - 1;
        if (s[i] == s[j] && (len == 2 || dp[i + 1][j - 1])) {
          dp[i][j] = true;
          cnt++;
        }
      }
    return cnt;
  }
};