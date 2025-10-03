#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <utility>
#include <tuple>
#include <ranges>
#include <functional>
#include <chrono>
#include <vector>
#include <array>
#include <random>
#include <stack>
#include <bitset>
#include <deque>
#include <ios>
#include <list>
#include <cstdint>
#include <limits>
#include <limits.h>
#include <cstdio>
#include <shared_mutex>
#include <mutex>
#include <memory>
#include <condition_variable>
#include <thread>
#include <random>

using i64 = std::int64_t;
using pii = std::pair<i64, i64>;
using tii = std::tuple<i64, i64, i64>;

constexpr i64 N = 9;
constexpr i64 M = 16;
constexpr i64 MOD = 1e8-3;
constexpr int ED = 123804765;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::queue<pii> q;
	std::unordered_map<int, int> m[2];

	auto change = [&] (int x, int op) -> int {
		std::array<int, N> a;
		int p = -1;
		for (int i = N - 1; i >= 0; i--) {
			a[i] = x % 10;
			if (a[i] == 0) {
				p = i;
			}
			x /= 10;
		}

		if (op == 1) {
			if (p < 3) {
				return -1;
			}
			std::swap(a[p], a[p - 3]);
		} else if (op == 2) {
			if (p >= 6) {
				return -1;
			}
			std::swap(a[p], a[p + 3]);
		} else if (op == 3) {
			if (p % 3 == 0) {
				return -1;
			}
			std::swap(a[p], a[p - 1]);
		} else {
			if (p % 3 == 2) {
				return -1;
			}
			std::swap(a[p], a[p + 1]);
		}

		x = 0;
		for (int i = 0; i < N; i++) {
			x = x * 10 + a[i];
		}

		return x;
	};

	auto check = [&] (int x, pii p) -> int {
		if (x == -1) {
			return -1;
		}
		if (m[p.second ^ 1].contains(x)) {
			return m[p.second ^ 1][x] + m[p.second][p.first] + 1;
		} else {
			m[p.second][x] = m[p.second][p.first] + 1;
			q.push({x, p.second});
		}

		return -1;
	};
	
	int bg;
	std::cin >> bg;
	if (bg == ED) {
		std::cout << "0\n";
		return 0;
	}


	q.push({bg, 1});
	q.push({ED, 0});
	while (!q.empty()) {
		auto p = q.front();
		q.pop();
		for (int i = 1; i <= 4; i++) {
			int x = change(p.first, i);
			int t = check(x, p);
			if (t != -1) {
				std::cout << t << "\n";
				return 0;
			}
		}
	}
	
	return 0;
}
