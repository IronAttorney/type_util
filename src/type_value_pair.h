//
// Created by PeterBurgess on 21/08/2023.
//


#pragma once


#include <type_traits>


namespace type_util
{


template<class T_FIRST, auto V_SECOND>
struct type_value_pair
{
    using first = T_FIRST;
    static constexpr auto second = V_SECOND;

    using _is_type_value_pair = std::true_type;
};

/**
 * Returns `std::true_type` if `T` is contains a nested type `__IS_VALUE_TO_TYPE_MAP_ELEMENT__` that is an alias of `std::true_type`
 */
template<class T>
using is_type_value_pair = typename T::_is_type_value_pair;



} // namespace type_util