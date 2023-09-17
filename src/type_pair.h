//
// Created by PeterBurgess on 21/08/2023.
//


#pragma once


#include <type_traits>


namespace type_util
{


template<class T_FIRST, class T_SECOND>
struct type_pair
{
    using first = T_FIRST;
    using second = T_SECOND;

    using _is_type_pair = std::true_type;
};

/**
 * Returns `std::true_type` if `T` is contains a nested type `_is_type_pair` that is an alias of `std::true_type`
 */
template<class T>
using is_type_pair = typename T::_is_type_pair;



} // namespace type_util