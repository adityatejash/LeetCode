class Solution {
    public int stoneGameVIII(int[] stones) {
        int n = stones.length;

        // clone
        int[] arr = new int[n];
        for (int i=0; i<n; i++) {
            arr[i] = stones[i];
        }
        
        for (int i=1; i<n; i++) {
            arr[i] += arr[i-1];
        }

        int best = arr[n-1];

        for (int i=n-2; i>=1; i--) {
            best = Math.max (best, arr[i] - best);
        }

        return best;
    }
}