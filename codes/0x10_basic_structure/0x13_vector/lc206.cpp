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
    ListNode* reverseList(ListNode* head) {
        if(!head||!head->next)return head;
        ListNode* temp1 = head,*temp2=head->next,*temp3=head->next->next;
        head->next=nullptr;
        while(temp2){
            temp2->next=temp1;
            temp1=temp2;
            temp2=temp3;
            if(temp3)
                temp3=temp3->next;
        }
        return temp1;
    }
};