class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> m;

        for (int i=0; i<nums.size(); i++){
            m[nums[i]].push_back(i);
        }

        int ans = INT_MAX;
        for (auto& a : m){
            vector<int> ind = a.second;

            if (ind.size() < 3) continue;

            for (int i=2; i<ind.size(); i++){
                ans = min(
                    ans, 
                    2 * (ind[i] - ind[i-2])
                );
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};