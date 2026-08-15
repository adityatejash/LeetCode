class Solution {
    public int longestSubsequence(int[] nums) {
        int temp = 0;

        for (int n : nums) {
            temp ^= n;
        }

        if (temp != 0) return nums.length;

        for (int n : nums) {
            if (n != 0) {
                return nums.length - 1;
            }
        }

        return 0;
    }
}