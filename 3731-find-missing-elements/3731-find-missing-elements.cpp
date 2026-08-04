class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_set<int> s;

        int m = nums[0];
        s.insert(nums[0]);
        int M = nums[1];
        s.insert(nums[1]);

        if (m > M) {
            swap (m, M);
        }

        for (int i=2; i<nums.size(); i++){
            if (nums[i] > M) {
                M = nums[i];
            } else if (nums[i] < m) {
                m = nums[i];
            }

            s.insert(nums[i]);
        }

        vector<int> ans;
        for (int i=m; i<=M; i++){
            if (s.find(i) == s.end()){
                ans.push_back(i);
            }
        }

        return ans;
    }
};