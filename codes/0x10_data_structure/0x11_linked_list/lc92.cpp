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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head||!head->next) return head;

        ListNode* temp1= new ListNode(-1,head),*ans=temp1;
        ListNode* temp2=head,*temp3=head->next;
        ListNode* h;
        int pos=1;
        while(pos!=left){
            temp1=temp2;
            temp2=temp3;
            temp3=temp3->next;
            ++pos;
        }
        h=temp1;
        while(pos!=right){
            temp2->next=temp1;
            temp1=temp2;
            temp2=temp3;
            temp3=temp3->next;
            ++pos;
        }
        temp2->next=temp1;
        h->next->next=temp3;
        h->next=temp2;
        return ans->next;
    }
};