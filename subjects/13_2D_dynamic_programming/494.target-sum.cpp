/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 */

// @lc code=start
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        return backtrack(nums, target, 0, 0);
    }
private:
    map<pair<int, int>, int> dp;
    int backtrack(vector<int> &nums, int target, int i, int total) {
        if(i == nums.size()) {
            return total == target ? 1 : 0;
        }
        if(dp.find({i, total}) != dp.end()) {
            return dp[{i, total}];
        }
        dp[{i, total}] = backtrack(nums, target, i+1, total + nums[i]) + backtrack(nums, target, i + 1, total - nums[i]);
        return dp[{i, total}];
    }
};
// @lc code=end

