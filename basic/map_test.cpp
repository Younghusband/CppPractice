// #include <iostream>
// #include <unordered_map>
//
//
// using namespace std;
//
// int main() {
//
//     // unordered_map<int, string> map = {
//     //     {1, "one"},
//     //     {2, "two"},
//     //     {3, "three"}
//     // };
//     unordered_map<int, string> map {
//         {1, "one"},
//         {2, "two"},
//         {3, "three"}
//     }; // both right
//
//     int cantFind = 4;
//     if(map.count(cantFind) == 0) {
//         cout << "map 中 key = " << cantFind << " 的值为 "<< map[4] << endl; // 会打印空白
//     }
//
//     cout << map[1] << endl;
//     map[4] = "Yangfan";
//     map.insert({5, "ByInsert"});
//     cout << map[4] << endl;
//
//     for(const auto& pair : map) {
//         cout << pair.first << " => " << pair.second << endl;
//     }
//
//     map.erase(3);
//     cout << "=============================================\n";
//
//     for(const auto& pair : map) {
//         cout << pair.first << " => " << pair.second << endl;
//     }
//
//     int key = 1;
//     if(map.find(key) != map.end()) {
//         cout << "key [" << key << "] exists with value: " << map.find(key)->second << std::endl;
//     } else {
//         cout << "key [" << key << "] does done exist." << std::endl;
//     }
//
//     cout << map.contains(99); // after 20
//
// }