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
        basic/vector_playground.cpp
        basic/map_playground.cpp
        basic/queue_playground.cpp
        basic/bar.cpp
        basic/bar.h
        basic/basic_test.cpp
)
