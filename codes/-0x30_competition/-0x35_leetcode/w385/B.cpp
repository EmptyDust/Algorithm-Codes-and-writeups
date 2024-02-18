#include <bits/stdc++.h>
using namespace std;
struct dic {
    struct dic* dics[10];
    int cnt = 0;
    void insert(int x) {
        int len = 0;
        vector<int> tmp(10);
        while (x)tmp[len++] = x % 10, x /= 10;
        dic* t = this;
        while (len--) {
            if (!t->dics[tmp[len]])t->dics[tmp[len]] = new dic();
            t = t->dics[tmp[len]];
            t->cnt++;
        }
    }
    int qry(int x) {
        int len = 0;
        vector<int> tmp(10);
        while (x)tmp[len++] = x % 10, x /= 10;
        dic* t = this;
        while (len--) {
            if (!t->dics[tmp[len]])return 0;
            t = t->dics[tmp[len]];
        }
        return t->cnt;
    }
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        dic* d = new dic();
        for (int num : arr1)d->insert(num);
        int ans = 0;
        for (int num : arr2)ans = max(ans, d->qry(num));
        return ans;
    }
};