//Date: 04/28/2024
//Time Complexity: O(N)
//Space Complexity: O(1)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int curr = 0;
        int p0 = 0; //pointer of rightmost 0 place
        int p2 = nums.size() - 1; //pointer of leftmost 2 place
        while(curr <= p2) {
            if(nums[curr] == 0) {
                swap(nums[curr], nums[p0]);
                curr++;
                p0++;
            }
            else if(nums[curr] == 1) {
                curr++;
            }
            else{
                swap(nums[curr], nums[p2]);
                p2--;
            }
        }
    }
};