class Solution {
public:
    bool check(char c) {
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) return true;

        return false;
    }
    string reverseOnlyLetters(string s) {
        int i=0;
        int j=s.size()-1;

        while (i < j) {
            if (!check(s[i])){
                i++;
                continue;
            }

            if (!check(s[j])){
                j--;
                continue;
            }
            swap(s[i++], s[j--]);
        }

        return s;
    }
};