class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        
        unordered_map<int, vector<int>> m;
        for (int i=0; i<n; i++) {
            m[nums[i]].push_back(i);
        }

        vector<int> v(n, INT_MAX);
        for (auto& [val, indices] : m) {
            int sz = indices.size();
            if (sz <= 1) continue;

            for (int i=0; i<sz; i++) {
                int curr = indices[i];
                int prev = indices[(i - 1 + sz) % sz];
                int next = indices[(i + 1) % sz];

                int d1 = abs(curr - prev);
                int d2 = abs(curr - next);

                d1 = min (d1, n - d1);
                d2 = min (d2, n - d2);

                v[curr] = min (d1, d2);
            }
        }
        
        vector<int> ans;
        for (int q : queries) {
            if (v[q] == INT_MAX) {
                ans.push_back(-1);
            } else {
                ans.push_back(v[q]);
            }
        }

        return ans;
    }
};