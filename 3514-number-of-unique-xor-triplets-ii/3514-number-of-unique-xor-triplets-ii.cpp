class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> ans;
        unordered_set<int> pairs;

        int n = nums.size();

        for (int k=0; k<n; k++) {
            for (int i=0; i<=k; i++) {
                pairs.insert(nums[i] ^ nums[k]);
            }

            for (int j : pairs) {
                ans.insert(j ^ nums[k]);
            }
        }

        return ans.size();

        return ans.size();
    }
};