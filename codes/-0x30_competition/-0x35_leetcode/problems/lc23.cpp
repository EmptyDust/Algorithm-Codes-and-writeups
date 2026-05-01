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
private:
    struct compare {
        bool operator() (ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ans = new ListNode(),*temp=ans;
        priority_queue<ListNode*, vector<ListNode*>,compare> pq;int i=0;
        for(auto a:lists)if(a)pq.push(a);
        while(!pq.empty()){
            ListNode* a=pq.top();
            pq.pop();
            temp->next=a;
            temp=a;
            if(a->next)pq.push(a->next);
        }
        return ans->next;
    }
};