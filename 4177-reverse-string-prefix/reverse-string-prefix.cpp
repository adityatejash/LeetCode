class Solution {
public:
    string reversePrefix(string s, int k) {
        string t = "";

        for (int i=k-1; i>=0; i--){
            t += s[i];
        }

        for (int i=0; i<k; i++){
            s[i] = t[i];
        }

        return s;
    }
};