class Solution {
public:
    bool solve (vector<int>& v, int l, int r, int p1, int p2, bool turn){
        if (l > r) return p1 >= p2;

        if (turn) {
            return solve (v, l+1, r, p1 + v[l], p2, false) ||
                   solve (v, l, r-1, p1 + v[r], p2, false);
        } else {
            return solve (v, l+1, r, p1, p2 + v[l], true) &&
                   solve (v, l, r-1, p1, p2 + v[r], true);
        }
    }
    bool predictTheWinner(vector<int>& nums) {
        return solve (nums, 0, nums.size()-1, 0, 0, true);
    }
};