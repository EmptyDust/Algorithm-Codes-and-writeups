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
    ListNode* oddEvenList(ListNode* head) {
        if(!head||!head->next)return head;
        ListNode *temp=head;
        ListNode *even = head->next,*temp2=even;
        head->next=head->next->next;
        while(temp->next){
            temp=temp->next;
            temp2->next=temp->next;
            temp2=temp2->next;
            if(temp->next)
                temp->next=temp->next->next;
        }
        temp->next=even;
        return head;
    }
};