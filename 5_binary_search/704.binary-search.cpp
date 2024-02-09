/*
 * @lc app=leetcode id=704 lang=cpp
 *
 * [704] Binary Search
 */

// @lc code=start
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        //neetcode solution
        int low = 0;
        int high = nums.size() - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] < target) {
                low = mid + 1;
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else {
                return mid;
            }
        }
        
        return -1;
        // /*
        // //initialize int i=0, j=nums.size()(i, j for array specification)
        // //find pivot = i+j/2
        // //if nums[pivot] > target, j = pivot, repeat
        // //if nums[pivot] < target, i = pivot, repeat
        // //if nums[pivot] == target, return pivot
        // //if i == j && nums[pivot] != target, return -1
        // */
        
        // int i = 0; 
        // int j = nums.size()-1;
        // int pivot;
        // while (i < j) {
        //     pivot = (i + j) / 2;
        //     cout << i << " " << j << " " << pivot << endl;
        //     if(nums[pivot] > target) {
        //         j = pivot;
        //     }
        //     else if(nums[pivot] < target) {
        //         i = pivot;
        //     }
        //     else{
        //         return pivot;
        //     }
        //     if(j == i+1){
        //         if(target == nums[i]) {
        //             return i;
        //         }
        //         else if(target == nums[j]) {
        //             return j;
        //         }
        //         else{
        //             return -1;
        //         }
        //     }
        // }
        // if(i == j && nums[i] ==target) {
        //     return i;
        // }
        // return -1;
    }
};
// @lc code=end
int main() {
    Solution sol;
    vector<int> nums = {-1,0,3,5,9,12};
    int target = 2;
    sol.search(nums, target);
}
