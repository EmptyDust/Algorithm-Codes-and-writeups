#include <vector>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)return root;
        root->next=NULL;
        vector<Node*> q;
        if(root->left)
            q.push_back(root->left);
        if(root->right)
            q.push_back(root->right);
        while(q.size()>0){
            vector<Node*> temp;
            for(int i=0;i<q.size()-1;++i){
                q[i]->next=q[i+1];
                if(q[i]->left)
                    temp.push_back(q[i]->left);
                if(q[i]->right)
                    temp.push_back(q[i]->right);
            }
            q[q.size()-1]->next=NULL;
            if(q[q.size()-1]->left)
                temp.push_back(q[q.size()-1]->left);
            if(q[q.size()-1]->right)
                temp.push_back(q[q.size()-1]->right);
            q=temp;
        }
        return root;
    }
};