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
#include <random>

using i64 = std::int64_t;
using pii = std::pair<i64, i64>;

constexpr i64 N = 100'001;
constexpr i64 M = 20;
constexpr i64 MOD = 1e8-3;

std::array<std::array<i64, M>, N> nxt, sum;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	nxt = {};
	sum = {};

	int n, q;
	std::cin >> n >> q;
	std::vector<i64> d(n + 1), c(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> d[i] >> c[i];
	}

	auto findMax = [&] () {
		std::stack<int> st;
		for (int i = 1; i <= n; i++) {
			while (!st.empty() && d[i] > d[st.top()]) {
				nxt[st.top()][0] = i;
				sum[st.top()][0] = c[i];
				st.pop();
			}
			st.push(i);
		}
		while(!st.empty()) {
			nxt[st.top()][0] = 0;
			st.pop();
		}
	};

	auto RMQ = [&] () {
		for (int j = 1; (1 << j) <= n; j++) {
			for (int i = 1; i + (1 << j) <= n; i++) {
				nxt[i][j] = nxt[nxt[i][j - 1]][j - 1];
				sum[i][j] = sum[i][j - 1] + sum[nxt[i][j - 1]][j - 1];
			}
		}
	};

	auto query = [&] (int r, int val) -> int {
		if (c[r] >= val) {
			return r;
		}

		val -= c[r];
		for (int i = M - 1; i >= 0; i--) {
			if (nxt[r][i] != 0 && val > sum[r][i]) {
				val -= sum[r][i];
				r = nxt[r][i];
			}
		}

		return nxt[r][0];
	};

	findMax();
	RMQ();
	for (int i = 0; i < q; i++) {
		int r, val;
		std::cin >> r >> val;
		std::cout << query(r, val) << "\n";
	}

	return 0;
}
