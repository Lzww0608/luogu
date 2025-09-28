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

constexpr i64 N = 100'001;
constexpr i64 M = 20;
constexpr i64 MOD = 1e8-3;


int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, k;
	std::cin >> n >> k;
	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	int ans = 0;
	std::function<void(int, int, int)> dfs;
	dfs = [&] (int i, int cnt, int sum) {
		if (n - i < k - cnt) {
			return;
		}
		if (cnt == k) {
			for (int i = 2; i * i <= sum; i++) {
				if (sum % i == 0) {
					return;
				}
			}
			ans++;
			return;
		}

		dfs(i + 1, cnt, sum);
		dfs(i + 1, cnt + 1, sum + a[i]);
	};
	dfs(0, 0, 0);

	std::cout << ans << "\n";
	return 0;
}
