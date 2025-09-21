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

constexpr i64 N = 100'001;
constexpr i64 MOD = 10007;


int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, p;
	std::cin >> n >> p;
	std::vector<i64> a(n + 1, 0);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	int x, y, z;
	std::vector<int> dif(n + 1, 0);
	for (int i = 0; i < p; i++) {
		std::cin >> x >> y >> z;
		dif[x - 1] += z;
		dif[y] -= z;
	}

	i64 cur = 0, ans = INT64_MAX;
	for (int i = 0; i < n; i++) {
		cur += dif[i];
		ans = std::min(ans, cur + a[i]);
	}

	std::cout << ans << "\n";

	return 0;
}
