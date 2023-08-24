//
// Created by PeterBurgess on 21/08/2023.
//


#pragma once


#include "type_map.h"

#include <tuple>


namespace type_util
{


template<class ... TYPE_LIST>
struct type_array
{

private:

    using _TYPE_LIST_TUPLE = std::tuple<TYPE_LIST...>;

public:

    template<std::size_t TYPE_INDEX>
    using at = typename std::tuple_element<TYPE_INDEX, _TYPE_LIST_TUPLE>::type;
};


} // namespace type_util
