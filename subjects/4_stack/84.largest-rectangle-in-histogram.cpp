/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */

// @lc code=start
#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        //neetcode solution

        // pair: [index, height]
        stack<pair<int, int>> stk;
        int result = 0;
        
        for (int i = 0; i < heights.size(); i++) {
            int start = i;
            
            while (!stk.empty() && stk.top().second > heights[i]) {
                int index = stk.top().first;
                int width = i - index;
                int height = stk.top().second;
                stk.pop();
                
                result = max(result, height * width);
                start = index;
            }
            
            stk.push({start, heights[i]});
        }
        
        while (!stk.empty()) {
            int width = heights.size() - stk.top().first;
            int height = stk.top().second;
            stk.pop();
            
            result = max(result, height * width);
        }
                          
        return result;

        
        // /*
        // initialize stack for vector{h, idx};
        // initialize output int;
        // initialize maxarea;
        // iterate heights{
        //     if current h <= stack's top height{
        //         //get area with elements in stack:
        //         {h1, idx1}, {h2, idx2} --> maxarea = max(maxarea, h1*(idx2-idx1+1), h2);
        //         while stack empty or stack top <= h{
        //             pop stack;
        //             with the last popped's idx, push to stack {current h, newidx};
        //         }
        //     }
        //     else{
        //         push {current h, curidx};
        //     }
        // }
        // return maxarea;
        // */

        // vector<vector<int>> st;
        // int output = 0;
        // int maxarea = 0;
        // for(int i = 0; i < heights.size(); i++) {
        //     if(st.empty()) {
        //         st.push_back({heights[i], i});
        //     }
        //     else{
        //         if(heights[i] <= st.back()[0]) {
        //             for(int j = 0; j < st.size(); j++) {
        //                 maxarea = max(maxarea, st[j][0]* (i-1 - st[j][1] + 1));
        //             }
        //             int popped_idx = i;
        //             while(!st.empty() && st.back()[0] > heights[i]) {
        //                 popped_idx = st.back()[1];
        //                 st.pop_back();
        //             }
        //             st.push_back({heights[i], popped_idx});
        //         }
        //         else{
        //             st.push_back({heights[i], i});
        //         }
        //     }
        // }

        // //after every iteration finished, calculate the remained stack max
        // if(!st.empty()){
        //     for(int i = 0; i < st.size(); i++) {
        //         maxarea = max(maxarea, st[i][0] * (st.back()[1] - st[i][1] + 1));
        //     }
        // }
        // return maxarea;
        
    }
};
// @lc code=end

int main() {
    Solution solution;
    vector<int> h = {5,4,1,2};
    solution.largestRectangleArea(h);
}