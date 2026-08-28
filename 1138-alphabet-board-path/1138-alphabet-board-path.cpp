class Solution {
public:
    string fill(int x1, int y1, int x2, int y2) {
        int x = x2 - x1;
        int y = y2 - y1;

        string s = "";
        
        if (x1 == 5) {
            int i = abs(x);

            while (i) {
                s += 'U';
                i--;
            }

            x = 0;
        }

        if (x2 == 5) {
            int i = abs(y);

            if (y >= 0) {
                while (i) {
                    s += 'R';
                    i--;
                }
            } else {
                while (i) {
                    s += 'L';
                    i--;
                }
            }

            y = 0;
        }

        if (x >= 0) {
            int i = x;
            while (i) {
                s += 'D';
                i--;
            }
        } else {
            int i = abs(x);
            while (i) {
                s += 'U';
                i--;
            }
        }

        if (y >= 0) {
            int i = y;
            while (i) {
                s += 'R';
                i--;
            }
        } else {
            int i = abs(y);
            while (i) {
                s += 'L';
                i--;
            }
        }

        return s;
    }

    vector<int> search(char c) {
        int x = (c - 'a') / 5;
        int y = (c - 'a') % 5;

        return {x, y};
    }

    string alphabetBoardPath(string target) {
        string ans = "";

        int x1 = 0;
        int y1 = 0;

        for (char c : target) {
            vector<int> pos = search(c);

            int x2 = pos[0];
            int y2 = pos[1];

            ans += fill (x1, y1, x2, y2) + '!';

            x1 = x2;
            y1 = y2;
        }

        return ans;
    }
};