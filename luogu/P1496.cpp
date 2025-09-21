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

	int n;
	std::cin >> n;
	std::vector<i64> a(n), b(n);

	for (int i = 0; i < n; i++) {
		std::cin >> a[i] >> b[i];
	} 

	std::ranges::sort(a);
	std::ranges::sort(b);

	i64 ans = 0;
	for (int i = 0; i < n; i++) {
		ans += b[i] - a[i];
		if (i + 1 < n && b[i] > a[i + 1]) {
			ans -= b[i] - a[i + 1];
		}
	}

	std::cout << ans << "\n";

	return 0;
}
