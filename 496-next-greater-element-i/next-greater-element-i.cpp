#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> nextGreaterElement(vector<int> &n1, vector<int> &n2) {
    vector<int> greater(n2.size(), -1);
    for (int i = 0; i < n2.size() - 1; i++) {
      for (int j = i + 1; j < n2.size(); j++) {
        if (n2[j] > n2[i]) {
          greater[i] = n2[j];
          break;
        }
      }
    }
    map<int, int> m;
    for (int i = 0; i < n2.size(); i++)
      m[n2[i]] = i;
    vector<int> ans;
    for (auto x : n1) {
      ans.push_back(greater[m[x]]);
    }
    return ans;
  }
};
