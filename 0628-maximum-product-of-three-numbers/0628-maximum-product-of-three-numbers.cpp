class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int mx1 = INT_MIN;
        int mx2 = INT_MIN;
        int mx3 = INT_MIN;
        
        int mn1 = INT_MAX;
        int mn2 = INT_MAX;

        // mn2 <= mn1 <= mx1 <= mx2 <= mx3

        for (int n : nums) {
            // Minimum
            if (n <= mn2) {
                mn1 = mn2;
                mn2 = n;
            } else if (n <= mn1) {
                mn1 = n;
            }

            // Maximum
            if (n >= mx3) {
                mx1 = mx2;
                mx2 = mx3;
                mx3 = n;
            } else if (n >= mx2) {
                mx1 = mx2;
                mx2 = n;
            } else if (n >= mx1) {
                mx1 = n;
            }       
        }

        return max (
            mn1 * mn2 * mx3,
            mx1 * mx2 * mx3
        );
    }
};