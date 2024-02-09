/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:

    //solution from neetcode.io - uses two pointers.
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> output;
        int n = nums.size();
        for(int i = 0; i < n-2; i++) {
            if(i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            int j = i+1;
            int k = n-1;
            int sum;
            while(j < k) {
                sum = nums[i] + nums[j] + nums[k];
                if(sum == 0) {
                    output.push_back({nums[i], nums[j], nums[k]});
                    int new_j = j;
                    int new_k = k;
                    while(nums[new_j] == nums[j] && new_j < k) {
                        new_j++;
                    }
                    j = new_j;
                    while(nums[new_k] == nums[k] && new_k > j) {
                        new_k--;
                    }
                    k = new_k;
                }
                else if(sum < 0) {
                    j++;
                }
                else{
                    k--;
                }
            }
        }
        return output;
    }
};
// @lc code=end
