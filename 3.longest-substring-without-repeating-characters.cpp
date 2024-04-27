class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;
        int maxSize = 0;
        unordered_set<char> chars;
        while(r < s.size()) {
            while(chars.find(s[r]) != chars.end()) {
                chars.erase(s[l]);
                l++;
            }
            maxSize = max(maxSize, r-l+1);
            chars.insert(s[r]);
            r++;
        }
        return maxSize;
    }
private:
    
};