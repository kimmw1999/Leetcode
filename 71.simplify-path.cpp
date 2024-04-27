class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        
        string curr = "";
        for(char ch : path) {
            if(ch == '/') {
                if(curr != "") {
                    pushString(st, curr);
                    curr = "";
                }
            }
            else{
                curr += ch;
            }
            cout << endl;
            // printStack(st);
        }
        if(!curr.empty()) {
            pushString(st, curr);
            
        }
        // printStack(st);
        return stackToString(st);
    }
private:
    void printStack(stack<string> st) {
        vector<string> v(st.size());
        for(int i = st.size()-1; i >= 0; i--) {
            v[i] = st.top();
            st.pop();
        }
        for(int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
    }
    void pushString(stack<string> &st, string curr) {
        if(curr == ".") {
            return;
        }
        if(curr == "..") {
            if(!st.empty()) {
                st.pop();
            }
            return;
        }
        st.push(curr);
    }
    string stackToString(stack<string> st) {
        if(st.empty()) {
            return "/";
        }
        string res = "";
        while(!st.empty()) {
            res = "/" + st.top() + res;
            st.pop();
        }

        return res;
    }
};