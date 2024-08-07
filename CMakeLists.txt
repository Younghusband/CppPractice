cmake_minimum_required(VERSION 3.28)
project(CppPractice)

set(CMAKE_CXX_STANDARD 20)

add_executable(CppPractice main.cpp
        huawei/GetHexString.cpp
        huawei/Solution.h
        utils/sort_utils.cpp
        huawei/FanSort.h
        utils/sort_utils.h
        CodeTemplate.cpp
        huawei/Fib.cpp
        basic/string_test.cpp
        basic/array_test.cpp
        basic/vector_test.cpp
        leetcode/permutation.cpp
        leetcode/bubble_sort.cpp
        utils/print_utils.cpp
        utils/print_utils.h
        basic/map_test.cpp
        leetcode/two_sum.cpp
        basic/stack_test.cpp
        leetcode/group_anagrams.cpp
        basic/math_test.cpp
        huawei/Solution.cpp
)
