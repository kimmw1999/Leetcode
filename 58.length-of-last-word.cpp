class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size() - 1;
        while(s[i] == ' ') {
            i--;
        }
        int res = 0;
        while(i > -1 && s[i] != ' ') {
            i--;
            res++;
        }
        return res;
    }
};