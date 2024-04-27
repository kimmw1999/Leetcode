/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, result, curr, 0);
        return result;
    }
private:
    void backtracking(vector<int> &candidates, int target, vector<vector<int>> &result, vector<int> &curr, int start) {
        if(target == 0) {
            result.push_back(curr);
            return;
        }
        if(start == candidates.size() || target < 0) {
            return;
        }

        for(int i = start; i < candidates.size(); i++) {
            if(i > start && candidates[i] == candidates[i-1]) {
                continue;
            }
            curr.push_back(candidates[i]);
            backtracking(candidates, target - candidates[i], result, curr, i+1);
            curr.pop_back();
        }

    }
};
// @lc code=end

