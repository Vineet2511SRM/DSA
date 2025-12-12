class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        // Determine sign of result
        bool negative = (dividend < 0) ^ (divisor < 0);

        // Convert to positive long long to avoid overflow
        long long dvd = llabs(dividend);
        long long dvs = llabs(divisor);
        long long ans = 0;

        while (dvd >= dvs) {
            long long temp = dvs;
            long long multiple = 1;

            // Double temp until it's just below dvd
            while ((temp << 1) <= dvd) {
                temp <<= 1;
                multiple <<= 1;
            }

            // Subtract this highest chunk
            dvd -= temp;
            ans += multiple;
        }

        // Apply sign
        if (negative) ans = -ans;

        // Clamp to 32-bit range
        if (ans > INT_MAX) return INT_MAX;
        if (ans < INT_MIN) return INT_MIN;

        return ans;
    }
};