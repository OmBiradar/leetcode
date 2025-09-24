#include <bits/stdc++.h>
using namespace std;

// struct ListNode {
//   int val;
//   ListNode *next;
//   ListNode() : val(0), next(nullptr) {}
//   ListNode(int x) : val(x), next(nullptr) {}
//   ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution {
public:
  ListNode *partition(ListNode *head, int x) {
    ListNode *one, *two, *cur1, *cur2, *curx;
    one = new ListNode();
    two = new ListNode();
    cur1 = one, cur2 = two;
    curx = head;
    while (curx != nullptr) {
      if (curx->val < x) {
        cur1->next = curx;
        cur1 = cur1->next;
      } else {
        cur2->next = curx;
        cur2 = cur2->next;
      }
      curx = curx->next;
    }
    cur1->next = two->next;
    cur2->next = nullptr;
    return one->next;
  }
};
