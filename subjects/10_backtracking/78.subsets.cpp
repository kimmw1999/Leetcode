/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> curr;
        backtracking(result, nums, curr, 0);
        return result;
    }

private:
    void backtracking(vector<vector<int>> &result, vector<int>& nums, vector<int> &curr, int i) {
        if(i >= nums.size()) {
            result.push_back(curr);
            return;
        }
        
        curr.push_back(nums[i]);
        backtracking(result, nums, curr, i+1);
        curr.pop_back();
        backtracking(result, nums, curr, i+1);
    }
};
// @lc code=end

