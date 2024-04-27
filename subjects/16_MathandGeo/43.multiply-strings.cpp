/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 */

// @lc code=start
class Solution {
public:
    string multiply(string num1, string num2) {
        string result(num1.size() + num2.size(), '0');
        for(int i = num1.size()-1; i > -1; i--) {
            for(int j = num2.size()-1; j > -1; j--) {
                int sum = (num1[i]-'0') * (num2[j]-'0') + (result[i + j + 1] - '0');
                result[i + j + 1] = sum % 10 + '0';
                result[i + j] += sum / 10;
            }
        }

        for(int i = 0; i < result.size(); i++) {
            if(result[i] != '0') {
                return result.substr(i);
            }
        }
        return "0";
    }
};
// @lc code=end

