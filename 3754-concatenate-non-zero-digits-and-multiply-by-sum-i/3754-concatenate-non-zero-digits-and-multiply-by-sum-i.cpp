class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0;
        long long sum = 0;
        
        while (n){
            if (n%10 != 0){
                x = (x * 10) + (n % 10);
                sum += n % 10;
            }
            n /= 10;
        }

        // reverse x;
        long long temp = 0;
        while (x){
            temp = (temp * 10) + (x % 10);
            x /= 10;
        }
        x = temp;

        return x * sum;
    }
};