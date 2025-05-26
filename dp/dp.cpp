#include<bits/stdc++.h>

signed main() {
	system("g++ -std=c++2a std.cpp -o std.exe");
	system("g++ -std=c++2a solve.cpp -o solve.exe");
	system("g++ -std=c++2a data.cpp -o data.exe");
	int t = 0;
	while (1) {
		std::cout << "Test:" << t++ << '\n';
		system("data.exe > data.in");
		system("std.exe < data.in > std.out");
		system("solve.exe < data.in > solve.out");
		if (system("fc std.out solve.out > diff.log")) {
			std::cout << "WA\n";
			break;
		}
		std::cout << "AC\n";
	}
	return 0;
}
