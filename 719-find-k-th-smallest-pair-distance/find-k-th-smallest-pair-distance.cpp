#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        function<int(int)> count = [&](int dist) {
            int count = 0;
            int left = 0;
            for (int right = 1; right < n; right++) {
                while(nums[right] - nums[left] > dist)
                    left++;
                count += right - left;
            }
            return count;
        };
        sort(nums.begin(), nums.end());
        int left = 0, right = nums[n-1] - nums[0];
        // largest range possible
        while (left < right) {
            int mid = std::midpoint(left, right);
            if (count(mid) >= k) {
                right = mid;
            } else left = mid + 1;
        }
        return left;
    }
};
