#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
        int maxValue = INT_MIN;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            pq.push({nums[i][0], 0, i});
            maxValue = max(maxValue, nums[i][0]);
        }
        vector<int> minRange = {pq.top()[0], maxValue};
        while(true) {
            auto [ele, eleIdx, listIdx] = pq.top();
            pq.pop();
            if (eleIdx < nums[listIdx].size() - 1) {
                int nextEle = nums[listIdx][eleIdx + 1];
                pq.push({nextEle, eleIdx + 1, listIdx});
                maxValue = max(maxValue, nextEle);
                int newMinVal = pq.top()[0];
                if (maxValue - newMinVal < minRange[1] - minRange[0] || 
                    ( maxValue - newMinVal < minRange[1] - minRange[0] && 
                      newMinVal < minRange[0])) {
                    minRange = {newMinVal, maxValue};
                }
            } else break;
        }
        return minRange;
    }
};
