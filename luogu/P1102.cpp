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

using i64 = std::int64_t;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	
	int n, c;
	std::cin >> n >> c;

	std::vector<i64> a(n, 0);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	std::ranges::sort(a);
	i64 ans = 0;
	for (int i = 0, l = 0, r = 0; i < n && l < n; i++) {
		while (l < n && a[l] - a[i] < c) {
			l++;
		}

		while (r < n && a[r] - a[i] <= c) {
			r++;
		}
		if (l < n && a[l] - a[i] == c) {
			ans += r - l;
		}
	}
	std::cout << ans << std::endl;
}