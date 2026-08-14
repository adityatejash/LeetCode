class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int> v(26, 0);

        int i = 0;        
        int ans = 0;

        for (int j=0; j<s.size(); j++){
            int ind =  s[j] - 'a';
            v[ind]++;

            while (v[ind] > 2) {
                v[s[i] - 'a'] -- ;
                i++;
            }

            ans = max (ans, j-i+1);
        }

        return ans;
    }
};