class Solution {
public:
    int findClosest(vector<int>& power, int n){
        vector<int> closest(power.size(), 0);

        for (int i=0; i<power.size(); i++){
            closest[i] = abs(n - power[i]);
        }

        int minIdx = 0;
        for (int i=1; i<closest.size(); i++){
            if (closest[i] < closest[minIdx]) minIdx = i;
        }

        return minIdx;
    }

    int minOperations(int n) {
        vector<int> power;

        int i = 0;
        while (true){
            int n = pow(2, i);

            if (n > 100000) break;

            i++;
            power.push_back(n);
        }

        int ans = 0;
        while (n){
            int idx = findClosest(power, n);
            n = abs(n - power[idx]);
            ans ++;
        }

        return ans;    
    }
};