#include <bits/stdc++.h>
//c++的命名空间，不用管它
using namespace std;

void myswap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void myreverse(int nums[], int l, int r) {
    int i = l, j = r - 1;
    while (i < j) {
        myswap(&nums[i], &nums[j]);
        ++i, --j;
    }
}

int main() {
    int m, n;

    //输入cin
    cin >> n;
    int nums[10000];
    for (int i = 0;i < n;++i)cin >> nums[i];
    cin >> m;

    //核心代码
    //reverse反转 区间左闭右开
    //nums.begin()  nums[0]
    //nums.end()  nums[n]  *(nums+n) 
    myreverse(nums, 0, n);
    myreverse(nums, 0, m);
    myreverse(nums, m, n);

    //输出cout
    for (int i = 0; i < n; i++)cout << nums[i] << ' ';
    //*(arr+i)  arr[i]
    return 0;
}