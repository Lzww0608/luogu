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
	std::vector<std::vector<int>> a (n, std::vector<int> (n, 0));
	std::vector<std::vector<int>> pre (n + 1, std::vector<int> (n + 1, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cin >> a[i][j];
			pre[i + 1][j + 1] = pre[i + 1][j] + pre[i][j + 1] - pre[i][j] + a[i][j];
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			int mn = 0;
			for (int k = 0; k < n; k++) {
				int cur = pre[j + 1][k + 1] - pre[i][k + 1];
				ans = std::max(ans, cur - mn);
				mn = std::min(mn, cur);
			}
		}
	}

	std::cout << ans << "\n";

	return 0;
}



