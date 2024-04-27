class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_set<char> start_chars;
        unordered_map<string, int> m;
        for(string s : words) {
            start_chars.insert(s[0]);
            m[s]++;
        }

        int i = 0;
        int word_size = words[0].size();
        int substr_size = word_size * words.size();
        if(s.size() < substr_size) {
            return {};
        }
        vector<int> result;
        while(i <= s.size() - substr_size) {
            if(start_chars.find(s[i]) != start_chars.end()) {
                string substr = s.substr(i, substr_size);
                if(check_perm(substr, m, word_size, substr_size)) {
                    result.push_back(i);
                }
            }
            i++;
        }
        return result;
    }
private:
    bool check_perm(string substr, unordered_map<string, int> m, int word_size, int substr_size) {
        int i = 0;
        while(i < substr.size()) {
            string target = substr.substr(i, word_size);
            if(m[target] <= 0) {
                return false;
            }
            m[target]--;
            i += word_size;
        }
        return true;
    }
};