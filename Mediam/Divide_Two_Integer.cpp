

class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle divisor == 0 (undefined; return 0 for safety)
        if (divisor == 0) {
            return 0;
        }
        
        // Handle overflow case explicitly
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        // Determine sign of the result (true if negative)
        bool negative = (dividend < 0) ^ (divisor < 0);

        // Convert to long long before abs to avoid overflow on INT_MIN
        long long dvd = dividend;
        long long dvs = divisor;
        dvd = (dvd < 0) ? -dvd : dvd;
        dvs = (dvs < 0) ? -dvs : dvs;

        long long quotient = 0;

        // Bit-shift approach to find quotient (check if dvs * 2^i fits into dvd)
        for (int i = 31; i >= 0; --i) {
            if (dvd >= (dvs << i)) {
                dvd -= (dvs << i);
                quotient += (1LL << i);
            }
        }

        // Apply sign
        if (negative) {
            quotient = -quotient;
        }

        // Clamp to 32-bit signed integer range
        if (quotient > INT_MAX) {
            return INT_MAX;
        }
        if (quotient < INT_MIN) {
            return INT_MIN;
        }

        return static_cast<int>(quotient);
    }
};


