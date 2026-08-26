class Solution {
public:
    int solve (int n) {
        int div = 2;
        int sum = 1 + n;

        for (int i=2; i<n; i++) {
            if (n % i == 0) {
                div++;
                sum += i;

                if (div > 4) return 0;
            }
        }

        if (div == 4) return sum;

        return 0;
    }
    int sumFourDivisors(vector<int>& nums) {
        int sum = 0;
    
        for (int n : nums) {
            sum += solve(n);
        }

        return sum;
    }
};