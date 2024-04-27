class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> memo(nums.size());
        memo[nums.size()-1] = 0;
        for(int i = nums.size() - 2; i > -1; i--) {
            int min_num = INT_MAX;
            for(int j = 1; j <= nums[i]; j++) {
                if(i + j >= nums.size()) {
                    break;
                }
                min_num = min(min_num, memo[i+j]);
            }
            if(min_num == INT_MAX) {
                memo[i] = INT_MAX;
            }
            else{
                memo[i] = min_num + 1;
            }
        }
        return memo[0];
    }
};