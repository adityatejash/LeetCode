class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        long long ans = 0;
        for (int i=0; i+1<n; i++) {
            int m = lower - nums[i];
            int M = upper - nums[i];

            auto h = upper_bound (nums.begin() + i + 1, nums.end(), M);
            auto l = lower_bound (nums.begin() + i + 1, nums.end(), m);

            ans += (h - l);
        }

        return ans;
    }
};