class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        return max(helper(s, k, 'T'), helper(s, k, 'F'));
    }

    int helper(const string& s, int k, char target) {
        int left = 0, flips = 0, res = 0;
        for (int right = 0; right < s.size(); right++) {
            if (s[right] != target) flips++;
            while (flips > k) {
                if (s[left] != target) flips--;
                left++;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};
