class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        vector<bool> inc(n, false), dec(n, false);
        for (int i = 0; i < n; i++) {
            if (i == 0 || nums[i] > nums[i-1]) {
                inc[i] = true;
            } else break;
        }
        for (int i = n - 1; i >= 0; i--) {
            if (i == n - 1 || nums[i] > nums[i+1])
                dec[i] = true;
            else break;
        }
        vector<long long> cum_sum(n);
        for (int i = 0; i < n; i++) {
            cum_sum[i] = nums[i];
            if (i != 0) cum_sum[i] += cum_sum[i-1];
        }
        long long mi = LLONG_MAX;
        for (int i = 0; i < n - 1; i++) {
            if (inc[i] && dec[i+1])
                mi = min(mi, abs(cum_sum[i] - (cum_sum[n-1] - cum_sum[i])));
        }
        return mi == LLONG_MAX ? -1 : mi;
    }
};