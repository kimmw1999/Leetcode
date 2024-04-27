class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) {
            return false;
        }
        vector<int> digits;
        while(x > 0) {
            digits.push_back(x % 10);
            x /= 10;
        }
        int l;
        int r;
        if(digits.size() % 2 == 1) {
            l = digits.size() / 2;
            r = l;
        }
        else{
            r = digits.size() / 2;
            l = r-1;
        }
        while(l > -1 && r < digits.size()) {
            if(digits[l] != digits[r]) {
                return false;
            }
            l--;
            r++;
        }
        return true;

    }
};