//
// Created by PeterBurgess on 21/08/2023.
//


#pragma once


#include <type_traits>


namespace type_util
{


template<auto V_FIRST, class T_SECOND>
struct value_type_pair
{
    static constexpr auto first = V_FIRST;
    using second = T_SECOND;

    using _is_value_type_pair = std::true_type;
};

/**
 * Returns `std::true_type` if `T` is contains a nested type `__IS_VALUE_TO_TYPE_MAP_ELEMENT__` that is an alias of `std::true_type`
 */
template<class T>
using is_value_type_pair = typename T::_is_value_type_pair;



} // namespace type_util