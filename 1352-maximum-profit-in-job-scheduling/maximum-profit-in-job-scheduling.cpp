class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<array<int, 3>> jobs(n);
        
        for (int i = 0; i < n; i++) {
            jobs[i] = {endTime[i], startTime[i], profit[i]};
        }
        
        sort(jobs.begin(), jobs.end());
        
        vector<int> dp(n);
        dp[0] = jobs[0][2];
        
        for (int i = 1; i < n; i++) {
            int take = jobs[i][2];
            int left = 0, right = i - 1, latest = -1;
            
            while (left <= right) {
                int mid = (left + right) / 2;
                if (jobs[mid][0] <= jobs[i][1]) {
                    latest = mid;
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            
            if (latest != -1) take += dp[latest];
            dp[i] = max(dp[i-1], take);
        }
        
        return dp[n-1];
    }
};
