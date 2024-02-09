/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
#include <string>
#include <stack>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char ch : s) {
            if(!st.empty()) {
                if(ch == ')') {
                    if (st.top() == '{' || st.top() == '[') {
                        return false;
                    }
                    else {
                        st.pop();
                    }
                }
                else if(ch == ']') {
                    if (st.top() == '{' || st.top() == '(') {
                        return false;
                    }
                    else {
                        st.pop();
                    }
                }
                else if(ch == '}') {
                    if (st.top() == '(' || st.top() == '[') {
                        return false;
                    }
                    else {
                        st.pop();
                    }
                }
                else {
                    st.push(ch);
                }

            }

            else{
                if(ch == ')' || ch == '}' || ch == ']') {
                    return false;
                }
                st.push(ch);
            }
        }
        if(st.empty()) {
            return true;
        }
        else {
            return false;
        }
    }
};
// @lc code=end

