class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> onesRow;
        vector<int> zerosRow;
        
        vector<int> onesCol;
        vector<int> zerosCol;

        // row
        for (int i=0; i<grid.size(); i++){
            int one = 0;
            int zero = 0;

            for (int j=0; j<grid[0].size(); j++){
                if (grid[i][j] == 0) zero++;
                else one++;
            }
            
            onesRow.push_back(one);
            zerosRow.push_back(zero);
        }

        // col
        for (int j=0; j<grid[0].size(); j++){
            int one = 0;
            int zero = 0;

            for (int i=0; i<grid.size(); i++){
                if (grid[i][j] == 1) one++;
                else zero++;
            }

            onesCol.push_back(one);
            zerosCol.push_back(zero);
        }

        for (int i=0; i<grid.size(); i++){
            for (int j=0; j<grid[0].size(); j++){
                grid[i][j] = onesRow[i] + onesCol[j] - zerosRow[i] - zerosCol[j];
            }
        }

        return grid;
    }
};