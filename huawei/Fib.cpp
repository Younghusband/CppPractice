//
// Created by Younghusband on 2024/8/2.
//

#include "Solution.h"

using namespace std;

int Solution::fib(int n) {
    if(n < 3) return 1;
    auto p1 = fib(n - 1);
    auto p2 = fib(n - 2);
    return p1 + p2;
}

