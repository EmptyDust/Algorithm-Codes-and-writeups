#include<iostream>
using namespace std;

//快速幂

// a ^ n

// 1 2 4 8 16 32
// 3 = 1 + 2
// 6 = 4 + 2 // 110   0 * (2^0) + 1 * (2^1) + 1 * (2^2)
// 33 = 32 + 1

// 127 = 64 + 32 + 16 + 8 + 4 + 2 + 1
// 1111111

// 26127  1 78 6084 

// 26172 / 6084 
// (26172 % 6084) / 78
// (26172 % 6084) % 78

// a ^ 33 = a ^ 32 * a

// a ^ 32 = (a ^ 16) ^ 2

// log2(n)

// (a + b) % p = (a % p + b % p) % p
// (a - b) % p = (a % p - b % p) % p
// (a * b) % p = (a % p * b % p) % p

// long long int 
//quick_pow
long long qpow(long long a, int n, int p) {//a ^ n
    long long res = 1;
    while (n) {
        if (n % 2 == 1)res = res * a % p;// res = res * a
        a = a * a % p;
        n = n / 2;
    }
    return res;
}

void solve() {
    int p;cin >> p;
    int n;cin >> n;
    long long ans = 0;
    for (int i = 0;i < n;++i) {
        int a, b;cin >> a >> b;
        ans = (ans + qpow(a, b, p)) % p;
    }
    cout << ans << '\n';
}

int main() {
    int z;
    cin >> z;
    while (z--) {
        solve();
    }

    return 0;
}