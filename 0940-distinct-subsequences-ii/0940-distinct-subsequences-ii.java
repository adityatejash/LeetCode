class Solution {
    static final long MOD = 1000000007;

    public int distinctSubseqII(String s) {
        long x = 1;

        HashMap<Character, Long> m = new HashMap<>();

        for (int i=0; i<s.length(); i++){
            char c = s.charAt(i);

            long y = x;

            x = (2 * x - m.getOrDefault(c, 0L) + MOD) % MOD;

            m.put(c, y);
        }

        return (int)((x - 1 + MOD) % MOD);
    }
}