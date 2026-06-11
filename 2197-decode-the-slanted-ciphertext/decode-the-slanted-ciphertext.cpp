class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        if (encodedText.size() == 0) return "";

        int column = encodedText.size() / rows;

        vector<vector<char>> v(rows, vector<char>(column));

        int c = 0;

        for (int i=0; i<rows; i++){
            for (int j=0; j<column; j++){
                v[i][j] = encodedText[c++];
            }
        }

        string s = "";
        for (int start=0; start<column; start++){
            int i = 0;
            int j = start;

            while (i < rows && j < column){
                s += v[i++][j++];
            }
        }

        while (s.back() == ' '){
            s.pop_back();
        }

        return s;
    }
};