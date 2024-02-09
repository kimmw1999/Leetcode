/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
#include <string>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        int i = 0;
        int j = 0;
        unordered_set<char> chars;
        while(j < s.size()) {
            while(chars.find(s[j]) != chars.end()) {
                chars.erase(s[i]);
                i++;
            }
            maxLen = max(maxLen, j - i + 1);
            chars.insert(s[j]);
            j++;
        }
        return maxLen;
    }
};
// @lc code=end

