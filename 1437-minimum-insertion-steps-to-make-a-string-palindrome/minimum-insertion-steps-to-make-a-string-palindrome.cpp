#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minInsertions(string s) {
    // find Longest Palindromic Subsequence then the remaining should be added
    // in
    string t(s.rbegin(), s.rend());
    // LCS of s and t
    vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
    for (int i = 1; i <= s.size(); i++)
      for (int j = 1; j <= t.size(); j++) {
        if (s[i - 1] == t[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
        } else {
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    return s.size() - dp[s.size()][t.size()];
  }
};