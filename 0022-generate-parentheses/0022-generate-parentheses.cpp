class Solution {
public:
    void solve (int n, int open, int close, string s, vector<string>& ans) {
        if (open > n || open < close) return;

        if (open == n && close == n) {
            ans.push_back(s);
            return;
        }

        solve(n, open+1, close, s + "(", ans);
        solve(n, open, close+1, s + ")", ans);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        if (n == 0) return ans;

        string s = "(";
        solve (n, 1, 0, s, ans);

        return ans;
    }
};