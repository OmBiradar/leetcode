#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<string>> suggestedProducts(vector<string> &products,
                                           string searchWord) {
    sort(products.begin(), products.end());
    deque<string> q;
    for (auto p : products)
      q.push_back(p);
    auto lexcompare_give_back = [&](string pref) {
      vector<string> s;
      while (!q.empty() && s.size() < 3) {
        if (q.front().substr(0, pref.size()) < pref) {
          q.pop_front();
        } else if (q.front().substr(0, pref.size()) == pref) {
          s.push_back(q.front());
          q.pop_front();
        } else
          break;
      }
      for (int i = s.size() - 1; i >= 0; i--)
        q.push_front(s[i]);
      return s;
      //    vector<string> s(3, "");
      //     if (q.empty()) {
      //       return s;
      //     }
      //     while (q.front().substr(0, pref.size()) < pref) {
      //       q.pop_front();
      //     }
      //     if (q.empty())
      //       return s;
      //     if (q.front().substr(0, pref.size()) > pref) {
      //       return s;
      //     }
      //     // first
      //     if (q.empty())
      //       return s;
      //     s[0] = q.front();
      //     q.pop_front();
      //     if (q.empty() || q.front().substr(0, pref.size()) > pref) {
      //       q.push_front(s[0]);
      //       return s;
      //     }
      //     s[1] = q.front();
      //     q.pop_front();
      //     if (q.empty() || q.front().substr(0, pref.size()) > pref) {
      //       q.push_front(s[1]);
      //       q.push_front(s[0]);
      //       return s;
      //     }
      //     s[2] = q.front();
      //     q.push_front(s[1]);
      //     q.push_front(s[0]);
      //     return s;
    };
    vector<vector<string>> answer(searchWord.size(), vector<string>(3, ""));
    for (int i = 0; i < searchWord.size(); i++) {
      // pop if pref less than searchWrod prefix
      answer[i] = lexcompare_give_back(searchWord.substr(0, i + 1));
    }
    return answer;
  }
};