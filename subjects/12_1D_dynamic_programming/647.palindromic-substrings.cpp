/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 */

// @lc code=start
class Solution {
public:
    int countSubstrings(string s) {
        int result = 0;
        for(int i = 0; i < s.size()-1; i++) {
            result++;//itself is substring
            int l = i;
            int r = i;
            l--;
            r++;
            while(l > -1 && r < s.size() && s[l] == s[r]) {
                result++;
                l--;
                r++;
            }
            l = i;
            r = i+1;
            while(l > -1 && r < s.size() && s[l] == s[r]) {
                result++;
                l--;
                r++;
            }
        }
        return result+1;
    }
};
// @lc code=end

