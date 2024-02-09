/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

// @lc code=start
#include <vector>
using namespace std;
class MinStack {
public:
    MinStack() {
    }
    
    void push(int val) {
        if(min_st.empty() || min_st.back() >= val) {
            min_st.push_back(val);
        }
        main_st.push_back(val);
    }
    
    void pop() {
        if(min_st.back() == main_st.back()) {
            min_st.pop_back();
        }
        main_st.pop_back();
    }
    
    int top() {
        return main_st.back();
    }
    
    int getMin() {
        return min_st.back();   
    }
private:
    vector<int> main_st;
    vector<int> min_st;
    
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

