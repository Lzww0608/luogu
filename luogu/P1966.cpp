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

constexpr i64 N = 1e8-3;
constexpr i64 MOD = 1e8-3;


i64 merge(std::vector<int>& a, int l, int r) {
	if (l >= r) return 0;
	i64 cnt = 0;
	int mid = l + ((r - l) >> 1);
	cnt += merge(a, l, mid);
	cnt += merge(a, mid + 1, r);
	std::vector<int> tmp(r - l + 1, 0);

	cnt %= MOD;
	for (int i = l, j = mid + 1; i <= mid; i++) {
		while (j <= r && a[i] > a[j]) {
			j++;
		}
		cnt += j - mid - 1;
	}

	cnt %= MOD;
	int i = l, j = mid + 1, k = 0;
	while (i <= mid || j <= r) {
		if (j > r || i <= mid && a[i] <= a[j]) {
			tmp[k++] = a[i++];
		} else {
			tmp[k++] = a[j++];
		}
	}
	std::copy(tmp.begin(), tmp.end(), a.begin() + l);

	return cnt;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;
	std::vector<pii> a(n);
	std::vector<pii> b(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i].first;
		a[i].second = i;
	}
	for (int i = 0; i < n; i++) {
		std::cin >> b[i].first;
		b[i].second = i;
	}

	std::ranges::sort(a.begin(), a.end(), [] (const auto& u, const auto& v) {
		return u.first < v.first;
	});
	std::ranges::sort(b.begin(), b.end(), [] (const auto& u, const auto& v) {
		return u.first < v.first;
	});

	std::vector<int> c(n);
	for (int i = 0; i < n; i++) {
		c[b[i].second] = a[i].second;
	}

	std::cout << merge(c, 0, n - 1) << "\n";

	return 0;
}
