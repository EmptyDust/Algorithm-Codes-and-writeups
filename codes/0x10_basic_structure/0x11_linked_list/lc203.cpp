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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *h = new ListNode(0,head);
        ListNode *temp = h;
        while(temp&&temp->next){
            while(temp->next&&temp->next->val==val){
                ListNode* d = temp->next;
                temp->next=temp->next->next;
                delete d;
            }
            temp=temp->next;
        }
        return h->next;
    }
};