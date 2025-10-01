#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        int MOD = 1e9 + 7;
        int area = 0;
        map<int, vector<tuple<int, int, int>>> breakpoints;
        for (auto r : rectangles) {
            breakpoints[r[0]].push_back({0, r[1], r[3]});
            breakpoints[r[2]].push_back({1, r[1], r[3]});
        }
        int prev_x = -1;
        multiset<pair<int, int>> intervals;
        function<int(void)> get_y_height = [&]() {
            vector<pair<int, int>> UNION_INTERVALS;
            for (auto i : intervals) {
                if (UNION_INTERVALS.empty() || UNION_INTERVALS.back().second < i.first) {
                    UNION_INTERVALS.push_back({i.first, i.second});
                } else {
                    UNION_INTERVALS.back().second = max(UNION_INTERVALS.back().second, i.second);
                }
            }
            int ans = 0;
            for (auto i : UNION_INTERVALS) {
                ans += i.second - i.first;
            }
            return ans;
        };
        for (auto [cur_x, cur_intervals] : breakpoints) {
            int x_dist = prev_x == -1 ? 0 : cur_x - prev_x;
            // use the current intervals to calculate union of y height
            int y_dist = get_y_height();
            area = (area + ((1LL * x_dist) * y_dist) % MOD) % MOD;
            for (auto cur_interval : cur_intervals) {
                if (get<0>(cur_interval) == 0) {
                    intervals.insert({get<1>(cur_interval), get<2>(cur_interval)});
                } else {
                    auto it = intervals.find({get<1>(cur_interval), get<2>(cur_interval)});
                    if (it != intervals.end()) {
                        intervals.erase(it);
                    }
                }
            }
            prev_x = cur_x;
        }
        return area;
    }
};