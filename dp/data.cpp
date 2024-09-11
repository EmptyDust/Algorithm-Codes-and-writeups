#include <bits/stdc++.h>

const int inf = 1e9 + 7;

signed main()
{
	srand(time(0));
	//	std::cout<<1<<'\n'; 
	int n = rand() % 5 + 1, m = rand() % 5 + 1;
	std::cout << n << ' ' << m << '\n';
	for (int i = 0;i < n;++i) {
		for (int j = 0;j < m;++j) {
			std::cout << (rand() % inf) << " ";
		}
		std::cout << '\n';
	}

	return 0;
}
