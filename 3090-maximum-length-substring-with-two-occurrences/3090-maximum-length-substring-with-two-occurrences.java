class Solution {
    public int maximumLengthSubstring(String s) {
        int[] arr = new int[26];

        int i=0;
        int ans=0;

        for (int j=0; j<s.length(); j++){
            int ind = s.charAt(j) - 'a';
            arr[ind]++;

            while (arr[ind] > 2) {
                arr[s.charAt(i) - 'a']--;
                i++;
            }

            ans = Math.max(ans, j-i+1);
        }

        return ans;
    }
}