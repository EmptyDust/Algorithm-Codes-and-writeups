#ifndef REPO_LOCAL_BITS_STDCXX_H
#define REPO_LOCAL_BITS_STDCXX_H

#include <algorithm>
#include <array>
#include <atomic>
#include <bit>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfenv>
#include <cfloat>
#include <chrono>
#include <cinttypes>
#include <climits>
#include <clocale>
#include <cmath>
#include <complex>
#include <condition_variable>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <exception>
#include <filesystem>
#include <forward_list>
#include <fstream>
#include <functional>
#include <future>
#include <initializer_list>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <mutex>
#include <new>
#include <numeric>
#include <optional>
#include <ostream>
#include <queue>
#include <random>
#include <ratio>
#include <regex>
#include <set>
#include <shared_mutex>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <string_view>
#include <system_error>
#include <thread>
#include <tuple>
#include <type_traits>
#include <typeindex>
#include <typeinfo>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <valarray>
#include <variant>
#include <vector>

namespace std {
inline int __lg(int x) {
    return 31 - __builtin_clz(x);
}

inline int __lg(long long x) {
    return 63 - __builtin_clzll(x);
}

inline int __lg(unsigned x) {
    return 31 - __builtin_clz(x);
}

inline int __lg(unsigned long long x) {
    return 63 - __builtin_clzll(x);
}
} // namespace std

#if __cplusplus >= 202002L
#include <barrier>
#include <compare>
#include <concepts>
#include <coroutine>
#include <latch>
#include <numbers>
#include <ranges>
#include <semaphore>
#include <span>
#include <stop_token>
#include <syncstream>
#endif

#endif
