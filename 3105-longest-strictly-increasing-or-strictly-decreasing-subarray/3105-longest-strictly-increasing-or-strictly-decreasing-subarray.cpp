class Solution {
public:
    int solve(vector<int>& nums, int i, int ans, int inc) {
        if (i == nums.size() - 1) return ans;

        if (inc && nums[i] < nums[i+1]) {
            return solve(nums, i+1, ans+1, true);
        }

        if (!inc && nums[i] > nums[i+1]) {
            return solve(nums, i+1, ans+1, false);
        }

        return ans;
    }
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans = 1;

        for (int i=0; i<nums.size(); i++) {
            ans = max (ans, solve(nums, i, 1, true));
            ans = max (ans, solve(nums, i, 1, false));
        }

        return ans;
    }
};