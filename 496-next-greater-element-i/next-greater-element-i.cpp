class Solution {
public:
    vector<int> solve(vector<vector<int>>& v1, vector<int>& v2){
        vector<int> ans;

        for (auto& a : v1){
            int value = a[0];
            int ind = a[1];
            bool found = false;

            for (int i = ind + 1; i < v2.size(); i++){
                if (v2[i] > value) {
                    ans.push_back(v2[i]);
                    found = true;
                    break;
                }
            }

            if (!found) ans.push_back(-1);
        }

        return ans;
    }

    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> temp;

        for (int i = 0; i < nums1.size(); i++){
            for (int j = 0; j < nums2.size(); j++){
                if (nums1[i] == nums2[j]){
                    temp.push_back({nums1[i], j});
                    break;
                }
            }
        }

        return solve(temp, nums2);
    }
};