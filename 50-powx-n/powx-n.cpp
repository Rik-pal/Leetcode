class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;           // convert to long long to handle INT_MIN safely
        if (N < 0) {
            x = 1.0 / x;
            N = -N;
        }

        double result = 1.0;
        while (N > 0) {
            if (N & 1)             // if N is odd
                result *= x;
            x *= x;                // square the base
            N >>= 1;               // halve the exponent
        }
        return result;
    }
};