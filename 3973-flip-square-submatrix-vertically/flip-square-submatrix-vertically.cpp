class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> submatrix;

        for (int i = x; i < x + k && i < m; i++) {
            vector<int> temp;
            for (int j = y; j < y + k && j < n; j++) {
                temp.push_back(grid[i][j]);
            }
            submatrix.push_back(temp);
        }

        reverse(submatrix.begin(), submatrix.end());

        for (int i=0; i<submatrix.size(); i++){
            for (int j=0; j<submatrix[0].size(); j++){
                grid[x+i][y+j] = submatrix[i][j];
            }
        }

        return grid;
    }
};