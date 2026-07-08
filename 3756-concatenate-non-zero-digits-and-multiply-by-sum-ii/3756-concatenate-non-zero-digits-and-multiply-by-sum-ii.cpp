class Solution {
public:
    static const int MOD = 1000000007;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        vector<long long> SUM(n + 1, 0);
        vector<long long> X(n + 1, 0);
        vector<int> COUNT(n + 1, 0);
        vector<long long> pow10(n + 1, 1);

        // SUM
        for (int i = 1; i <= n; i++) {
            SUM[i] = SUM[i - 1] + (s[i - 1] - '0');
        }

        // X
        for (int i = 1; i <= n; i++) {
            if (s[i - 1] == '0') {
                X[i] = X[i - 1];
            } else {
                X[i] = (X[i - 1] * 10 + (s[i - 1] - '0')) % MOD;
            }
        }

        // COUNT (count of non-zero digits)
        for (int i = 1; i <= n; i++) {
            if (s[i - 1] == '0') {
                COUNT[i] = COUNT[i - 1];
            } else {
                COUNT[i] = COUNT[i - 1] + 1;
            }
        }

        // pow10
        for (int i = 1; i <= n; i++) {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];

            long long sum = SUM[r + 1] - SUM[l];

            int k = COUNT[r + 1] - COUNT[l];

            long long x = (X[r + 1] - (X[l] * pow10[k]) % MOD + MOD) % MOD;

            ans.push_back((x * sum) % MOD);
        }

        return ans;
    }
};