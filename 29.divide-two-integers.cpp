class Solution {
public:
    int divide(int dividend, int divisor) {
        int sign = 1;
        long ldividend = dividend;
        long ldivisor = divisor;
        if(ldividend < 0) {
            sign *= -1;
            ldividend *= -1;
        }
        if(ldivisor < 0) {
            sign *= -1;
            ldivisor *= -1;
        }

        long result = 0;
        int temp_divisor = ldivisor;
        int multiplier = 1;
        int count = 0;
        while(temp_divisor < ldividend && count < 31) {
            if(count == 30){
                cout << "a";
            }
            if(temp_divisor < 0) {
                break;
            }
            ldividend -= temp_divisor;
            result += multiplier;
            temp_divisor <<= 1;
            multiplier <<= 1;
            count++;
        }
        while(ldividend - ldivisor >= 0) {
            result += 1;
            ldividend -= ldivisor;
        }
        if(sign == 1 && result > (long)INT_MAX) {
            return INT_MAX;
        }
        if(sign == -1 && result > (long)INT_MAX + 1) {
            return INT_MIN;
        }
        return sign * result;
    }
};