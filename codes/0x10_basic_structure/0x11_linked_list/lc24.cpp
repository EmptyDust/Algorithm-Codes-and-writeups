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
    ListNode* swapPairs(ListNode* head) {
        if(!head||!head->next)return head;
        ListNode *h = new ListNode(0,head);
        ListNode *temp=h;
        while(temp->next&&temp->next->next){
            ListNode *temp1=temp->next;
            temp->next=temp1->next;
            temp=temp->next;
            temp1->next=temp->next;
            temp->next=temp1;
            temp=temp1;
        }
        return h->next;
    }
};