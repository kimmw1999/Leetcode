class Solution {
public:
    int strStr(string haystack, string needle) {
        int idx = -1;
        int n = haystack.size();
        int m = needle.size();
        int i = 0;
        while(i < n) {
            if(haystack[i] == needle[0] && n-i >= m) {
                int counter = 0;
                for(int j = 0; j < m; j++) {
                    if(idx < i && haystack[counter] == needle[0]) {
                        idx = counter;
                    }
                    if(haystack[i + counter] != needle[j]) {
                        break;
                    }
                    counter++;
                }
                if(counter != m) {
                    i += 1;
                    if(idx > i) {
                        i = idx;
                    }
                }
                else{
                    return i;
                }
            }
            else{
                i++;
            }
        }
        return -1;
    }
};