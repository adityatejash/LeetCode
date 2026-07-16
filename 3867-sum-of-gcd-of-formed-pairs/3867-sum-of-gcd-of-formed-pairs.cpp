class Solution {
public:
    int gcd (int a, int b){
        if (b == 0) return a;

        return gcd(b, a% b);
    }

    long long gcdSum(vector<int>& nums) {
        vector<int> prefixGcd;
        int mx = INT_MIN; 

        for (int n : nums){
            mx = max(n, mx);

            prefixGcd.push_back(gcd(n, mx));
        }

        sort(prefixGcd.begin(), prefixGcd.end());
        
        long long ans  = 0;
        int i = 0; 
        int j = prefixGcd.size() - 1;
        
        while (i < j){
            ans += gcd(prefixGcd[i++], prefixGcd[j--]);
        }

        return ans;
    }
};