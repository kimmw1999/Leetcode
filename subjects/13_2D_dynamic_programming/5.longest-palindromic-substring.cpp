/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n == 0){
            return "";
        }
        if(n == 1) {
            return s;
        }
        string result = "";
        int res_len = 0;
        for(int i = 0; i < n-1; i++) {
            int l = i;
            int r = i;
            while(l >= 0 && r < n && s[l] == s[r]) {
                if(r - l + 1 > res_len) {
                    result = s.substr(l, r-l+1);
                    res_len = r-l+1;
                }
                r++;
                l--;
            }

            l = i;
            r = i+1;
            while(l >= 0 && r < n && s[l] == s[r]) {
                if(r - l + 1 > res_len) {
                    result = s.substr(l, r-l+1);
                    res_len = r-l+1;
                }
                r++;
                l--;
            }
        }
        return result;
    }
};
// @lc code=end

