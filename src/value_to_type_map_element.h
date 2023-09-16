//
// Created by PeterBurgess on 21/08/2023.
//


#pragma once


#include <type_traits>


namespace type_util
{


/**
 * Returns `std::true_type` if `T` is contains a nested type `__IS_VALUE_TO_TYPE_MAP_ELEMENT__` that is an alias of `std::true_type`
 */
template<class T>
using __is_value_to_type_map_element__ = std::is_same<typename T::__IS_VALUE_TO_TYPE_MAP_ELEMENT__::type, std::true_type>;


template<auto KEY_VALUE, class ITEM_TYPE>
struct value_to_type_map_element
{
    static constexpr auto key_value = KEY_VALUE;
    using item_type = ITEM_TYPE;

    using __IS_VALUE_TO_TYPE_MAP_ELEMENT__ = std::true_type;
};


} // namespace type_util