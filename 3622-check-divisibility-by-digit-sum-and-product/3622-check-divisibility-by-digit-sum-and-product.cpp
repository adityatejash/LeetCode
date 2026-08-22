class Solution {
public:
    int sum (int n) {
        int ans = 0;
        
        while (n) {
            ans += n % 10;
            n /= 10;
        }

        return ans;
    }

    int mul (int n) {
        int ans = 1;

        while (n) {
            ans *= n % 10;
            n/= 10;
        }

        return ans;
    }

    bool checkDivisibility(int n) {
        int a = sum(n) + mul(n);

        return n % a == 0;
    }
};