class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<vector<char>> v(m, vector<char>(n, '#'));

        for (int i=0; i<n; i++) {
            v[0][i] = '.';
        }

        for (int i=0; i<m; i++) {
            v[i][n-1] = '.';
        }

        vector<string> ans;

        for (auto& a : v) {
            string s = "";
            for (char c : a) {
                s += c;
            }
            ans.push_back(s);
        }

        return ans;
    }
};