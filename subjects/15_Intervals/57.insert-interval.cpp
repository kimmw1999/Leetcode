/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int newStart = newInterval[0];
        int newEnd = newInterval[1];
        int n = intervals.size();
        for (int i = 0; i < n; i++) {
            // Case 1: Non overlapping interval
            // If new interval is before the current interval
            if (intervals[i][0] > newEnd) {
                ans.push_back(newInterval);
                copy(intervals.begin() + i, intervals.end(), back_inserter(ans));
                return ans;
            }
            // If new interval is after the current interval
            else if (intervals[i][1] < newStart) {
                ans.push_back(intervals[i]);
            }
            // Case 2: Overlapping interval
            else {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }
        ans.push_back(newInterval);
        return ans;
    }
};

// class Solution {
// public:
//     vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
//         vector<vector<int>> output;
//         int i = 0;
//         bool inserted = false;
//         if(!intervals.empty() && intervals[0][0] > newInterval[1]) {
//             output.push_back(newInterval);
//             for(int i = 0; i < intervals.size(); i++) {
//                 output.push_back(intervals[i]);
//             }
//             return output;
//         }

//         while(i < intervals.size()) {
//             if(intervals[i][1] < newInterval[0]) {
//                 output.push_back(intervals[i]);
//                 i++;
//             }
//             else if(intervals[i][0] > newInterval[1]) {
//                 if(!inserted) {
//                     output.push_back(newInterval);
//                     inserted = true;
//                 }
//                 output.push_back(intervals[i]); 
//                 i++;
//             }
//             else{
//                 inserted = true;
//                 int start = min(intervals[i][0], newInterval[0]);
//                 while(intervals[i][1] < newInterval[1] ) {
//                     i++;
//                     if(i == intervals.size()) {
//                         output.push_back({start, newInterval[1]});
//                         return output;
//                     }
//                 }
//                 if(intervals[i][0] > newInterval[1]) {
//                     i--;
//                 }
//                 int end = max(intervals[i][1], newInterval[1]);
//                 output.push_back({start, end});
//                 i++;
//             }
//         }
//         if(!inserted) {
//             output.push_back(newInterval);
//         }
//         return output;
//     }
// };
// @lc code=end

