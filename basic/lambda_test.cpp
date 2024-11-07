//
// Created by Younghusband on 2024/11/7.
//

#include <iostream>


using namespace std;
int main() {

    int x = 10;
    auto lamb1 = [=] () { std::cout << x << std::endl; };

    lamb1();

    int xx = 10;
    auto lamb2 = [&]() {xx = 20;};
    lamb2();
    cout << xx << endl;

    auto cmp = [] (const pair<int, int> p1, const pair<int, int> p2) {
        return p1.first > p2.first;
    };


}
