//
// Created by PeterBurgess on 21/08/2023.
//


#pragma once


#include "same_type_concept.h"
#include "type_pair.h"
#include "type_value_pair.h"
#include "unique_type_tuple.h"
#include "unique_value_concept.h"
#include "value_type_pair.h"

#include <algorithm>
#include <array>
#include <tuple>
#include <type_traits>


namespace type_util
{


template<class ... ELEMENT_LIST>
struct type_map;


/**
 * Maps from one type to another type at compile time.
 *
 * Elements in the list each represent a single mapping from one type to another.
 *
 * @tparam ELEMENT_LIST : Each template argument must be of type `type_util::type_pair`,
 *                        each of which requires two types as it's template parameters.
 */
template<class ... ELEMENT_LIST> requires std::conjunction<is_type_pair<ELEMENT_LIST>...>::value
struct type_map<ELEMENT_LIST...>
{

private:

    using KEY_TYPE_TUPLE = unique_type_tuple<typename ELEMENT_LIST::first...>;
    using ITEM_TYPE_TUPLE = std::tuple<typename ELEMENT_LIST::second...>;

public:

    /**
     * Returns index of given key
     */
    template<class KEY_TYPE>
    static constexpr std::size_t key_index = KEY_TYPE_TUPLE::template get_type_index<KEY_TYPE>;

    /**
     * Get type associate with key
     */
    template<class KEY_TYPE>
    using at = typename std::tuple_element<key_index<KEY_TYPE>, ITEM_TYPE_TUPLE>::type;

//    /**
//     * TODO: `internal compiler error: Segmentation fault`
//     *
//     * Convenience function that allows call sight to construct an instance of the type associated with the given key
//     */
//    template<class KEY_TYPE, class ... ARGS>
//    constexpr static at<KEY_TYPE> make(ARGS ... args) { return at<KEY_TYPE>(args...); }
};


/**
 * Maps from an integral or enum value to a type at compile time.
 *
 * Elements in the list each represent a single mapping a value to a type.
 *
 * Key values within a single `type_map` instance must be of the same type.
 *
 * @tparam ELEMENT_LIST : Each template argument must be of type `type_util::value_type_pair`,
 *                        each of which requires an integral or enum value and a type as it's
 *                        template parameters.
 */
template<class ... ELEMENT_LIST> requires std::conjunction<is_value_type_pair<ELEMENT_LIST>...>::value
                                       && are_same_types<decltype(ELEMENT_LIST::first)...>
                                       && are_unique_values<ELEMENT_LIST::first...>
struct type_map<ELEMENT_LIST...>
{

private:

    static constexpr std::array _key_value_array{ ELEMENT_LIST::first... };
    using ITEM_TYPE_TUPLE = std::tuple<typename ELEMENT_LIST::second...>;

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
    using at = typename std::tuple_element<key_index<KEY_VALUE>, ITEM_TYPE_TUPLE>::type;
};


template<class ... ELEMENT_LIST> requires std::conjunction<is_type_value_pair<ELEMENT_LIST>...>::value
                                          && are_same_types<decltype(ELEMENT_LIST::second)...>
struct type_map<ELEMENT_LIST...>
{

private:

    using KEY_TYPE_TUPLE = unique_type_tuple<typename ELEMENT_LIST::first...>;
    static constexpr std::array _item_value_array{ ELEMENT_LIST::second... };

public:

    /**
     * Returns index of given key
     */
    template<class KEY_TYPE>
    static constexpr std::size_t key_index = KEY_TYPE_TUPLE::template get_type_index<KEY_TYPE>;

    /**
     * Get value associate with key
     */
    template<class KEY_TYPE>
    static constexpr auto at = _item_value_array.at(key_index<KEY_TYPE>);
};


} // namespace type_util