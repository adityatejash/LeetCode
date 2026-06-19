class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        
        int highest = 0;
        int currSum = 0;

        for (int i=0; i<n; i++){
            currSum += gain[i];
            highest = max(highest, currSum);
        }

        return highest;
    }
};