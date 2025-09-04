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

constexpr i64 N = 601;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	
	int n, w;
	std::cin >> n >> w;

	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	std::array<int, N> cnt{};
	for (int i = 0; i < n; i++) {
		int x = a[i];
		cnt[x]++;
		int j = N - 1, sum = 0;
		while (sum < std::max(1, (i + 1) * w / 100)) {
			sum += cnt[j];
			j--;
		}
		std::cout << j + 1 << " ";
	}

	return 0;
}