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


i64 quickSort(i64 a, i64 b, i64 p) {
	i64 res = 1;
	while (b > 0) {
		if (b % 2 == 1) {
			res = res * a % p;
		}
		a = a * a % p;
		b >>= 1;
	}

	return res;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	i64 a, b, p;
	std::cin >> a >> b >> p;

	std::cout << a << "^" << b << " mod " << p << "=" << quickSort(a, b, p) << "\n";

	return 0;
}
