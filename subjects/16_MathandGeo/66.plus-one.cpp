/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 */

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // int carry = 0;
        // vector<int> result;
        // if(digits[digits.size()-1] == 9) {
        //     result.push_back(0);
        //     carry = 1;
        // }
        // else{
        //     result.push_back(digits[digits.size()-1] + 1);
        // }

        // for(int i = digits.size()-2; i > -1; i--) {
        //     if(carry == 1) {
        //         if(digits[i] == 9) {
        //             result.push_back(0);
        //         }
        //         else{
        //             carry = 0;
        //             result.push_back(digits[i] + 1);
        //         }
        //     } 
        //     else{
        //         result.push_back(digits[i]);
        //     }
        // }
        // if(carry == 1) {
        //     result.push_back(1);
        // }
        // reverse(result.begin(), result.end());
        // return result;

        for(int i = digits.size() - 1; i > -1; i--) {
            if(digits[i] != 9) {
                digits[i] += 1;
                return digits;
            }

            digits[i] = 0;
        }

        digits[0] = 1;
        digits.push_back(0);
        return digits;
    }
};
// @lc code=end

