#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxBottlesDrunk(int n, int m) {
        int ans = 0, empty = 0;
        ans += n;
        empty += n;
        // drink when full available
        while(true) {
            if (m > empty) break;
            ans += 1;
            empty -= m;
            empty++;
            m++;
        }
        return ans;
    }
};
