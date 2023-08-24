//
// Created by PeterBurgess on 21/08/2023.
//


#pragma once


#include "unique_type_concept.h"

#include <tuple>


namespace type_util
{


template<typename T, typename TUPLE>
struct _tuple_element_index_helper_t_;

template<typename T>
struct _tuple_element_index_helper_t_<T, std::tuple<>>
{
    static constexpr std::size_t value = 0;
};

template<typename T, typename... REMAINING_TYPE_LIST>
struct _tuple_element_index_helper_t_<T, std::tuple<T, REMAINING_TYPE_LIST...>>
{
    static constexpr std::size_t value = 0;
    using RemainingTyple = std::tuple<REMAINING_TYPE_LIST...>;
};

template<typename T, typename First, typename... REMAINING_TYPE_LIST>
struct _tuple_element_index_helper_t_<T, std::tuple<First, REMAINING_TYPE_LIST...>>
{
    using RemainingTyple = std::tuple<REMAINING_TYPE_LIST...>;
    static constexpr std::size_t value = 1 + _tuple_element_index_helper_t_<T, RemainingTyple>::value;
};

template<typename T, typename TUPLE>
struct _tuple_element_index_t_
{
    static constexpr std::size_t value = _tuple_element_index_helper_t_<T, TUPLE>::value;
};

template<typename T, typename TUPLE>
static constexpr std::size_t _tuple_element_index_v_ = _tuple_element_index_t_<T, TUPLE>::value;


template<class TYPE_TO_FIND, class TUPLE_TYPE>
static constexpr std::size_t get_tuple_element_index = _tuple_element_index_v_<TYPE_TO_FIND, TUPLE_TYPE>;


} // namespace type_util