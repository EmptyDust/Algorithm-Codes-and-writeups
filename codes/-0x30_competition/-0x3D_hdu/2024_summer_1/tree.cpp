#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

struct TreeNode {
    int key;
    TreeNode* left;
    TreeNode* right;
    i64 sum = 0;
    i64 square_sum = 0;
    int size;
    int count;

    i64 get_smaller_sum() {
        if (!left)
            return sum;
        else return sum + left->sum;
    }

    i64 get_bigger_sum() {
        if (!right)
            return 0;
        else return sum + right->sum;
    }

    i64 get_bigger_square_sum() {
        if (!right)
            return 0;
        else return sum + right->square_sum;
    }

    TreeNode(int value)
        : key(value), size(1), count(1), left(nullptr), right(nullptr) {
    }
};

void inorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    inorderTraversal(root->left);
    std::cout << root->key << " ";
    inorderTraversal(root->right);
}

bool search(TreeNode* root, int target) {
    if (root == nullptr) {
        return false;
    }
    if (root->key == target) {
        return true;
    }
    else if (target < root->key) {
        return search(root->left, target);
    }
    else {
        return search(root->right, target);
    }
}

TreeNode* insert(TreeNode* root, int value) {
    if (root == nullptr) {
        return new TreeNode(value);
    }
    if (value < root->key) {
        root->left = insert(root->left, value);
    }
    else if (value > root->key) {
        root->right = insert(root->right, value);
    }
    else {
        root->count++;  // 节点值相等，增加重复数量
    }
    root->size = root->count + (root->left ? root->left->size : 0) +
        (root->right ? root->right->size : 0);  // 更新节点的子树大小
    return root;
}

int queryRank(TreeNode* root, int v) {
    if (root == nullptr) return 0;
    if (root->key == v) return (root->left ? root->left->size : 0) + 1;
    if (root->key > v) return queryRank(root->left, v);
    return queryRank(root->right, v) + (root->left ? root->left->size : 0) +
        root->count;
}

int querykth(TreeNode* root, int k) {
    if (root == nullptr) return -1;  // 或者根据需求返回其他合适的值
    if (root->left) {
        if (root->left->size >= k) return querykth(root->left, k);
        if (root->left->size + root->count >= k) return root->key;
    }
    else {
        if (k == 1) return root->key;
    }
    return querykth(root->right,
        k - (root->left ? root->left->size : 0) - root->count);
}

// TreeNode* rotateLeft(TreeNode* root) {
//     TreeNode* newRoot = root->right;
//     root->right = newRoot->left;
//     newRoot->left = root;
//     // 更新相关节点的信息
//     updateHeight(root);
//     updateHeight(newRoot);
//     return newRoot;  // 返回新的根节点
// }

// TreeNode* rotateRight(TreeNode* root) {
//     TreeNode* newRoot = root->left;
//     root->left = newRoot->right;
//     newRoot->right = root;
//     updateHeight(root);
//     updateHeight(newRoot);
//     return newRoot;
// }

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n;std::cin >> n;
    std::vector<int> adj[n];
    for (int i = 1;i < n;++i) {
        int u, v;std::cin >> u >> v;u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    std::vector<int> a(n);
    for (int i = 0;i < n;++i)std::cin >> a[i];
    std::function<void(int, int)> dfs = [&](int x, int p)->void {

        };
    return 0;
}

// au^2*cnt - au*sum(av)    //new node bigger than av
// sum(au^2) - sum(au) * av //new node smaller than au
