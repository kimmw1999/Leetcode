class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int i = 0;
        int n = words.size();
        while(i < words.size()) {
            vector<string> curr = getWords(i, words, maxWidth);
            ans.push_back(makeString(curr, i, n, maxWidth));
        }
        return ans;
    }
private:
    vector<string> getWords(int &i, vector<string>& words, int maxWidth) {
        cout << i << endl;
        vector<string> result;
        int currLen = 0;
        while(i < words.size() && currLen + words[i].size()<= maxWidth) {
            result.push_back(words[i]);
            currLen += words[i].size() + 1;
            cout << i << " " << currLen << endl;
            for(string s : result) {
                cout << s << " ";
            }
            cout << endl;
            i++;
        }
        return result;
    }
    string makeString(vector<string> &curr, int i, int n, int maxWidth) {
        int numPads = curr.size() - 1;
        if(numPads == 0) {
            return curr[0] + string(maxWidth - curr[0].size(), ' ');
        }
        if(i >= n) {
            //last string, left justified
            string result = "";
            for(int i = 0; i < curr.size() - 1; i++) {
                result += curr[i] + " ";
            }
            result += curr[curr.size() - 1];
            result += string(maxWidth - result.size(), ' ');
            return result;
        }
        else{
            //normal string
            int strLen = 0;
            for(string s : curr) {
                strLen += s.size();
            }
            int padSize = maxWidth - strLen;
            int mod = padSize % numPads;
            string pad(padSize / numPads, ' ');

            string result = "";
            for(int i = 0; i < curr.size() - 1; i++) {
                string s = curr[i];
                result += s + pad;
                if(mod > 0) {
                    result += " ";
                    mod--;
                }
            }
            result += curr[curr.size() - 1];
            return result;

        }
    }
};