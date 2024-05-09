class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> curr;
        backtracking(ans, curr, nums, n, 0);
        return ans;
    }

    void backtracking(vector<vector<int>> &ans, vector<int> &curr, vector<int>& nums, int n, int i) {
        if(i == n) {
            ans.push_back(curr);
            return;
        }
        curr.push_back(nums[i]);
        backtracking(ans, curr, nums, n, i+1);
        int j = i+1;
        while(j < n && nums[i] == nums[j]) {
            j++;
        }
        curr.pop_back();
        backtracking(ans, curr, nums, n, j);
        return;
    }
};