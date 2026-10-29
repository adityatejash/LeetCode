class Solution {
public:
    bool isPathCrossing(string path) {
        int i = 0;
        int j = 0;
        
        set<pair<int, int>> s;
        s.insert({i,j});

        for (char c : path) {
            if (c == 'N') j++;
            else if (c == 'E') i++;
            else if (c == 'W') i--;
            else if (c == 'S') j--;

            if (s.count({i,j})) return true;

            s.insert({i,j});
        }

        return false;
    }
};