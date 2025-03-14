#include <bits/stdc++.h>

const int inf = 1e9 + 7;

signed main()
{
	srand(time(0));
	int n = rand() % 10 + 1;
	std::cout << n << ' ' << 1 << '\n';
	int sum = 0;
	for (int i = 0;i < n;++i) {
		int x = rand() % 4 + 1;
		sum += x;
		std::cout << x << ' ';
	}
	std::cout << '\n';
	int l = rand() % sum + 1;
	int r = std::min(l + rand() % 8, sum);
	std::cout << l << ' ' << r << '\n';

	return 0;
}
