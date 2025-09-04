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

using i64 = std::int64_t;

constexpr i64 N = 1'000'000;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	i64 ans = INT64_MIN, cur = 0;
	for (i64 x : a) {
		cur = std::max(cur + x, x);
		ans = std::max(ans, cur);
	}

	std::cout << ans << std::endl;
}