class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for(string str : strs) {
            char s[26];
            for(int i = 0; i < 26; i++) {
                s[i] = '0';
            }

            for(char ch : str) {
                s[ch - 'a']++;
            }

            string key(s, 26);

            m[key].push_back(str);
        }

        vector<vector<string>> res;
        for(auto it = m.begin(); it != m.end(); it++) {
            res.push_back(it->second);
        }
        return res;
    }
};