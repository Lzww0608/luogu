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

constexpr i64 N = 1'001;
constexpr i64 M = 20;
constexpr i64 MOD = 1e8-3;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, q;
	std::cin >> n >> q;
	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	std::vector<std::array<int, M>> mx(n + 1);
	std::vector<std::array<int, M>> mn(n + 1);
	std::vector<int> log2(n + 1, 0);

	for (int i = 2; i <= n; i++) {
		log2[i] = log2[i >> 1] + 1;
	}

	for (int i = 0; i < n; i++) {
		mx[i][0] = a[i];
		mn[i][0] = a[i];
	}

	for (int j = 1; (1 << j) <= n; j++) {
		for (int i = 0; i + (1 << j) <= n; i++) {
			mx[i][j] = std::max(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);
			mn[i][j] = std::min(mn[i][j - 1], mn[i + (1 << (j - 1))][j - 1]);
		}
	}

	auto rmqMax = [&] (int l, int r) -> int {
		int d = log2[r - l + 1];
		return std::max(mx[l][d], mx[r - (1 << d) + 1][d]);
	};

	auto rmqMin = [&] (int l, int r) -> int {
		int d = log2[r - l + 1];
		return std::min(mn[l][d], mn[r - (1 << d) + 1][d]);
	};

	int l, r;
	for (int i = 0; i < q; i++) {
		std::cin >> l >> r;
		l--; r--;
		std::cout << rmqMax(l, r) - rmqMin(l, r) << "\n";
	}

	return 0;
}
