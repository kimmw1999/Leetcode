class Solution {
public:
    unordered_map<string, bool> dp;
    bool isScramble(string s1, string s2) {
        this->dp = unordered_map<string, bool>();
        return isScrambleDP(s1, s2);
    }
    bool isScrambleDP(string s1, string s2) {
        if(s1.size() != s2.size()) {
            return false;
        }
        if(s1.size() == 1 && s1[0] == s2[0]) {
            return true;
        }

        if(this->dp.find(s1+s2) != this->dp.end()) {
            return this->dp[s1+s2];
        }

        for(int i = 1; i < s1.size(); i++) {
            //for s1 =x1 + y1, s2 = x1 + y2, compare (x1, x2), (y1, y2)
            string x1 = s1.substr(0, i);
            string x2 = s2.substr(0, i);
            string y1 = s1.substr(i, s1.size() - i);
            string y2 = s2.substr(i, s2.size() - i);
            //for s2 = xp2 + yp2, compare (x1, yp2), (y1, xp2)
            string xp2 = s2.substr(0, s2.size() - i);
            string yp2 = s2.substr(s2.size() - i, i);

            if((isScrambleDP(x1, x2) && isScrambleDP(y1, y2)) || (isScrambleDP(x1, yp2) && isScrambleDP(y1, xp2))) {
                this->dp[s1 + s2] = true;
                return true;
            }
        }

        this->dp[s1 + s2] = false;
        return false;
    }
};