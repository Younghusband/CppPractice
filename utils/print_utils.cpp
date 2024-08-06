//
// Created by Younghusband on 2024/8/6.
//

#include "print_utils.h"
#include <string>

namespace print_utils {

    void print_array(vector<int> arr) {
        string result = "[";
        for(size_t i = 0; i < arr.size(); i++) {
            result += to_string(arr.at(i));
            if(i != arr.size() - 1) {
                result += ", ";
            }
        }
        result += "]\n";
        cout << result;
    }

}