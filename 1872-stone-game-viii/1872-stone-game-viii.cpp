class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();

        vector<int> v(stones.begin(), stones.end());

        for (int i=1; i<n; i++) {
            v[i] += v[i-1];
        }

        int best = v.back();

        for (int i=n-2; i >=1; i--) {
            best = max (best, v[i] - best);
        }

        return best;
    }
};