//
// Created by Younghusband on 2024/9/13.
//


// #include <iostream>
// #include <string>
// #include <regex>
//
//
// using namespace std;

// int main() {
//
//     // usage of regex_match
//     string email = "example@test.com";
//     regex email_regex(R"((\w+)(\.\w+)*@(\w+)(\.\w+)+)");
//     if(regex_match(email, email_regex)) {
//         cout << "valid email address." << endl;
//     } else {
//         cout << "invalid email address." << endl;
//     }
//
//     // usage of sregex_iterator
//     string withDigit = "There are 2 apples and 3 oranges.";
//     regex digit_regex(R"(\d+)");
//     auto digits_begin = sregex_iterator(withDigit.begin(), withDigit.end(), digit_regex);
//     auto digits_end = sregex_iterator();
//     for(auto it = digits_begin; it != digits_end; ++it) {
//         cout << "Found number:" << it->str() << std::endl;
//     }
//
//     // usage of regex_replace
//     string phone_text = "My phone number is 123-456-7890.";
//     regex phone_regex(R"(\d{3}-\d{3}-\d{4})");
//     string new_text = regex_replace(phone_text, phone_regex, "XXX-XXX-XXXX");
//     cout << new_text << endl;
//
//     // usage of multi conditions
//     regex multi("cat|dog");
//     string include_dog = "ssdfa dddDDD xedog @#@";
//     string replace_res = regex_replace(include_dog, multi, "FengDanni");
//
//     cout << replace_res << endl;
//
//     // usage of regex_search
//     string case_text = "Hello world!";
//     regex ignore_case("hello", regex_constants::icase);
//     if(regex_search(case_text, ignore_case)) {
//         cout << "Matched (regex, case insensitive)!" << endl;
//     } else {
//         cout << "No match." << endl;
//     }
//
// }