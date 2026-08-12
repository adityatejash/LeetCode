class Solution {
    public int maxSubarrayLength(int[] nums, int k) {
        int n = nums.length;

        HashMap<Integer, Integer> h = new HashMap<>();

        int i = 0;
        int j = 0;
        int ans = 0;

        while (j < n) {
            if (h.containsKey(nums[j])) {
                h.put(nums[j], h.get(nums[j]) + 1);
            } else {
                h.put(nums[j], 1);
            }

            while (i < j && h.get(nums[j]) > k) {
                h.put (nums[i], h.get(nums[i]) - 1);
                i++;
            }

            ans = Math.max(ans, j-i+1);
            j++;
        }

        return ans;
    }
}