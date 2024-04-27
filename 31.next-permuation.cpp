class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int piv = nums.size() - 2;
        while(piv > -1) {
            if(nums[piv] >= nums[piv+1]) {
                piv--;
            }
            else{
                break;
            }
        }

        if(piv == -1) {
            int l = 0;
            int r = nums.size() - 1;
            while(l < r) {
                swap(nums[l], nums[r]);
                l++;
                r--;
            }
            return;
        }

        int j = nums.size()-1;
        while(piv < j && nums[piv] >= nums[j]) {
            j--;
        }
        swap(nums[piv],nums[j]);

        int l = piv+1;
        int r = nums.size() - 1;
        while(l < r) {
            swap(nums[l], nums[r]);
            l++;
            r--;
        }
        return;
    }
};