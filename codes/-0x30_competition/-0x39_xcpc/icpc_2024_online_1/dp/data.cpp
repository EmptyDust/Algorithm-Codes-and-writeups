#include<bits/stdc++.h>

signed main() {
    srand(time(0));
    int n = rand()%7+1;
    std::cout<<n<<'\n';
    for (int i = 0;i < n;++i) {
    	int x = rand() % 100;
        std::cout << x << ' ';
    }
    return 0;
}
