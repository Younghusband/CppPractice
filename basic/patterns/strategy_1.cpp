//
// Created by Younghusband on 2024/12/9.
//


#include <iostream>

using namespace std;

class Discount {
public:
    virtual double calculateDiscount() = 0;
};


class Type1Discount : public Discount {
public:
    double calculateDiscount() {
        return 10;
    }
};

class Type2Discount : public Discount {
public:
    double calculateDiscount() override {
        return 15;
    }
};

class DiscountCalculator {
public:
    double calculateTotalDiscount(Discount* discount) {
        return discount->calculateDiscount();
    }
};

// int main() {
//     DiscountCalculator calculator;
//     Discount* type1 = new Type1Discount();
//
//     double discount1 = calculator.calculateTotalDiscount(type1);
//     cout << "Type 1 discount: " << discount1 << "%" << endl;
// }
