/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 */

// @lc code=start
#include <vector>
using namespace std;

//leetcode solution
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<int> curr;
        vector<vector<int>> result;
        
        dfs(nums, 0, curr, result);
        return result;
    }
private:
    void dfs(vector<int>& nums, int start, vector<int>& curr, vector<vector<int>>& result) {
        result.push_back(curr);
        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1]) {
                continue;
            }
            curr.push_back(nums[i]);
            dfs(nums, i + 1, curr, result);
            curr.pop_back();
        }
    }
};
// class Solution {
// public:
//     vector<vector<int>> subsetsWithDup(vector<int>& nums) {
//         vector<vector<int>> result;
//         sort(nums.begin(), nums.end());
//         vector<int> curr;
//         backtracking(result, curr, nums, 0);
//         return result;
//     }

// private:
//     void backtracking(vector<vector<int>> &result, vector<int> &curr, vector<int> &nums, int i) {
//         if(i >= nums.size()){
//             result.push_back(curr);
//             return;
//         }
//         curr.push_back(nums[i]);
//         backtracking(result, curr, nums, i+1);
//         curr.pop_back();
//         int j = i;
//         while(j < nums.size() && nums[i] == nums[j]) {
//             j++;
//         }
//         backtracking(result, curr, nums, j);
//     }
// };
// @lc code=end

