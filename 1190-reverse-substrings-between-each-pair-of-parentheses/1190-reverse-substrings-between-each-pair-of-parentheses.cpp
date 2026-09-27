class Solution {
public:
    string reverseParentheses(string s) {
        vector<pair<int, int>> pairs;
        vector<int> open;

        for (int i=0; i<s.size(); i++) {
            if (s[i] == '('){
                open.push_back(i);
            } else if (s[i] == ')') {
                int t = open.back();
                open.pop_back();

                pairs.push_back({t, i});
            }
        }

        

        for (auto& p : pairs) {
            int l = p.first;
            int r = p.second;

            reverse(s.begin() + l + 1, s.begin() + r);
        }

        string ans = "";
        for (char c : s) {
            if (c == '(' || c == ')') continue;

            ans += c;
        }

        return ans;
    }
};