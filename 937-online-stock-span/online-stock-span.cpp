#include <bits/stdc++.h>
using namespace std;

class StockSpanner {
public:
  stack<pair<int, int>> st;
  StockSpanner() {}
  // we need to store the max, and span of contineous increasing sequence in the
  // stack easy answer
  int next(int price) {
    int span = 1;
    while (!st.empty() && st.top().first <= price) {
      span += st.top().second;
      st.pop();
    }
    st.push({price, span});
    return span;
  }
};
