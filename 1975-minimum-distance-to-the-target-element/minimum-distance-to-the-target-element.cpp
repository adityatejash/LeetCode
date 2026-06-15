class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int ans = INT_MAX;

        for (int i=0; i<nums.size(); i++){
            if (target == nums[i]){
                ans = min(abs(i-start), ans);
            }
        }

        return ans;
    }
};