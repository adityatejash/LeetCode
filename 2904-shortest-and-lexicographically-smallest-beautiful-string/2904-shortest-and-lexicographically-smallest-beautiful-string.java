class Solution {
    public String shortestBeautifulSubstring(String s, int k) {
        int i=0;
        int count = 0;
        
        int best = Integer.MAX_VALUE;
        String ans = "";
        
        for (int j=0; j<s.length(); j++) {
            if (s.charAt(j) == '1') count++;

            while (count == k) {
                int len = j - i + 1;

                // Java uses [start, end)
                // unlike C++, which uses [start, start + length).
                String current = s.substring(i, j+1);

                if (len < best || (len == best && current.compareTo(ans) < 0)) {
                    best = len;
                    ans = current;
                }

                if (s.charAt(i) == '1') count--;

                i++;
            }
        }

        return ans;
    }
}