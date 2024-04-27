class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        permutation(res, nums, 0);
        return res;
    }
private:
    void permutation(vector<vector<int>> &res, vector<int> &nums, int i) {
        if(i == nums.size()) {
            res.push_back(nums);
            return;
        }

        for(int j = i; j < nums.size(); j++) {
            swap(nums[i], nums[j]);
            permutation(res, nums, i+1);
            swap(nums[i], nums[j]);
        }
    }
};