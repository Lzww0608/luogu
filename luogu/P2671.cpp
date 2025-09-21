#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <utility>#include <iostream>
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
#include <cstdio>

using i64 = std::int64_t;

constexpr i64 N = 100'001;
constexpr i64 MOD = 10007;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	
	int n, m;
	std::cin >> n >> m;
	std::vector<i64> num(n), col(n);
	for (int i = 0; i < n; i++) {
		std::cin >> num[i];
	}
	for (int i = 0; i < n; i++) {
		std::cin >> col[i];
	}

	i64 ans = 0;
	std::vector<std::array<i64, 4>> cnt1(N);
	std::vector<std::array<i64, 4>> cnt2(N);
	for (int i = 0; i < n; i++) {
		auto x = num[i], y = col[i];
		int t = i + 1;
		if (i % 2 == 0) {
			ans += cnt1[y][0] * t * x % MOD;
			ans += cnt1[y][1] % MOD;
			ans += cnt1[y][2] * x % MOD;
			ans += cnt1[y][3] * t % MOD;
			ans %= MOD;

			cnt1[y][0] = (cnt1[y][0] + 1) % MOD;
			cnt1[y][1] = (cnt1[y][1] + t * x) % MOD;
			cnt1[y][2] = (cnt1[y][2] + t) % MOD;
			cnt1[y][3] = (cnt1[y][3] + x) % MOD;
		} else {
			ans += cnt2[y][0] * t * x % MOD;
			ans += cnt2[y][1] % MOD;
			ans += cnt2[y][2] * x % MOD;
			ans += cnt2[y][3] * t % MOD;
			ans %= MOD;

			cnt2[y][0] = (cnt2[y][0] + 1) % MOD;
			cnt2[y][1] = (cnt2[y][1] + t * x) % MOD;
			cnt2[y][2] = (cnt2[y][2] + t) % MOD;
			cnt2[y][3] = (cnt2[y][3] + x) % MOD;
		} 
	}


	std::cout << ans << "\n";

	return 0;
}
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
#include <cstdio>

using i64 = std::int64_t;

constexpr i64 N = 100'001;
constexpr i64 MOD = 10007;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	
	int n, m;
	std::cin >> n >> m;
	std::vector<int> num(n), col(n);
	for (int i = 0; i < n; i++) {
		std::cin >> num[i];
	}
	for (int i = 0; i < n; i++) {
		std::cin >> col[i];
	}

	i64 ans = 0;
	std::vector<std::array<int, 4>> cnt1(N);
	std::vector<std::array<int, 4>> cnt2(N);
	for (int i = 0; i < n; i++) {
		auto x = num[i], y = col[i];
		cnt1[y][i % 2]++;
		cnt2[y][i % 2] = (cnt2[y][i % 2] + x) % MOD;
	}

	for (int i = 0; i < n; i++) {
		int y = col[i];
		ans += (i + 1) * (cnt2[y][i % 2] + num[i] * (cnt1[y][i % 2] - 2) % MOD) % MOD;
		ans %= MOD;
	}

	std::cout << ans << "\n";

	return 0;
}