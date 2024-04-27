/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        int prev = 0;
        int curr = 0;
        int next = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            next = max(prev + nums[i], curr);
            prev = curr;
            curr = next;
        }
        
        return curr;
        // int n = nums.size();
        // if(n == 0) {
        //     return 0;
        // }
        // else if(n == 1) {
        //     return nums[0];
        // }
        // else if(n==2) {
        //     return max(nums[0], nums[1]);
        // }
        // else if(n==3) {
        //     return max(nums[0] + nums[2] , nums[1]);
        // }
        // int first = nums[0]; // pick 0
        // int second = nums[1]; // pick 1
        // int third = nums[0] + nums[2]; // pick 1
        // int last;
        // for(int i = 3; i < n; i++) {
        //     last = max(max(first, second) + nums[i], third);
        //     first = second;
        //     second = third;
        //     third = last;
        // }
        // return last;
    }
};
// @lc code=end

