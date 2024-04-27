/*
 * @lc app=leetcode id=973 lang=cpp
 *
 * [973] K Closest Points to Origin
 */

// @lc code=start
#include <queue>
#include <vector>
#include <cmath>
using namespace std;
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        //use double instead of float for more precision
        priority_queue<pair<double, vector<int>>, vector<pair<double, vector<int>>>, greater<pair<double, vector<int>>>> pq;
        for(int i = 0; i < points.size(); i++) {
            pq.push({sqrt((pow(points[i][0], 2) + pow(points[i][1],2))), points[i]});
        }
        vector<vector<int>> output;
            for(int i = 0; i < k; i++) {
            output.push_back(pq.top().second);
            pq.pop();
        }
        return output;
    }
};
// @lc code=end

