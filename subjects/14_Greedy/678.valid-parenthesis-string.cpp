/*
 * @lc app=leetcode id=678 lang=cpp
 *
 * [678] Valid Parenthesis String
 */

// @lc code=start
class Solution {
public:
    bool checkValidString(string s) {
        int l_min = 0;
        int l_max = 0;
        for(char ch : s) {
            if(ch == '(') {
                l_min++;
                l_max++;
            }
            else if(ch == ')') {
                l_min--;
                l_max--;
            }
            else{
                l_min--;
                l_max++;
            }
            if(l_min < 0) {
                l_min = 0;
            }
            if(l_max < 0) {
                return false;
            }
        }
        return l_min == 0;
    }
};
// @lc code=end

