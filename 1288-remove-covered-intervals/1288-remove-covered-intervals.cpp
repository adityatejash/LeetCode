class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
            if (a[0] == b[0]){
                return a[1] > b[1];
            } 
            return a[0] < b[0];
        });

        int count = 0;
        int r = 0;

        for (auto& a : intervals){
            if (a[1] > r){
                count++;
                r = a[1];
            }
        }

        return count;
    }
};