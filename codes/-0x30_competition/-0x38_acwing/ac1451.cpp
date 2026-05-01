//Definition for singly-linked list.
#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
void pt(ListNode* head);

class Solution {
public:
    ListNode* quickSortList(ListNode* head) {
        if(!head||!head->next) return head;
        ListNode* temp = new ListNode(0);
        ListNode* i = head;
        while(i->next){
            if(i->next->val<head->val){
                ListNode* t = temp->next;
                temp->next=i->next;
                i->next=i->next->next;
                temp->next->next=t;
            }
            else
                i=i->next;
        }
        temp->next=quickSortList(temp->next);
        head->next=quickSortList(head->next);
        i=temp;
        while(i->next)i=i->next;
        i->next=head;
        head=temp->next;
        return head;
    }
};

void pt(ListNode* head){
    ListNode* temp = head;
    while(temp){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    Solution s;
    int temp;
    ListNode* head=new ListNode(0);
    ListNode* t=head;
    while(cin>>temp){
        t->next=new ListNode(temp);
        t=t->next;
    }
    ListNode* ans = s.quickSortList(head->next);
    pt(ans);
    return 0;
}