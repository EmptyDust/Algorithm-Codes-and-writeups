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
    void reorderList(ListNode* head) {
        ListNode *temp=head;
        ListNode *even=temp;
        while(temp->next){
            temp=temp->next;
            if(temp->next){
                temp=temp->next;
                even=even->next;
            }
        }
        ListNode* temp1=even,*temp2;
        even=even->next;
        temp1->next=nullptr;
        even=reverseList(even);
        temp=head;
        
        while(temp&&even){
            temp2=temp->next;
            temp->next=even;
            even=even->next;
            temp->next->next=temp2;
            temp=temp2;
        }
    }
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