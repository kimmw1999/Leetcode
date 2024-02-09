/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        //neetcode solution
        int res = nums[0];
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r)
        {
            if (nums[l] < nums[r])
            {
                res = min(res, nums[l]);
                break;
            }
            int mid = l + (r - l) / 2;
            res = min(res, nums[mid]);

            if (nums[mid] >= nums[l]) // mid present in left sorted array
            {
                l = mid + 1; // try to move closer to right sorted array
            }
            else
            {
                r = mid - 1;
            }
        }

        return res;

        //my solution
        // int i = 0;
        // int j = nums.size()-1;
        // while(i < j) {
        //     int m = (i + j) / 2;
        //     if(nums[i] < nums[j]) {
        //         //no rotation
        //         return nums[i];
        //     }

        //     if(m == i || m == j) {
        //         int min_num = nums[i];
        //         min_num = min(min_num, nums[i]);
        //         return min(min_num, nums[j]);
        //     }

        //     //there's rotation somewhere(nums[i] > nums[j])
        //     if(nums[i] > nums[m]) {
        //         //rotation somewhere around i~m
        //         j = m;
        //     }
        //     else{
        //         //rotation around m~j
        //         i = m;
        //     }

        // }
        // return nums[i];
    }
};
// @lc code=end

