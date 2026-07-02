class Solution {
public:
    char check(int r) {
        if (r >= 0 && r <= 9)
            return '0' + r;
        else if (r == 10)
            return 'a';
        else if (r == 11)
            return 'b';
        else if (r == 12)
            return 'c';
        else if (r == 13)
            return 'd';
        else if (r == 14)
            return 'e';
        return 'f';
    }

    string toHex(int num) {
        if (num == 0)
            return "0";

        unsigned int n = num;
        string ans = "";

        while (n > 0) {
            int r = n % 16;
            ans += check(r);
            n /= 16;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};