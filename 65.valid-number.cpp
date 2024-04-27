class Solution {
public:
    bool isNumber(string s) {
        bool num_seen = false;
        bool e_seen = false;
        bool point_seen = false;
        bool num_after_e = false;

        for(int i = 0; i < s.size(); i++) {
            if('0' <= s[i] && s[i] <= '9') {
                num_seen = true;
                num_after_e = true;
            }
            else if(s[i] == '.') {
                if(e_seen || point_seen) {
                    return false;
                }
                point_seen = true;
            }
            else if(s[i] == 'e' || s[i] == 'E') {
                if(e_seen || !num_seen) {
                    return false;
                }
                num_after_e = false;
                e_seen = true;
            }
            else if(s[i] == '+' || s[i] == '-') {
                if(i != 0 && s[i-1] != 'e' && s[i-1] != 'E') {
                    return false;
                }
            }
            else{
                return false;
            }
        }
        return num_seen && num_after_e;
    }
};