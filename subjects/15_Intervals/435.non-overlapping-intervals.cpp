/*
 * @lc app=leetcode id=435 lang=cpp
 *
 * [435] Non-overlapping Intervals
 */

// @lc code=start
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<int> prev = intervals[0];
        int output = 0;
        for(int i = 1; i < intervals.size(); i++) {
            if(prev[1] > intervals[i][0]) {
                //overlap, delete one
                if(prev[1] > intervals[i][1]) {
                    prev = intervals[i];
                }
                output++;
            }
            else{
                prev = intervals[i];
            }
        }
        return output;
    }
};
// @lc code=end

