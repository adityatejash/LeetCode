class Solution {
public:
    int digitProduct (int n) {
        int prod = 1;

        while (n) {
            prod *= n % 10;
            n /= 10;
        }

        return prod;
    }
    int smallestNumber(int n, int t) {
        
        for (int i=n; i<INT_MAX; i++) {
            if (digitProduct(i) % t == 0) {
                return i;
            }
        }

        return INT_MAX;
    }
};