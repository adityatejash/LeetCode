class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> m = new HashMap<>();

        for (int i=0; i<nums.length; i++){
            int n = target - nums[i];

            if (m.containsKey(n)) {
                return new int[]{m.get(n), i};
            }

            m.put(nums[i], i);
        }

        return new int[]{};
    }
}