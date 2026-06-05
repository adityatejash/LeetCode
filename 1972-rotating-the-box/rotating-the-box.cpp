class Solution {
public:
    void solve(vector<char>& v) {
        int ob = 0;

        for (int i = 0; i < v.size(); i++) {

            if (v[i] == '#') {
                ob++;
                v[i] = '.';
            }

            else if (v[i] == '*') {

                int a = i - 1;

                while (ob > 0) {
                    v[a--] = '#';
                    ob--;
                }
            }
        }

        int a = v.size() - 1;

        while (ob > 0) {
            v[a--] = '#';
            ob--;
        }
    }

    vector<vector<char>> rotate(vector<vector<char>>& v) {
        int m = v.size();
        int n = v[0].size();

        vector<vector<char>> ans(n, vector<char>(m));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans[j][m - 1 - i] = v[i][j];
            }
        }

        return ans;
    }

    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {

        int m = boxGrid.size();

        for (int i = 0; i < m; i++) {
            solve(boxGrid[i]);
        }

        return rotate(boxGrid);
    }
};