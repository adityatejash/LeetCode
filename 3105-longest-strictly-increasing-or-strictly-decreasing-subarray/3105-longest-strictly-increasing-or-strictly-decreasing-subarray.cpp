class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp (n, vector<int> (2, 1));

        int ans = 1;
        for (int i=1; i<n; i++) {
            dp[i][0] = (
                nums[i] > nums[i-1] ? dp[i-1][0] + 1 : 1
            );

            dp[i][1] = (
                nums[i] < nums[i-1] ? dp[i-1][1] + 1 : 1
            );

            ans = max ({
                ans,
                dp[i][0],
                dp[i][1]
            });
        }

        return ans;
    }
};