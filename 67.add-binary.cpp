class Solution {
public:
    string addBinary(string a, string b) {
        if(a.size() < b.size()) {
            return addBinary(b, a);
        }
        int n = a.size();
        int m = b.size();
        for(int i = 0; i < n - m; i++) {
            b = "0" + b;
        }
        int c = 0;
        int one_count = 0;
        string res;
        for(int i = n-1; i >= 0; i--) {
            one_count = c;
            if(a[i] == '1') {
                one_count++;
            }
            if(b[i] == '1') {
                one_count++;
            }

            if(one_count == 0) {
                res += '0';
                c = 0;
            }
            else if(one_count == 1) {
                res += '1';
                c = 0;
            }
            else if(one_count == 2){
                res += '0';
                c = 1;
            }
            else {
                res += '1';
                c = 1;
            }
        }
        if(c == 1) {
            res += '1';
        }
        reverse(res.begin(), res.end());
        return res;

    }
};