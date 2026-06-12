class Solution {
public:
    string invertAndReverse (string s){
        // Invert
        for (char& c : s){
            if (c == '0') c = '1';
            else c = '0';
        }
        // Reverse
        reverse(s.begin(), s.end());

        return s;
    }
    char findKthBit(int n, int k) {
        string s = "0";
        for (int i=1; i<n; i++){
            s = s + "1" + invertAndReverse(s);
        }

        return s[k-1];
    }
};