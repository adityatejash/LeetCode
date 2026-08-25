class Solution {
    public int solve (int[] nums, int target, int ind, int sum) {
        if (nums.length == ind) {
            if (sum == target) {
                return 1;
            }

            return 0;
        }

        int add = solve (nums, target, ind+1, sum + nums[ind]);
        
        int sub = solve (nums, target, ind+1, sum - nums[ind]);
        
        return add + sub;    
    }
    public int findTargetSumWays(int[] nums, int target) {
        return solve (nums, target, 0, 0);
    }
}