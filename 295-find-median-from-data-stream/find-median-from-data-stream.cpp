#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
public:
  priority_queue<int, vector<int>> max_heap;
  priority_queue<int, vector<int>, greater<int>> min_heap;
  MedianFinder() {}
  void addNum(int num) {
    max_heap.push(num);
    while (!max_heap.empty() && !min_heap.empty() &&
           max_heap.top() > min_heap.top()) {
      min_heap.push(max_heap.top());
      max_heap.pop();
    }
    if (max_heap.size() > min_heap.size() + 1) {
      min_heap.push(max_heap.top());
      max_heap.pop();
    } else if (min_heap.size() > max_heap.size()) {
      max_heap.push(min_heap.top());
      min_heap.pop();
    }
  }
  double findMedian() {
    if (max_heap.size() > min_heap.size()) {
      return max_heap.top();
    } else if (!max_heap.empty()) {
      return (max_heap.top() + min_heap.top()) / 2.0;
    }
    return 0.0;
  }
};
