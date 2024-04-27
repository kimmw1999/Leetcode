/*
 * @lc app=leetcode id=746 lang=cpp
 *
 * [746] Min Cost Climbing Stairs
 */

// @lc code=start
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int first = 0;
        int second = 0;
        int third = 0;
        for(int i = 2; i < cost.size()+1; i++) {
            third = min(first + cost[i - 2], second + cost[i - 1]);
            first = second;
            second = third;
        }
        return third;
    }
};
// @lc code=end

