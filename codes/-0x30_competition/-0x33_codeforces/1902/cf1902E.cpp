#include<bits/stdc++.h>
#define int long long
using namespace std;

class trie {
public:
    struct trie* nxt[26];
    int cnt = 0;

    void ad(string s) {
        trie* tmp = this;
        for (char ch : s) {
            //cout<<ch;
            int i = ch - 'a';
            if (!tmp->nxt[i])
                tmp->nxt[i] = new trie();
            tmp = tmp->nxt[i];
            tmp->cnt++;
        }
    }

    int f(string s) {
        trie* tmp = this;
        int ret = 0;
        for (char ch : s) {
            int i = ch - 'a';
            if (!tmp->nxt[i])
                return ret;
            tmp = tmp->nxt[i];
            ret += tmp->cnt;
        }
        return ret;
    }
};

signed main() {
    ios::sync_with_stdio(false);
    int n;cin >> n;
    string s, sr;
    int sum = 0, ans = 0;
    trie* root = new trie(), * rootr = new trie();
    int k = 0, slen;
    while (n--) {
        cin >> s;
        reverse(s.begin(), s.end());
        sr = s;
        reverse(s.begin(), s.end());
        slen = s.length();

        ans += sum + k * slen - 2 * root->f(sr);
        ans += sum + k * slen - 2 * rootr->f(s);

        int i = 0, j = slen - 1;
        while (i <= j && s[i] == s[j])i++, j--;
        if (i <= j)
            ans += slen * 2 - i * 2;

        root->ad(s);
        rootr->ad(sr);

        sum += slen;
        ++k;
    }
    cout << ans << endl;
    return 0;
}