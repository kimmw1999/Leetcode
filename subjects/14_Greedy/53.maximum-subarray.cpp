/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr = nums[0];
        int result = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            curr = max(curr + nums[i], nums[i]);
            result = max(result, curr);
        }
        
        return result;
    }
};
// @lc code=end

