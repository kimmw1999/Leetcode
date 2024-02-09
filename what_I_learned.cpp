#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <string>
#include <cctype>

//vector append:
void vector_append() {
    std::vector<int> a;
    a.push_back(3);
}

void hashmap_getValue() {
    std::unordered_map<int, int> map;
    
}

void string_add_append_to_string() {
    std::string a = "";
    a.append(std::to_string(5));
    a + "55";

    //substring
    a.substr(0, 2); //substr(startIdx, substring length);
    std::stoi("1");
}

void is_alphanumeric() {
    //need #include <cctype>
    std::string s = "abc  ";
    for(char ch : s) {
        std::cout << isalnum(ch); 
    }
}