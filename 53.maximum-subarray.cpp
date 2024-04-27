class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if(sum < 0) {
                sum = 0;
                res = max(res, nums[i]);
            } 
            else{
                res = max(res, sum);
            }
        }
        return res;
    }
};