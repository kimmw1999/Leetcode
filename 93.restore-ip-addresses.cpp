class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        vector<string> curr(4);

        backtracking(s, ans, curr, 0, 0);
        return ans;
    }

    void backtracking(string s, vector<string> &ans, vector<string> &curr, int s_i, int i) {
        if(i == 4) {
            if(s_i == s.size()) {
                //add curr to ans
                ans.push_back(curr[0]+'.'+curr[1]+'.'+curr[2]+'.'+curr[3]);
                return;
            }
            return;
        }
        int curNum = 0;
        
        int j = 0;
        while(j < 3) {
            curNum = curNum * 10 + (s[s_i] - '0');
            if(curNum >= 256) {
                break;
            }
            curr[i].push_back(s[s_i]);
            s_i++;
            backtracking(s, ans, curr, s_i, i+1);
            j++;

            if(curNum == 0) {
                break;
            }
        }
        while(j > 0) {
            curr[i].pop_back();
            j--;
        }
    }
};