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

	
	int n, m;
	std::cin >> n >> m;
	std::vector<i64> a(n, 0);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	std::unordered_map<i64, i64> cnt;
	int ans = INT_MAX, left = 0, right = 0;
	for (int l = 0, r = 0; r < n; r++) {
		cnt[a[r]]++;

		while (cnt.size() == m) {
			if (ans > r - l + 1) {
				ans = r - l + 1;
				left = l;
				right = r;
			}
			if (cnt[a[l]]--; cnt[a[l]] == 0) {
				cnt.erase(a[l]);
			}
			l++;
		}
	}

	std::cout << left + 1 << " " << right + 1 << std::endl;
}