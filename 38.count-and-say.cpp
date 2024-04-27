class Solution {
public:
    string countAndSay(int n) {
        vector<string> memo;
        memo.push_back("1");
        for(int i = 0; i < n; i++) {
            string str = memo[i];
            memo.push_back(say(str));
        }
        return memo[n-1];
    }
private:
    string say(string str) {
        string output;
        int i = 0;
        int s = 0;
        char ch = str[s];
        while(i <= str.size()) {
            if(i == str.size() || str[i] != str[s]){
                int count = i - s;
                output += to_string(count);
                output.push_back(str[s]);
                s = i;
            }
            i++;
        }
        return output;
    }
};