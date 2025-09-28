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

constexpr i64 N = 1'001;
constexpr i64 MOD = 1e8-3;

std::array<i64, N> res = {0};
std::array<i64, N> a = {0};

void multiply1() {
	std::array<i64, N> tmp = {0};
	for (int i = 0; i < N / 2; i++) {
		for (int j = 0; j < N / 2; j++) {
			tmp[i + j] += res[i] * a[j];
		}
	}  

	i64 t = 0;
	for (int i = 0; i < N / 2; i++) {
		tmp[i] += t;
		res[i] = tmp[i] % 10;
		t = tmp[i] / 10;
	}
}

void multiply2() {
	std::array<i64, N> tmp = {0};
	for (int i = 0; i < N / 2; i++) {
		for (int j = 0; j < N / 2; j++) {
			tmp[i + j] += a[i] * a[j];
		}
	}  

	i64 t = 0;
	for (int i = 0; i < N / 2; i++) {
		tmp[i] += t;
		a[i] = tmp[i] % 10;
		t = tmp[i] / 10;
	}
}


void quickPow(i64 b) {
	res[0] = 1;
	a[0] = 2;
	while (b > 0) {
		if (b % 2 == 1) {
			multiply1();
		}
		multiply2();
		b >>= 1;
	}

}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	i64 p;
	std::cin >> p;
	std::cout << static_cast<i64> (p * std::log10(2) + 1) << "\n";

	quickPow(p);
	res[0] -= 1;
	for (int i = N / 2 - 1, j = 0; i >= 0; i--) {
		if (j == 50) {
			std::cout << "\n";
			j = 0;
		}
		std::cout << res[i];
		j++;
	}

	return 0;
}
