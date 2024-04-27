class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string curr = "(";
        int l = n-1;
        int r = n;
        vector<string> result;
        dfs(l, r, 0, curr, result);
        return result;
    }
private:
    void dfs(int l, int r, int n, string curr, vector<string> &result) {
        if(l == 0) {
            for(int i = 0; i < r; i++) {
                curr += ')';
            }
            result.push_back(curr);
            return;
        }

        if(l == r) {
            curr += '(';
            dfs(l-1, r, n+1, curr, result);
            return;
        }

        else{
            curr += '(';
            dfs(l-1, r, n+1, curr, result);
            curr.pop_back();
            curr += ')';
            dfs(l, r-1, n+1, curr, result);
        }
    }
};