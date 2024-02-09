#include <vector>
#include <string>
using namespace std;
class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        int n = strs.size();
        string output = "";
        for(int i = 0; i < n; i++) {
            int l = strs[i].size();
            output.append(to_string(l));
            output.append(":");
            output.append(strs[i]);
        }
        return output;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> output;
        int i = 0;
        int n = s.size();
        while(i < n) {
            int offset = 1;
            while(s[i+offset] != ':') {
                offset++;
            }
            int l = stoi(s.substr(i, offset));
            string str = s.substr(i + offset + 1, l);
            output.push_back(str);
            i = i+offset+1+l;
        }
        return output;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));