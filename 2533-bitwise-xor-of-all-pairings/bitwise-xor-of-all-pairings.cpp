class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int x1 = 0, x2 = 0;
        for (int a : nums1) x1 ^= a;
        for (int b : nums2) x2 ^= b;

        int ans = 0;
        if (nums2.size() % 2 == 1) ans ^= x1;
        if (nums1.size() % 2 == 1) ans ^= x2;
        return ans;
    }
};
