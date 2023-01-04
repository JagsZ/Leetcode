class Solution {
int HALF_INT_MIN = -1073741824;

public:

int divide(int dividend, int divisor) {

    if (dividend == INT_MIN && divisor == -1) {
        return INT_MAX;
    }
    
    int negatives = 2;
    if (dividend > 0) {
        negatives--;
        dividend = -dividend;
    }
    if (divisor > 0) {
        negatives--;
        divisor = -divisor;
    }

    int quotient = 0;
    while (divisor >= dividend) {
        int powerOfTwo = -1;
        int value = divisor;
        while (value >= HALF_INT_MIN && value + value >= dividend) {
            value += value;
            powerOfTwo += powerOfTwo;
        }
        // We have been able to subtract divisor another powerOfTwo times.
        quotient += powerOfTwo;
        // Remove value so far so that we can continue the process with remainder.
        dividend -= value;
    }

    /* If there was originally one negative sign, then
     * the quotient remains negative. Otherwise, switch
     * it to positive. */
    if (negatives != 1) 
        quotient = -quotient;
    
    return quotient;
    }
};