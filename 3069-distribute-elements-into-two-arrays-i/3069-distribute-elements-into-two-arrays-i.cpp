class Solution {
public:
    bool check (vector<int>& arr1,vector<int>& arr2) {
        if (arr1.back() >= arr2.back()) return true;

        return false;
    }

    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1;    
        vector<int> arr2;

        arr1.push_back(nums[0]);    
        arr2.push_back(nums[1]);

        bool flag = check(arr1, arr2);

        for (int i=2; i<nums.size(); i++) {
            if (flag) {
                arr1.push_back(nums[i]);
            } else {
                arr2.push_back(nums[i]);
            }

            flag = check(arr1, arr2);
        }

        int a=0; 

        for (int i=0; i<arr1.size(); i++) {
            nums[a++] = arr1[i];
        }
        for (int i=0; i<arr2.size(); i++) {
            nums[a++] = arr2[i];
        }

        return nums;
    }
};