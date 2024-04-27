class Solution {
public:
    string getPermutation(int n, int k) {
        string str(n, '1');
        vector<char> unused(n);
        for(int i = 1; i <= n; i++) {
            unused[i-1] = '0' + i;
        }
        
        for(int i = 0; i < n; i++) {
            int fact = factorial(n - i - 1);
            int idx = k / fact;
            if(k % fact == 0) {
                str[i] = unused[idx-1];
                unused.erase(unused.begin() + idx - 1);
                for(int j = i+1; j < n; j++) {
                    str[j] = unused.back();
                    unused.pop_back();
                }
                return str;
            }
            str[i] = unused[idx];
            unused.erase(unused.begin() + idx);
            k -= (idx * fact);
        }
        return str;
    }

private:
    int factorial(int n) {
        int res = 1;
        for(int i = 2; i <= n; i++) {
            res *= i;
        }
        return res;
    }
};