class Solution {
    public int robotSim(int[] commands, int[][] obstacles) {
        TreeSet<String> obs = new TreeSet<>();

        for (int[] a : obstacles) {
            obs.add(a[0] + "," + a[1]);
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

                    if (obs.contains(nx + "," + ny)) break;

                    x = nx;
                    y = ny;

                    ans = Math.max(ans, x*x + y*y);
                }
            }
        }

        return ans;
    }
}