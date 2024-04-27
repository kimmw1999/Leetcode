class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int sign = 1;
        long result = 0;
        while(s[i] == ' ' && i < s.size()) {
            i++;
        }

        if(s[i] == '-') {
            sign = -1;
            i++;
        }
        else if(s[i] == '+'){
            i++;
        }

        while(i < s.size()) {
            if(s[i] < '0' || s[i] > '9') {
                return result * sign;
            }

            result = result * 10 + (s[i]-'0');
            if(result > INT_MAX-1 && sign == 1) {
                return INT_MAX;
            }
            else if(result > INT_MAX && sign == -1 ) {
                return INT_MIN;
            }
            i++;
        }
        return result * sign;
    }
};