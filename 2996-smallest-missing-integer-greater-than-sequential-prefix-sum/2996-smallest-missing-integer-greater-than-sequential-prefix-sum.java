class Solution {
    public int missingInteger(int[] nums) {
        HashSet<Integer> s = new HashSet<>();
        for (int n : nums) {
            s.add(n);
        }

        int sum = nums[0];
        for(int i=1; i<nums.length; i++){
            if (nums[i] != nums[i-1] + 1) break;
        
            sum += nums[i];
        }

        while (s.contains(sum)) {
            sum++;
        }

        return sum;
    }
}