class Solution {
    public int minimumDeletions(int[] nums) {
        int minimum = Integer.MAX_VALUE;
        int maximum = Integer.MIN_VALUE;

        int minIndex = -1;
        int maxIndex = -1;

        for (int i = 0; i < nums.length; i++) {
            if (nums[i] < minimum) {
                minimum = nums[i];
                minIndex = i;
            }

            if (nums[i] > maximum) {
                maximum = nums[i];
                maxIndex = i;
            }
        }

        int n = nums.length;

        // deleting from front
        int front = Math.max(maxIndex, minIndex) + 1;

        // deleting from back
        int back = n - Math.min(minIndex, maxIndex);

        // deleting from either front or back
        int mixed;
        if (minIndex < maxIndex) {
            mixed = (minIndex + 1) + (n - maxIndex);
        } else {
            mixed = (maxIndex + 1) + (n - minIndex);
        }

        return Math.min(front, Math.min(back, mixed));
    }
}