/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

// @lc code=start
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) {
            return false;
        }

        unordered_map<char, int> s_map, t_map;
        for(int i = 0; i < s.size(); i++) {
            s_map[s[i]]++;
            t_map[t[i]]++;
        }
        return (s_map == t_map);
    }
};
// @lc code=end

