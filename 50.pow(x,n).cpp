class Solution {
public:
    double myPow(double x, int n) {
        double res = 1;
        long n1 = n;
        if(n1 == 0) {
            return 1;
        }
        if(n1 == 1) {
            return x;
        }
        if(n1 < 0) {
            x = 1/x;
            n1 *= -1;
        }

        while(n1 > 1) {
            if(n1 % 2 == 1) {
                res *= x;
                n1--;
            }
            x *= x;
            n1 /= 2;
        }
        return res * x;
    }
};