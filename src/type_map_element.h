//
// Created by PeterBurgess on 21/08/2023.
//


#pragma once


#include "unique_type_concept.h"
#include "unique_type_tuple.h"

#include <any>
#include <tuple>
#include <type_traits>


namespace type_util
{


/**
 * Returns `std::true_type` if `T` is contains a nested type `__IS_TYPE_MAP_ELEMENT__` that is an alias of `std::true_type`
 *
 * This will allow for other types of elements to be processed by `type_map` in the future if needed
 */
template<class T>
using __is_type_map_element__ = std::is_same<typename T::__IS_TYPE_MAP_ELEMENT__::type, std::true_type>;


template<class KEY_TYPE, class ITEM_TYPE>
struct type_map_element
{
    using key_type = KEY_TYPE;
    using item_type = ITEM_TYPE;

    using __IS_TYPE_MAP_ELEMENT__ = std::true_type;
};


} // namespace type_util