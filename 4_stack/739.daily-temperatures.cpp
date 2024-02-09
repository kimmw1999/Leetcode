/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 */

// @lc code=start
#include <stack>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
//neetcode.io solution
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        
        // pair: [index, temp]
        stack<pair<int, int>> stk;
        vector<int> result(n);
        
        for (int i = 0; i < n; i++) {
            int currDay = i;
            int currTemp = temperatures[i];
            
            while (!stk.empty() && stk.top().second < currTemp) {
                int prevDay = stk.top().first;
                int prevTemp = stk.top().second;
                stk.pop();
                
                result[prevDay] = currDay - prevDay;
            }
            
            stk.push({currDay, currTemp});
        }
        
        return result;
    }
    //this is my own solution
    vector<int> dailyTemperatures2(vector<int>& temperatures) {
        stack<int> st;
        unordered_map<int, stack<int>> hashmap;
        int i = 0;
        int n = temperatures.size();
        vector<int> output(n, 0);

        while(i < n) {
            //put in hashmap
            hashmap[temperatures[i]].push(i);
            while(!st.empty() && st.top() < temperatures[i]) {
                int temp = st.top();
                st.pop();
                int t_idx = hashmap[temp].top();
                hashmap[temp].pop();
                output[t_idx] = i - t_idx; 
            }
            st.push(temperatures[i]);
            i++;
        }
        return output;
    }
};
// @lc code=end
int main() {
    Solution solution;
    vector<int> temp = {73,74,75,71,69,72,76,73};
    solution.dailyTemperatures(temp);
}
