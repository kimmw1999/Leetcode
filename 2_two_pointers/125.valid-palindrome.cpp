/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

// @lc code=start
#include <string>
#include <cctype>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.size() - 1;
        while (start < end) {
            while(!isalnum(s[start]) && start < end) {
                start++;
            }
            while(!isalnum(s[end]) && start < end) {
                end--;
            }

            if(tolower(s[start])!= tolower(s[end])) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};
// @lc code=end

