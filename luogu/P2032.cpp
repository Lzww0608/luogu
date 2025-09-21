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

using i64 = std::int64_t;

constexpr i64 N = 100'001;
constexpr i64 MOD = 10007;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, k;
	std::cin >> n >> k;
	std::vector<int> a(n, 0);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	std::deque<int> dq;
	for (int i = 0; i < n; i++) {
		while (!dq.empty() && a[dq.back()] <= a[i]) {
			dq.pop_back();
		}
		dq.push_back(i);

		if (dq.front() < i - k + 1) {
			dq.pop_front();
		}

		if (i >= k - 1) {
			std::cout << a[dq.front()] << "\n";
		}
	}
	
	return 0;
}
