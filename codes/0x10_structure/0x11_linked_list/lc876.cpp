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
    ListNode* middleNode(ListNode* head) {
        if(!head||!head->next)return head;
        ListNode* ln1=head;
        while(ln1->next){
            head=head->next;
            ln1=ln1->next;
            if(ln1->next)ln1=ln1->next;
        }
        return head;
    }
};