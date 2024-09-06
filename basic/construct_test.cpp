//
// Created by Younghusband on 2024/8/31.
//

#include <string>
#include <iostream>

using namespace std;

class MyClass {

public:
    // 委托构造
    MyClass() : age(0), name("default") {
        cout << "call delegate-constructor..." << endl;
    }
    // 初始化列表方式
    MyClass(int age, string name) : age(age), name(name) {
        cout << "call constructor-with-params... " << endl;
    }
    MyClass(const MyClass& other) : age(other.age), name(other.name) {
        cout << "call copy-constructor..." << endl;
    }
    void display() const {
        cout << "name = " << this->name << " , age = " << this->age << endl;
    }
    void modify(int age, string name) {
        this->age = age;
        this->name = name;
    }

private:
    int age;
    string name;

};

// int main() {
//     MyClass obj1;
//     MyClass obj2(2, "fdn");
//     MyClass obj3(obj2);  // 复制对象2
//
//     obj3.modify(3, "fdnnnn");
//
//     obj1.display();
//     obj2.display();
//     obj3.display();
// }