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

	i64 n, m, s;
	std::cin >> n >> m >> s;
	std::vector<i64> w(n), v(n);
	for (int i = 0; i < n; i++) {
		std::cin >> w[i] >> v[i];
	}
	std::vector<i64> l(m), r(m);
	for (int i = 0; i < m; i++) {
		std::cin >> l[i] >> r[i];
		l[i]--;
		r[i]--;
	}

	i64 ans = s;

	auto check = [&] (i64 W) -> bool {
		std::vector<i64> cnt(n + 1, 0), pre(n + 1, 0);
		for (int i = 0; i < n; i++) {
			if (w[i] >= W) {
				cnt[i + 1] = cnt[i] + 1;
				pre[i + 1] = pre[i] + v[i];
			} else {
				cnt[i + 1] = cnt[i];
				pre[i + 1] = pre[i];
			}
		}

		i64 sum = 0;
		for (int i = 0; i < m; i++) {
			int x = l[i], y = r[i];
			sum += (pre[y + 1] - pre[x]) * (cnt[y + 1] - cnt[x]);
		}

		ans = std::min(ans, std::abs(sum - s));

		return sum <= s;
	};

	i64 left = 0, right = 1e6 + 1;
	while (left + 1 < right) {
		auto mid = left + ((right - left) >> 1);
		if (check(mid)) {
			right = mid;
		} else {
			left = mid;
		}
	}

	check(left); check(right);

	std::cout << ans << "\n";

	return 0;
}
