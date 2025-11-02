#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> cnt(10, 0);
        for (int d : digits) cnt[d]++;

        int ans = 0;
        // Fix the ones place as an even digit
        for (int c = 0; c <= 9; ++c) {
            if (c % 2 != 0 || cnt[c] == 0) continue; // must be even and available
            cnt[c]--;
            // Choose hundreds digit (no leading zero)
            for (int h = 1; h <= 9; ++h) {
                if (cnt[h] == 0) continue;
                cnt[h]--;
                // Choose tens digit (any digit available)
                for (int t = 0; t <= 9; ++t) {
                    if (cnt[t] > 0) ans++;
                }
                cnt[h]++;
            }
            cnt[c]++;
        }
        return ans;
    }
};
