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

	
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> a(n, std::vector<int> (m, 0));

	char c;
	i64 ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cin >> c;
			if (c == 'F') {
				a[i][j] = 1;
			}
		}
	}

	std::vector<i64> pre(m + 1, 0);
	pre[m] = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int x = a[i][j];
			if (x == 0) {
				pre[j] = 0;
			} else {
				pre[j]++;
			}
		}

		std::stack<int> st;
		st.push(-1);
		for (int j = 0; j <= m; j++) {
			while (st.size() > 1 && pre[j] <= pre[st.top()]) {
				auto k = st.top();
				st.pop();
				auto l = st.top();
				ans = std::max(ans, pre[k] * static_cast<i64>(j - l - 1));
			}
			st.push(j);
		}
	}


	std::cout << ans * 3 << "\n";

	return 0;
}