class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        this->nums = nums;
        this->n = nums.size();
        vector<vector<int>> ans;
        vector<int> curr;
        backtracking(ans, curr, 0);
        return ans;
    }

private:
    vector<int> nums;
    int n;
    void backtracking(vector<vector<int>> &ans, vector<int> curr, int i) {
        if(i == n) {
            ans.push_back(curr);
            return;
        }

        curr.push_back(nums[i]);
        backtracking(ans, curr, i+1);
        curr.pop_back();
        backtracking(ans, curr, i+1);
    }
};