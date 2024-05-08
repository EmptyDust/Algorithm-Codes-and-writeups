#include <stdio.h>
#include <stdlib.h>

int nums[(int)1e6];
int ans[(int)1e6], st = 0;

struct node
{
    int num;
    struct node* left, * right;
}nodes[(int)1e6];

typedef struct node node;

int dfs(int i, struct node* root) {
    int a = i, b = i;
    if (root->left)a = dfs(i + 1, root->left);
    ans[st++] = root->num;
    if (root->right)b = dfs(i + 1, root->right);
    return (a > b ? a : b);
}

int main() {
    node* root = (node*)malloc(sizeof(node));
    root->left = NULL;
    root->right = NULL;
    int n, i;
    scanf("%d", &n);
    for (i = 0;i < n;++i)scanf("%d", &nums[i]);
    root->num = nums[0];
    for (i = 1;i < n;++i) {
        node* f = root, * tmp = (node*)malloc(sizeof(node));
        tmp->num = nums[i];
        tmp->left = NULL;
        tmp->right = NULL;
        while (f) {
            if (f->num > nums[i]) {
                if (f->left)f = f->left;
                else {
                    f->left = tmp;
                    break;
                }
            }
            else {
                if (f->right)f = f->right;
                else {
                    f->right = tmp;
                    break;
                }
            }
        }
    }
    printf("%d\n", dfs(1, root));
    for (i = 0;i < n;++i)printf("%d ", ans[i]);

    return 0;
}
