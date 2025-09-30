class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        vector<int> res;
        long long pw = 1;
        while(n) {
            if (n % 10 != 0) {
                res.push_back(n % 10 * pw);
            }
            n /= 10;
            pw *= 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};