//
// Created by PeterBurgess on 21/08/2023.
//


#pragma once


#include <tuple>


namespace type_util
{


template<class ... TYPE_LIST>
struct type_array
{

private:

    using _TYPE_LIST_TUPLE = std::tuple<TYPE_LIST...>;

public:

    /**
     * Get type at index
     */
    template<std::size_t INDEX>
    using at = typename std::tuple_element<INDEX, _TYPE_LIST_TUPLE>::type;

    /**
     * Convenience function that allows call sight to construct an instance of the type associated with the given key
     */
    template<auto INDEX, class ... ARGS>
    constexpr static auto make(ARGS ... args) -> at<INDEX> { return at<INDEX>(args...); }
};


} // namespace type_util
