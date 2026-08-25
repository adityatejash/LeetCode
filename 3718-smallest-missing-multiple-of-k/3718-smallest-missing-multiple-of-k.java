class Solution {
    public int missingMultiple(int[] nums, int k) {
        HashSet<Integer> s = new HashSet<>();

        for (int n : nums) {
            if (n % k == 0) {
                s.add(n);
            }
        }

        int n = 1;
        for (int i=1; i<=100; i++) {
            n = k * i;

            if (s.contains(n)) {
                continue;
            }

            return n;
        }

        return n+1;
    }
}