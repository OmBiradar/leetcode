class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long k = (long long)k1 + k2;
        int n = nums1.size();
        int maxDiff = 0;
        vector<int> cnt(100001, 0);

        // build frequency map of absolute differences
        for (int i = 0; i < n; i++) {
            int d = abs(nums1[i] - nums2[i]);
            cnt[d]++;
            maxDiff = max(maxDiff, d);
        }

        // flatten differences greedily from largest to smallest
        for (int d = maxDiff; d > 0 && k > 0; d--) {
            if (cnt[d] == 0) continue;
            long long take = min(k, (long long)cnt[d]);
            long long move = take; // at least one layer reduced
            cnt[d] -= take;
            cnt[d - 1] += take;
            k -= take;

            // if more k remains but still count left at level d
            // we can move entire layers at once
            if (cnt[d] > 0 && k >= cnt[d]) {
                k -= cnt[d];
                cnt[d - 1] += cnt[d];
                cnt[d] = 0;
            } else if (cnt[d] > 0 && k < cnt[d]) {
                cnt[d] -= k;
                cnt[d - 1] += k;
                k = 0;
            }
        }

        long long ans = 0;
        for (long long i = 0; i <= maxDiff; i++) {
            ans += (long long)i * i * cnt[i];
        }
        return ans;
    }
};
