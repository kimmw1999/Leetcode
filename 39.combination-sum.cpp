class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> output;
        vector<int> curr;
        backtracking(candidates, output, curr, 0, target);
        return output;
    }
private:
    void backtracking(vector<int> &candidates, vector<vector<int>> &output, vector<int> &curr, int i, int target) {
        if(target == 0) {
            output.push_back(curr);
            return;
        }
        else if(target < 0) {
            return;
        }
        if(i >= candidates.size()) {
            return;
        }
        else if(candidates[i] > target) {
            return;
        }

        else{
            curr.push_back(candidates[i]);
            backtracking(candidates, output, curr, i, target-candidates[i]);
            curr.pop_back();
            backtracking(candidates, output, curr, i+1, target);
        }
    }
};