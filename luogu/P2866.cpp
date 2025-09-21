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
#include <cstdio>

using i64 = std::int64_t;

constexpr i64 N = 100'001;
constexpr i64 MOD = 10007;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;
	std::vector<int> a(n + 1);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	a[n] = INT_MAX;

	i64 ans = 0;
	std::stack<int> st;
	for (int i = 0; i <= n; i++) {
		while (!st.empty() && a[i] >= a[st.top()]) {
			auto j = st.top();
			ans += i - j - 1;
			st.pop();
		}

		st.push(i);
	}
	
	std::cout << ans << "\n";

	return 0;
}