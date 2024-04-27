/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 */

// @lc code=start

class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') return 0; // Return 0 if string is empty or starts with '0'
        
        int n = s.size();
        int first = 1, second = 1; // Correct initialization for DP
        
        for (int i = 1; i < n; i++) {
            int current = 0;
            if (s[i] != '0') // Current digit is not '0', can stand alone
                current = second;
            
            int twoDigit = (s[i - 1] - '0') * 10 + (s[i] - '0'); // Convert two digits to an integer
            if (twoDigit >= 10 && twoDigit <= 26) // Check if the two-digit number is valid
                current += first;
            
            first = second; // Move the window
            second = current;
        }
        
        return second; // Return the total number of ways to decode
    }
};
// @lc code=end

