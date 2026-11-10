class Solution {
public:
    int solve (int i, vector<int>& costs, vector<int>& dp, int n) {
        if (i == n) return 0;

        if (dp[i] != -1) return dp[i];

        int ans = INT_MAX;

        for (int j=i+1; j<=min(i+3, n); j++) {
            int cost = costs[j - 1] + pow(j-i, 2) + solve (j, costs,dp, n);

            ans = min(ans, cost);
        }

        return dp[i] = ans;
    }

    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp (n+1, -1);
        return solve (0, costs,dp, n);
    }
};