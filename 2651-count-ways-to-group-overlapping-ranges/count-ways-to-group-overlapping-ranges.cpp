class Solution {
public:
    int countWays(vector<vector<int>>& ranges) {
        sort(ranges.begin(), ranges.end());
        
        int count = 0;
        long long mod = 1e9 + 7;
        int l = ranges[0][0], r = ranges[0][1];
        
        for (int i = 1; i < ranges.size(); i++) {
            if (ranges[i][0] <= r) {
                r = max(r, ranges[i][1]);
            } else {
                count++;
                l = ranges[i][0];
                r = ranges[i][1];
            }
        }
        count++;  // last merged group

        long long ans = 1;
        for (int i = 0; i < count; i++)
            ans = (ans * 2) % mod;
        
        return ans;
    }
};
