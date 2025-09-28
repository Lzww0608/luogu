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
using pii = std::pair<double, double>;
using tii = std::tuple<i64, i64, i64>;

constexpr i64 N = 51;
constexpr i64 M = 16;
constexpr i64 MOD = 1e8-3;

double calc(pii a, pii b) {
	return std::sqrt(double(a.first - b.first) * (a.first - b.first) + double(a.second - b.second) * (a.second - b.second));
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n;
	std::cin >> n;
	std::vector<pii> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i].first >> a[i].second;
	}

	std::vector<std::vector<double>> f(n, std::vector<double>(1 << n, std::numeric_limits<double>::max() / 2));

	for (int i = 0; i < n; i++) {
		f[i][1 << i] = calc({0, 0}, a[i]);
	}

	for (int s = 1; s < (1 << n); s++) {
		for (int i = 0; i < n; i++) {
			if ((s & (1 << i)) != 0) {
				for (int j = 0; j < n; j++) {
					if ((s & (1 << j)) != 0 && i != j) {
						f[i][s] = std::min(f[i][s], f[j][s ^ (1 << i)] + calc(a[i], a[j]));
					}
				}
			}
		}
	}

	double ans = std::numeric_limits<double>::max();
	for (int i = 0; i < n; i++) {
		ans = std::min(ans, f[i][(1 << n) - 1]); 
	}

	std::cout << std::fixed << std::setprecision(2) << ans << std::endl;
	
	return 0;
}
