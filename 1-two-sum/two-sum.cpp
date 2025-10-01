#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> f;
        for (int i = 0; i < nums.size(); i++) {
            if (f.count(target-nums[i])) {
                return {f[target-nums[i]], i};
            }
            f[nums[i]] = i;
        }
        return {-1, -1};
    }
};
