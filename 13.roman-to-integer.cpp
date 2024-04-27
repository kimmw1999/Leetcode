class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> roman;
        roman['I'] = 1;
        roman['V'] = 5;
        roman['X'] = 10;
        roman['L'] = 50;
        roman['C'] = 100;
        roman['D'] = 500;
        roman['M'] = 1000;
        int result = 0;
        int i = 0;
        while(i < s.size()-1) {
            if(roman[s[i]] < roman[s[i+1]]) {
                result -= roman[s[i]];
            }
            else{
                result += roman[s[i]];
            }
            i++;
        }
        result += roman[s[i]];
        return result;
    }
};