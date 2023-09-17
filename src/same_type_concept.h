//
// Created by PeterBurgess on 21/08/2023.
//


#pragma once


#include <type_traits>


namespace type_util
{


template<class T, class... Ts>
constexpr bool _are_same_types_v_ = std::conjunction_v<std::is_same<T, Ts>...>;

template<class T>
constexpr bool _are_same_types_v_<T> = true;

template <class... Ts>
concept are_same_types = (_are_same_types_v_<Ts...>);


} // namespace type_util
