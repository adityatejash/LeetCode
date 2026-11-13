class Solution {
public:
    int find (unordered_map<long long, int>& mp, long long i) {
        if (mp[i] >= 2) return 2;
        if (mp[i] == 1) return 1;
        return 0;
    }

    int maximumLength(vector<int>& nums) {
        int ans = 0;

        unordered_map<long long, int> mp;

        int M = INT_MIN;
        for (int n : nums) {
            M = max(M, n);
            mp[n]++;
        }

        ans = (mp[1] % 2 == 0) ? mp[1] - 1 : mp[1];

        for (auto& [key, freq] : mp) {
            if (key == 1) continue;

            int sz = 1;
            long long x = key;

            while (find(mp, x) == 2) {

                if (x > M / x) break;

                long long next = x*x;

                if (find(mp, next) == 0) break;

                sz += 2;
                x = next;
            }

            ans = max(ans, sz);
        }

        return ans;
    }
};