class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int ans = 0;

        for (int i=0; i<nums.size(); i++) {
            int size = 1;

            int majority = 0;
            if (nums[i] == target) majority++;
            
            if (majority > size / 2) ans++;

            for (int j=i+1; j<nums.size(); j++) {
                size++;

                if (nums[j] == target) majority++;
                
                if (majority > size / 2) ans++;
            }
        }

        return ans;
    }
};