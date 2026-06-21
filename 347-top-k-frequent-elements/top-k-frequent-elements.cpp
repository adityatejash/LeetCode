class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;

        for (int n : nums){
            m[n]++;
        }

        vector<vector<int>> bucket(nums.size() + 1);

        for (auto& a : m){
            bucket[a.second].push_back(a.first);
        }

        vector<int> ans;
        for (int i=bucket.size()-1; i>=0; i--){
            for (int n : bucket[i]){
                ans.push_back(n);

                if (ans.size() == k){
                    return ans;
                }
            }
        }

        return ans;
    }
};