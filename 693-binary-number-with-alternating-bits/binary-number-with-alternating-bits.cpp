class Solution {
public:
    string intToBinary (int n){
        string s = "";

        while (n > 0){
            s += to_string(n % 2);
            n /= 2;
        }

        reverse(s.begin(), s.end());

        return s;
    }
    bool hasAlternatingBits(int n) {
        string s = intToBinary(n);

        char c = s[0];

        for (int i=1; i<s.size(); i++){
            if (c == s[i]){
                return false;
            } else {
                c = s[i];
            }
        }

        return true;
    }
};