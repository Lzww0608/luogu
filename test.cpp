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


class RefCount {
public:
	void AddRef() {
		count++;
	}

	int Release() {
		return --count;
	}

	int GetCount() {
		return count;
	}

private:
	int count{1};
};

template <typename T>
class SharedPtr {
public:
	SharedPtr(): ptr(nullptr), refCount(nullptr) {}

	explicit SharedPtr(T* p): ptr(p), refCount(new RefCount) {}

	SharedPtr(const SharedPtr<T>& other) {
		ptr = other.ptr;
		refCount = other.refCount;
		if (refCount) {
			refCount->AddRef();
		}
	}

	SharedPtr(const SharedPtr<T>&& other) noexcept {
		ptr = other.ptr;
		refCount = other.refCount;
		other.ptr = nullptr;
		other.refCount = nullptr;
	}

	SharedPtr<T>& operator=(const SharedPtr<T>& other) {
		if (this != other) {
			Release();

			ptr = other.ptr;
			refCount = other.refCount;
			if (refCount) {
				refCount->AddRef();
			}
		}

		return *this;
	}

	SharedPtr<T>& operator=(const SharedPtr<T>&& other) noexcept {
		if (this != other) {
			Release();

			ptr = other.ptr;
			refCount = other.refCount;
			other.ptr = nullptr;
			other.refCount = nullptr;
		}

		return *this;
	}

	T& operator*() const {
		return *ptr;
	}

	T* operator->() const {
		return ptr;
	}

	T* get() const {
		return ptr;
	}

	int use_count() const {
		return refCount ? refCount->GetCount() : 0;
	}

	~SharedPtr() {
		Release();
	}

private:
	T* ptr;
	RefCount* refCount;

	void Release() {
		if (refCount && refCount->Release() == 0) {
			delete ptr;
			delete refCount;
		}

		ptr = nullptr;
		refCount = nullptr;
	}
};