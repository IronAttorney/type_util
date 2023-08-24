//
// Created by PeterBurgess on 21/08/2023.
//


#pragma once


#include "tuple_element_index.h"
#include "unique_type_concept.h"

#include <tuple>


namespace type_util
{


/**
 * This class is derived from `std::tuple`
 *
 * Within this library this is only used for compile time type deduction,
 * but it can ofcourse be used as a container is meant to be used as well.
 *
 * It's functionally identical to `std::tuple` except all template types
 * must be unique and it has a new static function `get_type_index<>`.
 *
 * Example usage:
 *
 * `size_t double_type_index = unique_type_tuple<int, bool, double>::get_type_index<double>;`
 */
template <typename... TYPE_LIST> requires are_unique_types<TYPE_LIST...>
struct unique_type_tuple : public std::tuple<TYPE_LIST...>
{
    template<class TYPE_TO_FIND>
    static constexpr std::size_t get_type_index = _tuple_element_index_v_<TYPE_TO_FIND, std::tuple<TYPE_LIST...>>;
};


} // namespace type_util