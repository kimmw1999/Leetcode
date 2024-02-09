/*
 * @lc app=leetcode id=853 lang=cpp
 *
 * [853] Car Fleet
 */

// @lc code=start
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;
        stack<float> st;
        int n = position.size();
        for(int i = 0; i < n; i++) {
            pair<int, int> car(position[i], speed[i]);
            cars.push_back(car);
        }
        sort(cars.begin(), cars.end());

        //sorted by position, smaller to bigger
        for(int i = n-1; i > -1; i--) {
            float time = (target - cars[i].first) * 1.0 / cars[i].second * 1.0;
            if (!st.empty()) {
                if(st.top() < time) {
                    st.push(time);
                } 
            }  
            else{
                st.push(time);
            }
        }
        return st.size();
    }
};
// @lc code=end

