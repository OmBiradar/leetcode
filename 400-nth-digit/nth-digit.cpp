#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findNthDigit(long long n) {
        long long len = 1;        // number of digits in current range
        long long count = 9;      // count of numbers in current range
        long long start = 1;      // first number in current range
        
        // Step 1: find the range
        while (n > len * count) {
            n -= len * count;
            len++;
            count *= 10;
            start *= 10;
        }

        // Step 2: find the actual number
        start += (n - 1) / len;

        // Step 3: find the digit index in that number
        string s = to_string(start);
        return s[(n - 1) % len] - '0';
    }
};
