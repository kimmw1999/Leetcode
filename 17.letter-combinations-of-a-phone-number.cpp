class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) {
            return {};
        }
        m['2'] = {'a','b','c'};
        m['3'] = {'d','e','f'};
        m['4'] = {'g','h','i'};
        m['5'] = {'j','k','l'};
        m['6'] = {'m','n','o'};
        m['7'] = {'p','q','r','s'};
        m['8'] = {'t','u','v'};
        m['9'] = {'w','x','y','z'};

        vector<string> result;
        string cur;
        appendLetter(digits, 0, digits.size(), cur, result);
        return result;
    }
private:
    unordered_map<char, vector<char>> m;
    void appendLetter(string &digits, int i, int d_size, string &cur, vector<string> &result) {
        if(i >= d_size) {
            result.push_back(cur);
            return;
        }

        for(char ch : m[digits[i]]) {
            cur += ch;
            appendLetter(digits, i+1, d_size, cur, result);
            cur.erase(cur.begin() + cur.size()-1);
        }
    }
};