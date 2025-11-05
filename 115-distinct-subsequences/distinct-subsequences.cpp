class Solution {
public:
    int numDistinct(string s, string t) {
        vector<double> dp(t.size() + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < s.size(); i++) {
            for (int j = t.size() - 1; j >= 0; j--) {
                if (s[i] == t[j])
                    dp[j + 1] += dp[j];
            }
        }
        return (int)dp[t.size()];
    }
};
