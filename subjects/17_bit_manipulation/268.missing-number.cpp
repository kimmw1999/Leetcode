class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int result = n;
        for (int i = 0; i < n; i++) {
            result ^= i ^ nums[i];
        }
        return result;
        // int count = 0;
        // int n = nums.size();
        // if(n == 1) {
        //     if(nums[0] == 0) {
        //         return 1;
        //     }
        //     return 0;
        // }
        // int mtp_2 = 1;
        // while(mtp_2 <= n) {
        //     mtp_2 *= 2;
        // }
        // for(int i = 0; i < n; i++) {
        //     count ^= nums[i];
        // }
        // for(int i = n+1; i < mtp_2; i++) {
        //     count ^= i;
        // }
        // return count;
    }
};