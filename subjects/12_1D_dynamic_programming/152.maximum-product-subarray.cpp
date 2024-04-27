/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */

// @lc code=start
#include <cmath>
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int result = nums[0];
        int minP = 1;
        int maxP = 1;
        for(int n : nums) {
            int temp = maxP * n;
            maxP = max(maxP * n, minP * n);
            maxP = max(maxP, n);
            minP = min(temp, minP * n);
            minP = min(minP, n);
            result = max(result, maxP);
        }
        return result;

    }
};
// @lc code=end

