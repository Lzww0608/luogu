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

	int m, n;
	std::cin >> m >> n;
	std::vector<std::string> s(m);
	for (int i = 0; i < m; i++) {
		std::cin >> s[i];
	}

	i64 ans = 0;
	std::vector<i64> pre(n, 0);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (s[i][j] == '.') {
				pre[j]++;
			} else {
				pre[j] = 0;
			}
		}

		std::stack<int> st;
		st.push(-1);
		i64 sum = 0;
		for (int i = 0; i < n; i++) {
			while (st.size() > 1 && pre[i] < pre[st.top()]) {
				auto h = st.top();
				st.pop();
				sum -= (h - st.top()) * pre[h];
			}
			sum += (i - st.top()) * pre[i];
			ans += sum;
			st.push(i);
		}
	}

	std::cout << ans << "\n";
	return 0;
}
