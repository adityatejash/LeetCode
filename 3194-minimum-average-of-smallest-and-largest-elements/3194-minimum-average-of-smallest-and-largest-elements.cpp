class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        vector<double> averages;
        double smallest = INT_MAX;

        sort(nums.begin(), nums.end());

        int m = 0;
        int M = nums.size() - 1;

        while (m < M){
            double temp = (nums[m] + nums[M]) / 2.0;
            averages.push_back(temp);
            if (temp < smallest) smallest = temp;
            m++;
            M--;
        }

        return smallest;
    }
};