class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> vec(n, 0);

        for (int i=1; i<n; i++){
            if (nums[i] - nums[i-1] > maxDiff){
                vec[i] = vec[i-1] + 1;
            } else {
                vec[i] = vec[i-1];
            }
        }

        vector<bool> ans;
        for (auto& q : queries){
            int u = q[0];
            int v = q[1];

            ans.push_back(vec[u] == vec[v]);
        }

        return ans;
    }
};