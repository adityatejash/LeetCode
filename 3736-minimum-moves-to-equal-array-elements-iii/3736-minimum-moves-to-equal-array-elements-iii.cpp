class Solution {
public:
    int minMoves(vector<int>& nums) {
        int M = INT_MIN;

        for (int n : nums) {
            if (n > M) M = n;
        }

        int ans =0 ;
        for (int n : nums) {
            ans += abs (n - M);
        }

        return ans;
    }
};