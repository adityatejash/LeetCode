class Solution {
    int sum (int n) {
        int ans = 0;
        
        while (n > 0) {
            ans += n % 10;
            n /= 10;
        }

        return ans;
    }

    int mul (int n) {
        int ans = 1;

        while (n > 0) {
            ans *= n % 10;
            n/= 10;
        }

        return ans;
    }

    public boolean checkDivisibility(int n) {
        int a = sum(n) + mul(n);

        return n % a == 0;
    }
}