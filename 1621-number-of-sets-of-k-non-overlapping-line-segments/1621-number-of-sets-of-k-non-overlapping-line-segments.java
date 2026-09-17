class Solution {
    public long MOD = 1000000007;
    
    public int numberOfSets(int n, int k) {

        long[][] dp = new long[k+1][n];

        for (int i=0; i<n; i++) {
            dp[0][i] = 1;
        }

        for (int i=1; i<=k; i++) {
            for (int j=1; j<n; j++) {
                dp[i-1][j] = (dp[i-1][j] + dp[i-1][j-1]) % MOD;
            }
            for (int j=i; j<n; j++) {
                dp[i][j] = (dp[i][j-1] + dp[i-1][j-1]) % MOD;
            }
        }

        return (int)dp[k][n-1];
    }
}