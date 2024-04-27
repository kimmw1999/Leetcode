/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) {
            return {};
        }
        unordered_map<char, vector<char>> map;
        map['2']={'a','b','c'};
        map['3']={'d','e','f'};
        map['4']={'g','h','i'};
        map['5']={'j','k','l'};
        map['6']={'m','n','o'};
        map['7']={'p','q','r', 's'};
        map['8']={'t','u','v'};
        map['9']={'w','x','y', 'z'};
        
        vector<string> result;
        vector<char> curr;
        backtracking(digits, map, 0, result, curr);
        return result;
    }
private:
    void backtracking(string &digits, unordered_map<char, vector<char>> &map, int i, vector<string> &result, vector<char> curr) {
        if(i == digits.size()) {
            string current(curr.begin(), curr.end());
            result.push_back(current);
            return;
        }

        for(char ch : map[digits[i]]) {
            curr.push_back(ch);
            backtracking(digits, map, i+1, result, curr);
            curr.pop_back();
        }
    }
};
// @lc code=end

