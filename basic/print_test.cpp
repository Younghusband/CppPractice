//
// Created by Younghusband on 2024/11/13.
//


#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

template <typename T>
string vector2String(const vector<T>& vec) {
    ostringstream oss;
    oss << "[";
    for(size_t i = 0; i < vec.size(); ++i) {
        oss << vec[i];
        if(i != vec.size() - 1) {
            oss << ", ";
        }
    }
    oss << "]";
    return oss.str();
} // oss更适合只读，也更快


struct Person {
    std::string name;
    int age;

    // Overload operator<< to print struct
    friend std::ostream& operator<<(std::ostream& os, const Person& p) {
        os << "{" << p.name << ", " << p.age << "}";
        return os;
    }
};


// int main() {
//
//     vector<Person> people = { {"Alice", 30}, {"Bob", 25}, {"Charlie", 35} };
//     cout << vector2String(people) << endl;
//
// }