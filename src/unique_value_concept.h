//
// Created by PeterBurgess on 21/08/2023.
//


#pragma once


#include <type_traits>


namespace type_util
{

template<auto VALUE, auto... VALUE_LIST>
constexpr bool _are_unique_values_v_ = (_are_unique_values_v_<VALUE, VALUE_LIST> && ...) && _are_unique_values_v_<VALUE_LIST...>;

template<auto VALUE_A, auto VALUE_B>
constexpr bool _are_unique_values_v_<VALUE_A, VALUE_B> = VALUE_A != VALUE_B;

template<auto VALUE>
constexpr bool _are_unique_values_v_<VALUE> = true;

template<auto ... VALUE_LIST>
concept are_unique_values = (_are_unique_values_v_<VALUE_LIST...>);



} // namespace type_util