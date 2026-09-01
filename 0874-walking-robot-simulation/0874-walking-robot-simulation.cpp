class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set <pair<int, int>> obs;

        for (auto& a : obstacles) {
            obs.insert({a[0], a[1]});
        }

        int x = 0;
        int y = 0;
        
        int dx = 0;
        int dy = 1;

        int ans = 0;

        for (int c : commands) {
            if (c == -2) {
                int t = dx;
                dx = -dy;
                dy = t;
            } else if (c == -1) {
                int t = dx;
                dx = dy;
                dy = -t;
            } else {
                for (int i=0; i<c; i++) {
                    int nx = x + dx;
                    int ny = y + dy;

                    if (obs.count({nx, ny})) break;

                    x = nx;
                    y = ny;
                
                    ans = max(ans, x*x + y*y);
                }
            }
        }

        return ans;
    }
};