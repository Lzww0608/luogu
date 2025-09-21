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
constexpr i64 MOD = 10007;

void quickSort(std::vector<int>& a, int l, int r) {
	if (l >= r) return;

	int pivot = a[l + rand() % (r - l + 1)];
	int i = l, j = l, k = r + 1;
	while (i < k) {
		if (a[i] > pivot) {
			k--;
			std::swap(a[k], a[i]);
		} else if (a[i] < pivot) {
			std::swap(a[i], a[j]);
			i++; j++;
		} else {
			i++;
		}
	}

	quickSort(a, l, j);
	quickSort(a, i, r);
	return;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for (int& x : a) {
		std::cin >> x;
	}

	quickSort(a, 0, n - 1);
	for (int x : a) {
		std::cout << x << " ";
	}

	return 0;
}
