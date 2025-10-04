#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        /*
         * At each step,
         * either:
         *  keep the current value of a[i] (if possible)
         *  replace with the smallest possible value from arr2
         */
        sort(arr2.begin(), arr2.end());
        arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());
        map<int, int> dp;
        dp[0] = -1;
        for (int i = 0; i < arr1.size(); i++) {
            map<int, int> new_dp;
            for (auto [operations, previous_value] : dp) {
                if (arr1[i] > previous_value) {
                    if (new_dp.find(operations) == new_dp.end() || arr1[i] < new_dp[operations]) {
                        new_dp[operations] = arr1[i];
                    }
                }
                auto it = upper_bound(arr2.begin(), arr2.end(), previous_value);
                if (it != arr2.end()) {
                    int new_value = *it;
                    int cur_operations = operations + 1;
                    if (new_dp.find(cur_operations) == new_dp.end() || new_value < new_dp[cur_operations]) {
                        new_dp[cur_operations] = new_value;
                    }
                }
            }
            if (new_dp.empty()) {
                return -1;
            }
            dp = new_dp;
        }
        return dp.begin()->first;
    }
};
