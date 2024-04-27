/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
#include <vector>
#include <string>
#include <stack>
using namespace std;
class Solution {
public:

    vector<string> generateParenthesis(int n) {
        vector<string> output;
        vector<string> st; //used as stack(LIFO) - vector for easy string conversion.

        backtracking(n, 0, 0, output, st);
        return output;
    }

private:

    void backtracking(int n, int open, int close, vector<string> &output, vector<string> &st) {
        if(open == n && close == n) {
            string str = "";
            for(int i = 0; i < n*2; i++) {
                str += st[i];
            }
            output.push_back(str);
            return;
        }

        if(open == close) {
            st.push_back("(");
            backtracking(n, open+1, close, output, st);
            st.pop_back();
        }
        else if(open > close) {
            st.push_back(")");
            backtracking(n, open, close + 1, output, st);
            st.pop_back();
            if (open < n) {
                st.push_back("(");
                backtracking(n, open + 1, close, output, st);
                st.pop_back();
            }
        }
    }
};
// @lc code=end