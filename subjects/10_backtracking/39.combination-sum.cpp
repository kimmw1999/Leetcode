/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> curr;
        backtracking(candidates, result, curr, target, 0);
        return result;
    }
private:
    void backtracking(vector<int> &candidates, vector<vector<int>> &result, vector<int> &curr, int target, int i) {
        if(i >= candidates.size() || target < 0) {
            return;
        }

        if(target == 0){
            result.push_back(curr);
            return;
        }

        curr.push_back(candidates[i]);

        backtracking(candidates, result, curr, target - candidates[i], i);

        curr.pop_back();

        backtracking(candidates, result, curr, target, i+1);
    }
};
// @lc code=end

