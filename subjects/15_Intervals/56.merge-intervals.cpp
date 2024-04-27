/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> output;
        sort(intervals.begin(), intervals.end());
        vector<int> curInterval = intervals[0];
        for(int i = 0; i < intervals.size(); i++) {
            if(curInterval[0] <= intervals[i][0] && curInterval[1] >= intervals[i][0]) {
                curInterval[0] = min(curInterval[0], intervals[i][0]);
                curInterval[1] = max(curInterval[1], intervals[i][1]);
            }
            else{
                output.push_back(curInterval);
                curInterval = intervals[i];
            }
        }
        if(!(!output.empty() && curInterval == output.back())) {
            output.push_back(curInterval);
        }
        return output;
    }
};
// @lc code=end

