class Solution {
public:
    string removeOuterParentheses(string s) {
        vector<int> v;

        int temp = 0;
        for (char c : s) {
            if (c == '(') {
                temp++;
                v.push_back(temp);
            } else {
                temp--;
                v.push_back(temp);
            }
        }

        string ans = "";
        for (int i=0; i<s.size(); i++) {
            if (v[i] == 1 && s[i] == '(') continue;

            if (v[i] == 0) continue;

            ans += s[i];
        }

        return ans;
    }
};