class Solution {
public:
    int gcd(int a, int b){
        if (b == 0) return a;

        return gcd(b, a%b);
    }

    int findGCD(vector<int>& nums) {
        int m = INT_MAX;    
        int M = INT_MIN;

        for (int n : nums){
            if (n > M) M = n;
            if (n < m) m = n;
        }    

        return gcd (M, m);
    }
};