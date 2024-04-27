/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
    double myPow(double x, int n) {
        long exponent = abs(n);
        double curr = x;
        double result = 1.0;
        
        for (long i = exponent; i > 0; i /= 2) {
            if (i % 2 == 1) {
                result *= curr;
            }
            curr *= curr;
        }
        
        if (n < 0) {
            return 1.0 / result;
        }
        return result;
    }
    // double myPow(double x, int n) {
    //     if(n == INT_MIN) {
    //         return 1/(x*myPow(x, INT_MAX));
    //     }
    //     else if(n < 0) {
    //         return 1/myPow(x, -n);
    //     }
    //     else if(n == 0) {
    //         return 1;
    //     }
    //     double result = x;
    //     double offset = 1;
    //     while(n > 1) {
    //         if(n % 2 == 1) {
    //             offset *= result;
    //             n--;
    //         }
    //         if( n > 1 ) {
    //             result *= result;
    //             n /= 2;
    //         }
    //         // cout << offset << " " << result << " " << n << endl;
    //     }
    //     return result * offset;
    // }
};
// @lc code=end

