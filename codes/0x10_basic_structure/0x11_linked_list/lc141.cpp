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
    bool hasCycle(ListNode *head) {
        if(!head||!head->next)return false;
        ListNode* a1=head,*a2=head;
        while(a1){
            a1=a1->next;
            if(a1){
                a1=a1->next;
                a2=a2->next;
            }
            if(a1==a2)return true;
        }
        return false;
    }
};