class Solution {
public:
    int count (unordered_map<int, int>& m, int& n){
        int ans = 0;
        for (auto& a : m){
            if (a.first < n) ans += a.second;
        }

        return ans;
    }
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        unordered_map<int, int> m;

        for (int n : nums){
            m[n]++;
        }

        for (int i=0; i<nums.size(); i++){
            nums[i] = count(m, nums[i]);
        }

        return nums;
    }
};