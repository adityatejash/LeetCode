class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        
        unordered_set<int> s;

        for (int n : nums) {
            if (n % k == 0) {
                s.insert(n);
            }
        }

        int n;
        for (int i=1; i<=100; i++) {
            n = k * i;

            if (s.count(n)) {
                continue;
            }

            return n;
        }

        return n+1;
    }
};