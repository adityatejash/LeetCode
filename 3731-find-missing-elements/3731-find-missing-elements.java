class Solution {
    public List<Integer> findMissingElements(int[] nums) {
        HashSet<Integer> set = new HashSet<>();

        int m = nums[0];
        int M = nums[1];

        if (m > M) {
            int t = m;
            m = M; 
            M = t;
        }

        set.add(m);
        set.add(M);

        for (int i=2; i<nums.length; i++){
            if (nums[i] < m) {
                m = nums[i];
            } else if (nums[i] > M) {
                M = nums[i];
            }

            set.add(nums[i]);
        }

        List<Integer> ans = new ArrayList<>();
        for (int i=m; i<=M; i++){
            if (!set.contains(i)) {
                ans.add(i);
            }
        }

        return ans;
    }
}