cmake_minimum_required(VERSION 3.22)


set(CMAKE_CXX_STANDARD 23)


add_library(
        type_util

        INTERFACE

        src/same_type_concept.h
        src/type_array.h
        src/type_map.h
        src/unique_type_concept.h
        src/unique_type_tuple.h
        src/unique_value_concept.h
        src/value_to_type_map.h
        src/value_to_type_map_element.h
)

target_include_directories(
        type_util

        INTERFACE

        ${CMAKE_CURRENT_SOURCE_DIR}/src
)
