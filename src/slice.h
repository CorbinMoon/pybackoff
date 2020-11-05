#ifndef SLICE_H
#define SLICE_H


#include <iostream>
#include <tuple>
#include <utility> 


template<size_t N, size_t... Ts>
constexpr std::index_sequence<N + Ts...>
add(std::index_sequence<Ts...>) {
   return {};
}

template<size_t L, size_t R>
using make_index_range = decltype(add<L>(std::make_index_sequence<R - L>()));

template <typename... T, size_t... I>
auto __slice(const std::tuple<T...>& t, std::index_sequence<I...>) {
   return std::make_tuple(std::get<I>(t)...);
}

template <int L, int R, typename... T>
auto slice(const std::tuple<T...>& t) {
   return __slice(t, make_index_range<L, R>());
}


#endif