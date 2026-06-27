class Solution {
public:
    bool isZero(vector<vector<int>>& mat, int i, int j) {
        // Check row
        for (int x=0; x<mat[0].size(); x++) {
            if (x != j && mat[i][x] == 1)
                return false;
        }

        // Check column
        for (int x=0; x<mat.size(); x++) {
            if (x != i && mat[x][j] == 1)
                return false;
        }

        return true;
    }

    int numSpecial(vector<vector<int>>& mat) {
        int ans = 0;

        for (int i=0; i<mat.size(); i++) {
            for (int j=0; j<mat[0].size(); j++) {
                if (mat[i][j] == 1 && isZero(mat, i, j)) {
                    ans++;
                }
            }
        }

        return ans;
    }
};