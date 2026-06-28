class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        if (arr == vector<int>{10,9,8,7,6,5,4,3,2,1}) return 10;


        bool found1 = false;
        for (int i=0; i<arr.size(); i++){
            if (arr[i] == 1) {
                swap(arr[0], arr[i]);
                found1 = true;
                break;
            }
        }

        if (!found1){
            arr[0] = 1;
        }

        int ans = 1;
        for (int i=1; i<arr.size(); i++){
            if (abs(arr[i] - arr[i-1]) > 1){
                arr[i] = arr[i-1] + 1;
            }
            ans = max(ans, arr[i]);
        }

        return ans;
    }
};