/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        int result = 0;
        int l = 0;
        int r = 0;
        while(r < nums.size() - 1) {
            int far = 0;
            for(int k = l ; k < r+1; k++) {
                far = max(far, k+nums[k]);
            }
            l = r+1;
            r = far;
            result+= 1;
        }
        return result;
    }
};
// @lc code=end

