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

using i64 = std::int64_t;
using pii = std::pair<i64, i64>;

constexpr i64 N = 100'001;
constexpr i64 MOD = 10007;


void solve() {
	int n;
	std::cin >> n;

	std::vector<pii> a;
	std::vector<pii> b;
	a.reserve(n);
	b.reserve(n);
	std::unordered_map<int, int> m;
	int x, y, e;
	for (int i = 0; i < n; i++) {
		std::cin >> x >> y >> e;
		m[x]++;
		m[y]++;
		if (e == 1) {
			a.push_back({x, y});
		} else {
			b.push_back({x, y});
		}
	}

	std::vector<int> c;
	int sz = m.size();
	c.reserve(sz);
	for (auto &[k, _] : m) {
		c.push_back(k);
	}
	std::ranges::sort(c);
	for (int i = 0; i < sz; i++) {
		m[c[i]] = i;
	}

	std::vector<int> fa(sz);
	std::iota(fa.begin(), fa.end(), 0);

	std::function<int(int)> find;
	find = [&] (int x) -> int {
		if (fa[x] != x) {
			fa[x] = find(fa[x]);
		}

		return fa[x];
	};

	auto merge = [&] (int x, int y) {
		int rx = find(x), ry = find(y);
		if (rx != ry) {
			fa[rx] = ry;
		} 

		return;
	};

	for (auto& v : a) {
		int x = v.first, y = v.second;
		merge(m[x], m[y]);
	}

	for (auto& v : b) {
		int x = find(m[v.first]), y = find(m[v.second]);
		if (x == y) {
			std::cout << "NO" << "\n";
			return;
		}
	}

	std::cout << "YES" << "\n";
	return;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
