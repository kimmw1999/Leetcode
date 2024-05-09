class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int pivot = 1;
        int n = nums.size();
        while(pivot < nums.size() && nums[pivot-1] <= nums[pivot]) {
            pivot++;
        }

        int l = 0;
        int r = nums.size() - 1;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(nums[(pivot + mid) % n] == target) {
                return true;
            }
            if(nums[(pivot + mid) % n] > target) {
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return false;
    }
};