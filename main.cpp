// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos

#include <iostream>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    // Ex: Input: 1->2->4, 2->3
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1 && !l2)
          return nullptr;
        else if (l1 && !l2)
          return l1;
        else if (!l1 && l2)
          return l2;
        
        ListNode *result = nullptr;
        ListNode *tail = nullptr;
        ListNode* c1 = l1;
        ListNode* c2 = l2;
        if (c1->val < c2->val) {
          result = c1;
          tail = c1;
          c1 = c1->next;
        } else {
          result = c2;
          tail = c2;
          c2 = c2->next;
        }
        // tail points to last element
        // c1 points to next element in List1
        // c2 same
        while (c1 && c2) {
          if (c1->val < c2->val) {
            tail->next = c1;
            tail = c1;
            c1 = c1->next;
          } else {
            tail->next = c2;
            tail = c2;
            c2 = c2->next;
          }
        }
        if (c1) {
          tail->next = c1;
        }
        if (c2) {
          tail->next = c2;
        }
        return result;
    }
};

void printListNode(ListNode* x) {
  cout << "[";
  ListNode *curr = x;
  while (curr) {
    cout << curr->val << "-->";
    curr = curr->next;
  }
  cout << "]" << endl;
}

void test0() {
  Solution S;

  ListNode *l1 = nullptr;
  ListNode *l2 = nullptr;

  // both empty
  ListNode *returned = S.mergeTwoLists(l1, l2);
  cout << "[]? ";
  printListNode(returned);
}

void test1() {
  Solution S;

  ListNode *l1 = nullptr;
  ListNode *l2 = nullptr;

  l1 = new ListNode(1);
  l1->next = new ListNode(2);
  l1->next->next = new ListNode(4);

// second one empty
  ListNode *returned = S.mergeTwoLists(l1, l2);
  cout << "[1-->2-->4-->]? ";
  printListNode(returned);

  // first one empty
  returned = S.mergeTwoLists(l2, l1);
  cout << "[1-->2-->4-->]? ";
  printListNode(returned);

}

void test2() {
  Solution S;

  ListNode *l1 = nullptr;
  ListNode *l2 = nullptr;

  l1 = new ListNode(1);
  l1->next = new ListNode(2);
  l1->next->next = new ListNode(4);

  l2 = new ListNode(1);
  l2->next = new ListNode(3);
  l2->next->next = new ListNode(4);
  l2->next->next->next = new ListNode(6);

  // longer l2
  ListNode *returned = S.mergeTwoLists(l1, l2);
  cout << "[1->1->2->3->4->4->6]? ";
  printListNode(returned);
}

void test3() {
  Solution S;

  ListNode *l1 = nullptr;
  ListNode *l2 = nullptr;

  l1 = new ListNode(1);
  l1->next = new ListNode(2);
  l1->next->next = new ListNode(4);

  l2 = new ListNode(1);
  l2->next = new ListNode(3);
  l2->next->next = new ListNode(4);
  l2->next->next->next = new ListNode(6);

  // longer l2 as first param
  ListNode *returned = S.mergeTwoLists(l2, l1);
  cout << "[1->1->2->3->4->4->6]? ";
  printListNode(returned);
}


int main() {
  
  test0();
  test1();
  test2();
  test3();

  cout << "All done!" << endl;
  return 0;
}
