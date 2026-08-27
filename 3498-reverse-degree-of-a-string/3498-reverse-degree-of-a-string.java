class Solution {
    public int reverseDegree(String s) {
        int sum = 0;

        for (int i=0; i<s.length(); i++) {
            int ind = 27 - (s.charAt(i) - 'a' + 1);

            sum += ind * (i + 1);
        }

        return sum;
    }
}