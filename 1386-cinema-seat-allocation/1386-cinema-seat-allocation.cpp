class Solution {
public:
    int solve(vector<bool>& v) {
        bool left = !v[2] && !v[3] && !v[4] && !v[5];
        bool middle = !v[4] && !v[5] && !v[6] && !v[7];
        bool right = !v[6] && !v[7] && !v[8] && !v[9];

        if (left && right) return 2;

        if (left || middle || right) return 1;

        return 0;
    }

    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map <int, vector<int>> m;

        for (auto& a : reservedSeats) {
            int row = a[0];
            int col = a[1];

            m[row].push_back(col);
        }

        int ans = 2*n;
        for (auto& a : m) {
            vector<bool> temp (11, false);

            for (int n : a.second) {
                temp[n] = true;
            }

            ans -= 2;
            ans += solve (temp);
        }

        return ans;
    }
};