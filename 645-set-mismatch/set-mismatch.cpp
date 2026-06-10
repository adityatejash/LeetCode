class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int, int> m;
        int sz = nums.size();

        for (int n : nums){
            m[n]++;
        }

        int naturalSum = sz * (sz + 1) / 2;
        int sumArrayWithoutDuplicate = 0;
        int duplicate = -1;

        for (auto& a : m){
            if (a.second > 1)
                duplicate = a.first;

            sumArrayWithoutDuplicate += a.first;
        }

        return {duplicate, naturalSum - sumArrayWithoutDuplicate};
    }
};