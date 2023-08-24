//
// Created by PeterBurgess on 21/08/2023.
//


#pragma once


#include "type_map_element.h"
#include "unique_type_concept.h"
#include "unique_type_tuple.h"

#include <any>
#include <tuple>
#include <type_traits>


namespace type_util
{


template<class ... ELEMENT_LIST> requires std::conjunction<__is_type_map_element__<ELEMENT_LIST>...>::value
struct type_map
{

private:

    using _TYPE_MAP_KEY_TUPLE = unique_type_tuple<typename ELEMENT_LIST::key_type...>;
    using _TYPE_MAP_ITEM_TUPLE = std::tuple<typename ELEMENT_LIST::item_type...>;

public:

    template<class KEY_TYPE>
    static constexpr std::size_t key_index = _TYPE_MAP_KEY_TUPLE::template get_type_index<KEY_TYPE>;

    template<class KEY_TYPE>
    using at = typename std::tuple_element<key_index<KEY_TYPE>, _TYPE_MAP_ITEM_TUPLE>::type;
};


} // namespace type_util