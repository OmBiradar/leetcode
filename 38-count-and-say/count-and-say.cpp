#include <bits/stdc++.h>
using namespace std;

class Solution {
  string rle(int n) {
    if (n == 1)
      return "1";
    string r = rle(n - 1);
    string res = "";
    int N = r.size();
    for (int i = 0; i < N; i++) {
      int j = i;
      while (r[j] == r[i] && j < N) {
        j++;
      }
      res += to_string(j - i) + r[i];
      i = j - 1;
    }
    return res;
  }

public:
  string countAndSay(int n) { return rle(n); }
};