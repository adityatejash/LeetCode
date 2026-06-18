class Solution {
public:
    set<vector<int>> s;
    void solve(int ind, vector<int>& temp, vector<int>& nums){
        if (ind == nums.size()) {
            s.insert(temp);
            return;
        }

        temp.push_back(nums[ind]);
        solve(ind+1, temp, nums);

        temp.pop_back();
        solve(ind+1, temp, nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> temp;

        solve(0, temp, nums);

        vector<vector<int>> ans(s.begin(), s.end());

        return ans;
    }
};