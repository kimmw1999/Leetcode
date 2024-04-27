class Solution {
public:
    int longestValidParentheses(string s) {
        stack<pair<char, int>> st;
        for(int i = 0 ; i < s.size(); i++) {
            if(s[i] == ')' && !st.empty() && st.top().first == '(') {
                st.pop();
            }
            else{
                st.push({s[i], i});
            }
        }
        if(st.empty()) {
            return s.size();
        }
        int r = s.size() - 1;
        int result = 0;
        pair<char, int> p;
        while(!st.empty()) {
            p = st.top();
            st.pop();
            int len = r - (p.second);
            result = max(result, len);
            r = p.second - 1;
        }
        result = max(result, p.second);
        return result;
    }
};