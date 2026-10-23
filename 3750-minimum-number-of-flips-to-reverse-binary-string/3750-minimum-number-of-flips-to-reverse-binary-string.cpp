class Solution {
public:
    string toBinary(int n) {
        string s = "";

        while (n > 0) {
            s += to_string(n % 2);
            n /= 2;
        }

        reverse(s.begin(), s.end());

        return s;
    }

    int minimumFlips(int n) {
        string s1 = toBinary (n);

        string s2 (s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());

        int ans = 0;
        for (int i=0; i<s1.size(); i++) {
            if (s1[i] != s2[i]) {
                ans ++;
            }
        }

        return ans;
    }
};