class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> curr;
        vector<vector<int>> result;
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, result, curr, 0, target);
        return result;
    }
private:
    void backtracking(vector<int> &candidates, vector<vector<int>> &result, vector<int> &curr, int i, int target) {

        if(target == 0) {
            result.push_back(curr);
            return;
        }
        else if(target < 0 || i == candidates.size()) {
            return;
        }

        curr.push_back(candidates[i]);
        backtracking(candidates, result, curr, i+1, target - candidates[i]);
        curr.pop_back();
        int j = i;
        while(j < candidates.size() && candidates[i] == candidates[j]) {
            j++;
        }
        backtracking(candidates, result, curr, j, target);

    }
};