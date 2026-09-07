class Solution {
public:
    const long long MOD = 1e9 + 7;
    int distinctSubseqII(string s) {
        long long x = 1;

        unordered_map<char, int> m;

        for (char c : s) {
            long long y = x;
        
            x = (2*x - m[c] + MOD) % MOD;

            m[c] = y;
        }

        return (x - 1 + MOD) % MOD;
    }
};