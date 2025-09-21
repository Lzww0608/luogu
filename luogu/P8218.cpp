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

	int n, m;
	std::cin >> n;
	std::vector<int> a(n), pre(n + 1, 0);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
		pre[i + 1] = pre[i] + a[i];
	}
	std::cin >> m;

	int l, r;
	for (int i = 0; i < m; i++) {
		std::cin >> l >> r;
		std::cout << pre[r] - pre[l - 1] << "\n";
	}
	
	return 0;
}



