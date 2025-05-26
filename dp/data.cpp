#include <bits/stdc++.h>

const int inf = 1e9 + 7;

std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

signed main()
{
	std::cout << 1 << '\n';
	int n = rng() % 100;
	std::cout << n << '\n';
	for (int i = 0;i < n;++i) {
		std::cout << rng() % 5 + 1 << ' ';
	}

	return 0;
}
