/*
 * @lc app=leetcode id=134 lang=cpp
 *
 * [134] Gas Station
 */

// @lc code=start
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> diff(gas.size());
        int sum = 0;
        for(int i = 0; i < gas.size(); i++) {
            diff[i] = gas[i] - cost[i];
            sum += diff[i];
        }
        if(sum < 0) {
            return -1;
        }
        int total = 0;
        int idx = 0;
        for(int i = 0; i < diff.size(); i++) {
            total += diff[i];
            if(total < 0) {
                total = 0;
                idx = i+1;
            }
        }
        return idx;
    }
};
// @lc code=end

