//
// Created by PeterBurgess on 21/08/2023.
//


#pragma once


#include "same_type_concept.h"
#include "value_to_type_map_element.h"
#include "unique_value_concept.h"

#include <algorithm>
#include <tuple>
#include <type_traits>


namespace type_util
{


template<class ... ELEMENT_LIST> requires std::conjunction<__is_value_to_type_map_element__<ELEMENT_LIST>...>::value
                                       && are_same_types<decltype(ELEMENT_LIST::key_value)...>
                                       && are_unique_values<ELEMENT_LIST::key_value...>
struct value_to_type_map
{

private:

    static constexpr std::array _key_value_array{ ELEMENT_LIST::key_value... };
    using _ITEM_TYPE_TUPLE = std::tuple<typename ELEMENT_LIST::item_type...>;

public:

    /**
     * Returns index of given key
     */
    template<auto KEY_VALUE>
    static constexpr std::size_t key_index = std::distance(_key_value_array.begin(), std::find(_key_value_array.begin(), _key_value_array.end(), KEY_VALUE));

    /**
     * Get type associate with key
     */
    template<auto KEY_VALUE>
    using at = typename std::tuple_element<key_index<KEY_VALUE>, _ITEM_TYPE_TUPLE>::type;

    /**
     * Convenience function that allows call sight to construct an instance of the type associated with the given key
     */
    template<auto KEY_VALUE, class ... ARGS>
    constexpr static at<KEY_VALUE> make(ARGS ... args) { return at<KEY_VALUE>(args...); }
};


} // namespace type_util