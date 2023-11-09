#include <bits/stdc++.h>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      auto* l = new ListNode();
      ListNode* tempNode = l;
      int k = 0;
      
      int temp = l1->val+l2->val;
      if(temp>=10){
        k = temp/10;
        temp%=10;
      }
      l->val=temp;
      while(l1->next!=nullptr||l2->next!=nullptr){
        if(l1->next==nullptr)
          l1->next=new ListNode();
        if(l2->next==nullptr)
          l2->next=new ListNode();
        temp = l1->next->val+l2->next->val+k;
        k=0;
        if(temp>=10){
          k=temp/10;
          temp%=10;
        }
        tempNode->next = new ListNode(temp);
        tempNode = tempNode->next;
        l1->next=l1->next->next;
        l2->next=l2->next->next;
      }
      if(k!=0) tempNode->next=new ListNode(k);
      return l;
    }
};