/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        backtracking(nums, 0, result);
        return result;
    }
private:
    void backtracking(vector<int> &nums, int start, vector<vector<int>> &result) {
        if(start == nums.size()){
            result.push_back(nums);
            return;
        }

        for(int i = start; i < nums.size(); i++) {
            swap(nums[i], nums[start]);
            backtracking(nums, start+1, result);
            swap(nums[i], nums[start]);
        }
    }
};
// @lc code=end

