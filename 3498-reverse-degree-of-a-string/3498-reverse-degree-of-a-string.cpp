class Solution {
public:
    int reverseInt (char ch) {
        int c = ch - 'a';

        return 26 - c;
    }
    int reverseDegree(string s) {
        int ans = 0;

        for (int i=0; i<s.size(); i++) {
            int ind = i+1;

            ans += ind *  reverseInt (s[i]);
        }

        return ans;
    }
};