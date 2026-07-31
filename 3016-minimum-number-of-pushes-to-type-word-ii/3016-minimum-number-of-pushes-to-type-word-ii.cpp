class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int> m;

        string s = "";
        for (char c : word){
            if (m.find(c) == m.end()){
                s += c;
            }
            m[c]++;
        }

        sort(s.begin(), s.end(), [&](char a, char b){
            return m[a] > m[b];
        });

        int ans = 0;
        for (int i=0; i<s.size(); ++i){

            ans += (i / 8 + 1) * m[s[i]];
        }

        return ans;
    }
};