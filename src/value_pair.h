//
// Created by PeterBurgess on 21/08/2023.
//


#pragma once


#include <type_traits>


namespace type_util
{


template<auto V_FIRST, auto V_SECOND>
struct value_pair
{
    static constexpr auto first = V_FIRST;
    static constexpr auto second = V_SECOND;

    using _is_value_pair = std::true_type;
};

/**
 * Returns `std::true_type` if `T` contains a nested type `_is_value_pair` that is an alias of `std::true_type`
 */
template<class T>
using is_value_pair = typename T::_is_value_pair;



} // namespace type_util