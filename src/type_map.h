//
// Created by PeterBurgess on 21/08/2023.
//


#pragma once


#include "type_map_element.h"
#include "unique_type_tuple.h"

#include <tuple>
#include <type_traits>


namespace type_util
{


template<class ... ELEMENT_LIST> requires std::conjunction<__is_type_map_element__<ELEMENT_LIST>...>::value
struct type_map
{

private:

    using _KEY_TYPE_TUPLE = unique_type_tuple<typename ELEMENT_LIST::key_type...>;
    using _ITEM_TYPE_TUPLE = std::tuple<typename ELEMENT_LIST::item_type...>;

public:

    /**
     * Returns index of given key
     */
    template<class KEY_TYPE>
    static constexpr std::size_t key_index = _KEY_TYPE_TUPLE::template get_type_index<KEY_TYPE>;

    /**
     * Get type associate with key
     */
    template<class KEY_TYPE>
    using at = typename std::tuple_element<key_index<KEY_TYPE>, _ITEM_TYPE_TUPLE>::type;

    /**
     * Convenience function that allows call sight to construct an instance of the type associated with the given key
     */
    template<class KEY_TYPE, class ... ARGS>
    constexpr static at<KEY_TYPE> make(ARGS ... args) { return at<KEY_TYPE>(args...); }
};


} // namespace type_util