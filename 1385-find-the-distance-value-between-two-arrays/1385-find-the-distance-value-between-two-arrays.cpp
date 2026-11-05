class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans = 0;

        unordered_set<int> s (arr2.begin(), arr2.end());

        for (int n : arr1) {
            int l = n - d;
            int r = n + d;

            bool isValid = true;
            for (int x : s) {
                if (x <= r && x >= l){
                    isValid = false;
                    break;
                } 
            }

            if(isValid) ans++;
        }

        return ans;
    }
};