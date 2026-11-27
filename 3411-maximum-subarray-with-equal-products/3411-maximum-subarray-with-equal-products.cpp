class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i=0; i<n; i++) {
            long long g = 0;
            long long l = 1;
            __int128 p = 1;


            for (int j=i; j<n; j++) {
                g = gcd(g, (long long)nums[j]);
                l = lcm(l, (long long)nums[j]);
                p *=nums[j];

                if (p > g * l) break;

                if (p == g * l) {
                    ans = max(ans, j-i+1);
                }
            }
        }

        return ans;
    }
};