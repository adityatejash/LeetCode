class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> v(26, 0);

        for (char c : s) {
            int ind = c - 'a';
            v[ind]++;
        }

        string left = "";
        string mid = "";

        for (int i = 0; i < 26; i++) {
            while (v[i] >= 2) {
                left += char('a' + i);
                v[i] -= 2;
            }

            if (v[i] == 1) {
                mid += char('a' + i);
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        return left + mid + right;
    }
};