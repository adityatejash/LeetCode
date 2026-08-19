class Solution {
    public int solve (boolean[] v) {
        boolean left = !v[2] && !v[3] && !v[4] && !v[5];
        boolean middle = !v[4] && !v[5] && !v[6] && !v[7];
        boolean right = !v[6] && !v[7] && !v[8] && !v[9];

        if (left && right) return 2;

        if (left || right || middle) return 1;

        return 0;
    }
    public int maxNumberOfFamilies(int n, int[][] reservedSeats) {
        HashMap<Integer, ArrayList<Integer>> m = new HashMap<>();

        for (var a : reservedSeats) {
            int row = a[0];
            int col = a[1];

            if (!m.containsKey(row)) {
                m.put(row, new ArrayList<>());
            }

            m.get(row).add(col);
        }

        int ans = 2 * n;
        for (var row : m.entrySet()) {
            boolean[] temp = new boolean[11];

            for (var seat : row.getValue()) {
                temp[seat] = true;
            }

            ans -= 2;
            ans += solve (temp);            
        }

        return ans;
    }
}