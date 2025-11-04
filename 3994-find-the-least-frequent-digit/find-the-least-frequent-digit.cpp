class Solution {
public:
    int getLeastFrequentDigit(int n) {
        map<int, int> freq;
        while(n) {
            freq[n%10]++;
            n /= 10;
        }
        int res = INT_MAX, cnt = INT_MAX;
        for (auto [k, e] : freq) {
            if (e < cnt) {
                res = k, cnt = e;
            } else if (e == cnt && k < res) {
                res = k;
            }
        }
        return res;
    }
};