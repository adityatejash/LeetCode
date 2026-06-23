class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        int j = 0;

        while (i < t.size() && j < s.size()){
            if (t[i] == s[j]){
                i++;
                j++;
            } else {
                i++;
            }
        }

        return j == s.size();
    }
};