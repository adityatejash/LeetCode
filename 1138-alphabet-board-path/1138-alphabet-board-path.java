class Solution {
    String fill(int x1, int y1, int x2, int y2) {
        int x = x2 - x1;
        int y = y2 - y1;

        String s = "";
        
        if (x1 == 5) {
            int i = Math.abs(x);

            while (i > 0) {
                s += 'U';
                i--;
            }

            x = 0;
        }

        if (x2 == 5) {
            int i = Math.abs(y);

            if (y >= 0) {
                while (i > 0) {
                    s += 'R';
                    i--;
                }
            } else {
                while (i > 0) {
                    s += 'L';
                    i--;
                }
            }

            y = 0;
        }

        if (x >= 0) {
            int i = x;
            while (i > 0) {
                s += 'D';
                i--;
            }
        } else {
            int i = Math.abs(x);
            while (i > 0) {
                s += 'U';
                i--;
            }
        }

        if (y >= 0) {
            int i = y;
            while (i > 0) {
                s += 'R';
                i--;
            }
        } else {
            int i = Math.abs(y);
            while (i > 0) {
                s += 'L';
                i--;
            }
        }

        return s;
    }

    int[] search(char c) {
        int x = (c - 'a') / 5;
        int y = (c - 'a') % 5;

        return new int[]{x, y};
    }

    public String alphabetBoardPath(String target) {
        String ans = "";

        int x1 = 0;
        int y1 = 0;

        for (int i=0; i<target.length(); i++) {
            char c = target.charAt(i);

            int[] pos = search(c);

            int x2 = pos[0];
            int y2 = pos[1];

            ans += fill (x1, y1, x2, y2) + '!';

            x1 = x2;
            y1 = y2;
        }

        return ans;
    }
}