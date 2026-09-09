class Solution {
public:
    long long countCommas(long long n) {
        long long k = 0;

        long long x = n;
        while (x >= 1000) {
            x /= 1000;
            k++;
        }

        return k * (n + 1) - (pow(1000, k+1) - 1000) / 999;
    }
};