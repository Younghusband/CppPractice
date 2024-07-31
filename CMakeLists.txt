cmake_minimum_required(VERSION 3.28)
project(CppPractice)

set(CMAKE_CXX_STANDARD 20)

add_executable(CppPractice main.cpp
        GetHexString.cpp
        huawei/Solution.h
        sort_test.cpp
        huawei/FanSort.h
)
