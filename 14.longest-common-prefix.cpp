class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int endI = 0;
        bool last = false;
        while(true) {
            if(endI >= strs[0].size()) {
                endI--;
                break;
            }
            char pf = strs[0][endI];
            for(int i = 1; i < strs.size(); i++) {
                if(endI >= strs[i].size() || strs[i][endI] != pf) {
                    endI--;
                    last = true;
                    break;
                }
            }
            if(last) {
                break;
            }
            endI++;
        }
        if(endI <= -1) {
            return "";
        }
        return strs[0].substr(0, endI + 1);
    }
};