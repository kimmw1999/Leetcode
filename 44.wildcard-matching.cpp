class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> memo(s.size()+1, vector<bool>(p.size()+1, false));
        memo[s.size()][p.size()] = true;

        for(int j = p.size() - 1; j > -1; j--) {
            if(p[j] == '*') {
                memo[s.size()][j] = memo[s.size()][j+1];
            }
            else{
                break;
            }
        }
        for(int i = s.size() - 1; i > -1; i--) {
            for(int j = p.size() - 1; j > -1; j--) {
                if(s[i] == p[j] || p[j] == '?') {
                    memo[i][j] = memo[i+1][j+1];
                }
                else if(p[j] == '*') {
                    memo[i][j] = memo[i+1][j] || memo[i][j+1];
                }
                else{
                    memo[i][j] = false;
                }
            }
        }
        return memo[0][0];
    }

};