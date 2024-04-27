/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */

// @lc code=start
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        unordered_set<int> dp;
        dp.insert(0);
        int target = 0;
        for(int i = 0; i < nums.size(); i++) {
            target += nums[i];
        }
        if(target%2 == 1 ){
            return false;
        }
        target = target / 2;
        for(int i = 0; i < nums.size(); i++) {
            unordered_set<int> nextDp;
            for(auto it = dp.begin(); it != dp.end(); it++) {
                if(*it + nums[i] == target) {
                    return true;
                }
                if(*it == target) {
                    return true;
                }
                nextDp.insert(*it+nums[i]);
                nextDp.insert(*it);
            }
            dp = nextDp;
        }
        return false;
    }
};
// @lc code=end

