class Solution {
    public int firstStableIndex(int[] nums, int k) {
        int n = nums.length;

        int[] M = new int[n];
        M[0] = nums[0];
        for (int i=1; i<n; i++) {
            M[i] = Math.max (M[i-1], nums[i]);
        }

        int[] m = new int[n];
        m[n-1] = nums[n-1];
        for (int i=n-2; i>=0; i--) {
            m[i] = Math.min (m[i+1], nums[i]);
        }

        for (int i=0; i<n; i++) {
            if (M[i] - m[i] <= k) return i;
        }

        return -1;
    }
}