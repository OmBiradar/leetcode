#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string reverseWords(string s) {
    stringstream ss(s);
    string word;
    vector<string> words;
    while (ss >> word)
      words.push_back(word);
    reverse(words.begin(), words.end());
    string ans;
    for (auto w : words) {
      ans += w + " ";
    }
    ans.pop_back();
    return ans;
  }
};
