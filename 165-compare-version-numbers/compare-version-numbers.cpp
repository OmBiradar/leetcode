#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int compareVersion(string v1, string v2) {
    vector<int> v_1, v_2;
    for (int i = 0, prev = 0; i <= v1.size(); i++) {
      if (v1[i] == '.' || i == v1.size()) {
        v_1.push_back(stoi(v1.substr(prev, i - prev + 1)));
        prev = i + 1;
      }
    }
    for (int i = 0, prev = 0; i <= v2.size(); i++) {
      if (v2[i] == '.' || i == v2.size()) {
        v_2.push_back(stoi(v2.substr(prev, i - prev + 1)));
        prev = i + 1;
      }
    }
    while (v_1.size() > v_2.size())
      v_2.push_back(0);
    while (v_2.size() > v_1.size())
      v_1.push_back(0);
    for (int i = 0; i < v_1.size(); i++)
      if (v_1[i] > v_2[i])
        return 1;
      else if (v_1[i] < v_2[i])
        return -1;
    return 0;
  }
};
