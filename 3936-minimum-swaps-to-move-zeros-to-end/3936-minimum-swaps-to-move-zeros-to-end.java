class Solution {
    public int minimumSwaps(int[] nums) {
        int n = nums.length;

        int i=0;
        int j=n-1;

        int ans = 0;
        while (i <= j) {
            if (nums[i] == 0 && nums[j] != 0) {
                int t = nums[i];
                nums[i] = nums[j];
                nums[j] = t;
                
                j--;
                ans++;
            }

            if (nums[i] != 0) {
                i++;
            } else if (nums[j] == 0) {
                j--;
            }            
        }

        return ans;
    }
}