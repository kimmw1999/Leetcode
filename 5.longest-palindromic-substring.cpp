class Solution {
public:
    string longestPalindrome(string s) {
        string result = s.substr(0, 1);
        int longest_len = 1;
        int i = 0;
        while(i < s.size()) {
            int j = i;
            while(j + 1 < s.size() && s[i] == s[j+1]) {
                j++;
            }
            int offset = 0;
            while(j + offset + 1< s.size() && i - offset - 1> -1 && s[j + offset + 1] == s[i - offset - 1]) {
                offset += 1;
            }
            if((j - i + 1) + 2*offset > longest_len) {
                longest_len = (j - i + 1) + 2*offset;
                result = s.substr(i-offset, (j - i + 1) + 2*offset);
            }
            i++;
        }
        return result;
    }
};