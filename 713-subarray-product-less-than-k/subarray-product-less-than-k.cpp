#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k) {
        int cur = 1;
        int n = nums.size();
        int l = 0;
        int cnt = 0;
        for (int r = 0; r < n; r++) {
            cur *= nums[r];
            while(cur >= k && l <= r) {
                cur /= nums[l];
                l++;
            }
            cnt += r - l + 1;
        }
        return cnt;
    }
};
