class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int r1 = 0;
        int r2 = 0;
        int r3 = 0;

        for (int n : stones) {
            if (n % 3 == 0) r1++;
            else if (n % 3 == 1) r2++;
            else r3++;
        }

        // even
        if (r1 % 2 == 0) {
            return r2 > 0 && r3 > 0;
        }

        // odd
        return abs(r2-r3) > 2;
    }
};