/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */

// @lc code=start
#include <stack>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int output = 0;
        for (int i = 0; i < tokens.size(); i++) {
            if(tokens[i] == "+") {
                int n2 = st.top();
                st.pop();
                int n1 = st.top();
                st.pop();
                st.push(n1 + n2);
            }
            else if(tokens[i] == "-") {
                int n2 = st.top();
                st.pop();
                int n1 = st.top();
                st.pop();
                st.push(n1 - n2);
            }
            else if(tokens[i] == "*") {
                int n2 = st.top();
                st.pop();
                int n1 = st.top();
                st.pop();
                st.push(n1 * n2);
            }
            else if(tokens[i] == "/") {
                int n2 = st.top();
                st.pop();
                int n1 = st.top();
                st.pop();
                st.push(n1 / n2);
            }
            else{
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};
// @lc code=end

