class Solution {
    public boolean solve (int[] nums, int l, int r, int p1, int p2, boolean turn){
        if (l > r) return p1 >= p2;

        if (turn) {
            return solve (nums, l+1, r, p1 + nums[l], p2, false) ||
                   solve (nums, l, r-1, p1 + nums[r], p2, false);
        } else {
            return solve (nums, l+1, r, p1, p2 + nums[l], true) &&
                   solve (nums, l, r-1, p1, p2 + nums[r], true);
        }
    }
    public boolean predictTheWinner(int[] nums) {
        return solve (nums, 0, nums.length-1, 0, 0, true);
    }
}