#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  ListNode *mergeTwoLists(ListNode *L1, ListNode *L2) {
    ListNode *dummy = new ListNode();
    ListNode *tail = dummy;
    while (L1 != nullptr && L2 != nullptr) {
      if (L1->val < L2->val) {
        tail->next = L1;
        L1 = L1->next;
      } else {
        tail->next = L2;
        L2 = L2->next;
      }
      tail = tail->next;
    }
    if (L1 != nullptr)
      tail->next = L1;
    else
      tail->next = L2;
    ListNode *head = dummy->next;
    delete dummy;
    return head;
  }
};