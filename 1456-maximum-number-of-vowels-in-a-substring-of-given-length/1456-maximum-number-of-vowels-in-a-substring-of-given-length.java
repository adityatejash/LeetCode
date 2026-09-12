class Solution {
    public boolean isVowel (Character c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    public int maxVowels(String s, int k) {
        int n = s.length();

        int[] count = new int[n];

        count[0] = 0;
        if (isVowel(s.charAt(0))) count[0] = 1;

        for (int i=1; i<n; i++) {
            count[i] = count[i-1];

            if (isVowel(s.charAt(i))) count[i]++;
        }

        int ans = count[k-1];

        for (int j=k; j<n; j++) {
            int i = j - k;

            int vowels = count[j] - count[i];

            ans = Math.max(ans, vowels);
        }

        return ans;
    }
}