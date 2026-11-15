class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const long long MOD = 1e9 + 7;

        int sum = 0;
        int even = 1;
        int odd = 0;

        long long ans = 0;
        for (int n : arr) {
            sum += n;

            if (sum % 2 == 1) {
                odd++;
                ans += even;
            } else {
                even++;
                ans += odd;
            }
        }

        return ans % MOD;
    }
};