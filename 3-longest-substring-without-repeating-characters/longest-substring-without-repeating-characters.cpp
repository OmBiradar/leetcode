#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // sliding window
        int mx = 0;
        map<char, int> f;
        int l = 0; // track the opening
        for (int r = 0; r < s.size(); r++) {
            f[s[r]]++;
            while(f[s[r]] > 1) {
                f[s[l]]--;
                l++;
            }
            mx = max(mx, r - l + 1);
        }
        return mx;
    }
};
