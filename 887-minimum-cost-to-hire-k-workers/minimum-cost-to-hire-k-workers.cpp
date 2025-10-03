#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<pair<double, int>> workers;
        // most important wage / quality ratio
        // heighest ratio dominates the whole group
        for (int i = 0; i < n; i++)
            workers.push_back({(double) wage[i] / quality[i], i});
        sort(workers.begin(), workers.end());
        priority_queue<int> maxHeap;
        int qualitySum = 0;
        double minCost = DBL_MAX;
        for (int i = 0; i < n; i++) {
            int idx = workers[i].second;
            double ratio = workers[i].first;
            maxHeap.push(quality[idx]);
            qualitySum += quality[idx];
            if (maxHeap.size() > k) {
                qualitySum -= maxHeap.top();
                maxHeap.pop();
            }
            if (maxHeap.size() == k) {
                minCost = min(minCost, ratio * qualitySum);
            }
        }
        return minCost;
    }
};
