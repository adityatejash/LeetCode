class Solution {
public:
    int solve (vector<int>& nums, int target, int ind, int sum) {
        if (nums.size() == ind) {
            if (sum == target) {
                return 1;
            }

            return 0;
        }

        int add = solve (nums, target, ind+1, sum + nums[ind]);

        int sub = solve (nums, target, ind+1, sum - nums[ind]);

        return add + sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve (nums, target, 0, 0);
    }
};