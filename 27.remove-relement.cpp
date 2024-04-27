class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int res = 0;
        for(int j = 0; j < nums.size(); j++) {
            if(nums[j] != val) {
                nums[res] = nums[j];
                res++;
            }
        }
        return res;
    }
};