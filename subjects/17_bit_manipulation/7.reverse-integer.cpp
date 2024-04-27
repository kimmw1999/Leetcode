class Solution {
public:
    int reverse(int x) {
        // cout << INT_MIN << " " << INT_MAX;
        bool neg = x < 0;
        x = abs(x);
        long result = 0;
        while( x > 0 ) {
            result *= 10;
            result += (x%10);
            x/=10;
        }
        if(neg) {
            result = -result;
        }
        if(result < INT_MIN || result > INT_MAX) {
            return 0;
        }
        return result;
        // int rev = 0;
//         while (x != 0) {
//             int temp = x % 10;
//             x /= 10;
//             if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && temp > 7)) {
//                 return 0;
//             }
//             if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && temp < -8)) {
//                 return 0;
//             }
//             rev = rev * 10 + temp;
//         }
//         return rev;
    }
};