class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<bool> v(nums.size(), false);

        for (int n : nums){
            int ind = n - 1;
            v[ind] = true;
        }

        vector<int> ans;

        for (int i=0; i<nums.size(); i++){
            if (v[i] == false) ans.push_back(i+1);
        }

        return ans;
    }
};