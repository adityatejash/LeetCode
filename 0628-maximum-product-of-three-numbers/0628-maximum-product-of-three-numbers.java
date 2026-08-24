class Solution {
    public int maximumProduct(int[] nums) {
        int mx1 = Integer.MIN_VALUE;
        int mx2 = Integer.MIN_VALUE;
        int mx3 = Integer.MIN_VALUE;
        
        int mn1 = Integer.MAX_VALUE;
        int mn2 = Integer.MAX_VALUE;

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

        return Math.max (
            mn1 * mn2 * mx3,
            mx1 * mx2 * mx3
        );
    }
}