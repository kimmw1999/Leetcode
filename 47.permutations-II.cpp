class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        permutation(res, nums, 0, nums.size());
        return res;
    }
private:
    void permutation(vector<vector<int>> &res, vector<int> &nums, int start, int n) {
        if(start == n) {
            res.push_back(nums);
            return;
        }
        unordered_set<int> seen;
        for(int i = start; i < n; i++) {
            if(seen.find(nums[i]) == seen.end()) {
                seen.insert(nums[i]);
                swap(nums[start], nums[i]);
                permutation(res, nums, start+1, n);
                swap(nums[start], nums[i]);
            }
        }
    }
};