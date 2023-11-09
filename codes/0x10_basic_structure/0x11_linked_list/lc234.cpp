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
    ListNode* frontPointer;
public:
    bool recursivelyCheck(ListNode* currentNode) {
        if (currentNode != nullptr) {
            if (!recursivelyCheck(currentNode->next)) {
                return false;
            }
            if (currentNode->val != frontPointer->val) {
                return false;
            }
            frontPointer = frontPointer->next;
        }
        return true;
    }

    bool isPalindrome(ListNode* head) {
        frontPointer = head;
        return recursivelyCheck(head);
    }
};