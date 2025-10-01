#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        ll n = nums.size();
        ll ans = 0;
        vector<map<ll, ll>> dp(n + 1);
        for (ll i = 1; i < n; i++) {
            for (ll j = 0; j < i; j++) {
                ll diff = (ll)nums[i] - nums[j];
                ans += dp[j][diff];
                dp[i][diff] += dp[j][diff] + 1; 
            }
        }
        return ans;
    }
};