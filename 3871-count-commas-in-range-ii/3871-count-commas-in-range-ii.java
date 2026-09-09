class Solution {
    public long countCommas(long n) {
        long k = 0;

        long x = n;
        while (x >= 1000) {
            x /= 1000;
            k++;
        }

        return (long)(k * (n + 1) - (Math.pow(1000, k + 1) - 1000) / 999);
    }
}