/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> twoSum_neetcode(vector<int>& nums, int target) {
            int n = nums.size();
            unordered_map<int, int> mp; // val -> index

            for (int i = 0; i < n; i++) {
                int complement = target - nums[i];
                if (mp.find(complement) != mp.end()) {
                    return {mp[complement], i};
                }
                mp.insert({nums[i], i});
            }
            return {};
    }
    
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, vector<int>> hashmap;
        for(int i = 0; i < nums.size(); i++) {
            hashmap[nums[i]].push_back(i);
        }

        for(int num:nums) {
            int new_target = target - num;
            if(new_target == num) {
                if(hashmap[new_target].size() > 1) {
                    return {hashmap[new_target][0], hashmap[new_target][1]};
                }
            }  
            else{
                if(hashmap[new_target].size() > 0) {
                    return {hashmap[new_target][0], hashmap[num][0]};
                }
            }
        }

        return {0, 0};
    }
};
// @lc code=end

