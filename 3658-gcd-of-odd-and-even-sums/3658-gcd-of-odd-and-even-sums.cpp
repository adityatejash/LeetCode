class Solution {
public:
    int gcd (int a, int b){
        if (b == 0) return a;

        return gcd(b, a%b);
    }
    int gcdOfOddEvenSums(int n) {
        int sumOdd = 0;
        int sumEven = 0;

        int num = 1;
        for (int i=0; i<n; i++){
            sumOdd += num;
            num += 2;
        }

        num = 2;
        for (int i=0; i<n; i++){
            sumEven += num;
            num += 2;
        }

        return gcd(sumOdd, sumEven);
    }
};