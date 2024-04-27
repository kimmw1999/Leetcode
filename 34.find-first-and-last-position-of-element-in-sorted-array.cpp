class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while(l <= r) {
            int m = (l + r) / 2;
            if(nums[m] == target) {
                l = m;
                r = m;
                while(l-1 >= 0 && nums[l-1] == target) {
                    l--;
                }
                while(r+1 < nums.size() && nums[r+1] == target) {
                    r++;
                }
                return {l, r};
            }

            if(nums[m] > target) {
                r = m-1;
            }

            else{
                l = m+1;
            }
        }
        return {-1, -1};
    }
};