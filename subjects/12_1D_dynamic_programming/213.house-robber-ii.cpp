/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        //without start
        int prev = 0;
        int curr = 0;
        int next = 0;
        for (int i = 1; i < nums.size(); i++) {
            next = max(prev + nums[i], curr);
            prev = curr;
            curr = next;
        }
        int withstart = curr;

        curr = nums[0];
        prev = curr;
        next = curr;
        for (int i = 2; i < nums.size() - 1; i++) {
            next = max(prev + nums[i], curr);
            prev = curr;
            curr = next;
        }
        return max(curr, withstart);
    }
};
// @lc code=end

