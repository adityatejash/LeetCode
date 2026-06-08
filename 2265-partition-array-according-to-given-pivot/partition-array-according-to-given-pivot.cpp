class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> v;

        int count = 0;

        for (int n : nums){
            if (n == pivot) count++;

            if (n < pivot){
                v.push_back(n);
            }
        }

        while (count--){
            v.push_back(pivot);
        }

        for (int n : nums){
            if (n > pivot) v.push_back(n);
        }

        return v;


    }
};