class Solution {
    public int solve (int[] nums, int n, int k) {
        int count = 0;

        for (int i=0; i+k<=nums.length; i++){
            for (int j=i; j<i+k; j++){
                if (nums[j] == n) {
                    count++;
                    break;
                }
            }
        }

        return count;
    }
    public int largestInteger(int[] nums, int k) {
        int ans = -1;

        for (int n : nums) {
            if (solve (nums, n, k) == 1) {
                ans = Math.max(ans, n);
            }
        }

        return ans;
    }
}