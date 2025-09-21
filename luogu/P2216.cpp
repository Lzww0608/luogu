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

	int m, n, k;
	std::cin >> m >> n >> k;
	std::vector<std::vector<int>> a(m, std::vector<int> (n, 0));
	std::vector<std::vector<int>> M(m, std::vector<int> (n, INT_MIN));
	std::vector<std::vector<int>> N(m, std::vector<int> (n, INT_MAX));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			std::cin >> a[i][j];
		}
	}


	for (int i = 0; i < m; i++) {
		std::deque<int> mx, mn;
		for (int j = 0; j < n; j++) {
			while (!mx.empty() && a[i][j] >= a[i][mx.back()]) {
				mx.pop_back();
			}
			mx.push_back(j);
			if (j - mx.front() >= k) {
				mx.pop_front();
			}
			M[i][j] = std::max(M[i][j], a[i][mx.front()]);

			while (!mn.empty() && a[i][j] <= a[i][mn.back()]) {
				mn.pop_back();
			}
			mn.push_back(j);
			if (j - mn.front() >= k) {
				mn.pop_front();
			}
			N[i][j] = std::min(N[i][j], a[i][mn.front()]);
		}
	}

	auto MM = M;
	auto NN = N;
	for (int j = 0; j < n; j++) {
		std::deque<int> mx, mn;
		for (int i = 0; i < m; i++) {
			while (!mx.empty() && M[i][j] >= M[mx.back()][j]) {
				mx.pop_back();
			}
			mx.push_back(i);
			if (i - mx.front() >= k) {
				mx.pop_front();
			}
			MM[i][j] = std::max(MM[i][j], M[mx.front()][j]);

			while (!mn.empty() && N[i][j] <= N[mn.back()][j]) {
				mn.pop_back();
			}
			mn.push_back(i);
			if (i - mn.front() >= k) {
				mn.pop_front();
			}
			NN[i][j] = std::min(NN[i][j], N[mn.front()][j]);
		}
	}

	int ans = INT_MAX;
	for (int i = k - 1; i < m; i++) {
		for (int j = k - 1; j < n; j++) {
			ans = std::min(ans, MM[i][j] - NN[i][j]);
		}
	}

	std::cout << ans << "\n";
	
	return 0;
}
