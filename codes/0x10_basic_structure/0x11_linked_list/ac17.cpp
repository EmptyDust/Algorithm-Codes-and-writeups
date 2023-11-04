#include <vector>
using namespace std;
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    vector<int> k;
    vector<int> printListReversingly(ListNode* head) {
        if(head){
            printListReversingly(head->next);
            k.push_back(head->val);
        }
        return k;
    }
};