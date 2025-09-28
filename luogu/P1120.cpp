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

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n;
	std::cin >> n;
	std::vector<int> a(n);

	int sum = 0, d = 0;
	std::array<int, N> len {};
	std::array<int, N> pre {};
 	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
		sum += a[i];
		len[a[i]]++;
	}

	std::ranges::sort(a);
	pre[a[0]] = 0;
	for (int i = 1; i < n; i++) {
		if (a[i] != a[i - 1]) {
			pre[a[i]] = a[i - 1];
		}
	}

	std::function<bool(int, int, int)> dfs;
	dfs = [&] (int u, int k, int p) -> bool {
		if (u == 0) {
			return dfs(d, k - 1, a[n - 1]);
		}

		if (k == 0) {
			return true;
		}

		if (p > u) {
			p = u;
		}

		while (p > 0 && len[p] == 0) {
			p--;
		}
		while (p > 0) {
			if (len[p] > 0) {
				len[p]--;
				if (dfs(u - p, k, p)) {
					return true;
				}
				len[p]++;
				if (u == p || u == d) {
					return false;
				}
				p = pre[p];
			} else {
				p = pre[p];
			}
		}

		return false;
	};

	for (d = a[n - 1]; d * 2 <= sum; d++) {
		if (sum % d == 0) {
			if (dfs(d, sum / d, a[n - 1])) {
				std::cout << d << "\n";
				return 0;
			}
		}
	}


	std::cout << sum << "\n";
	return 0;
}
