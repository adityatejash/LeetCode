class Solution {
public:
    int count1s (int n){
        int c = 0;
        while (n){
            if (n % 2 == 1) c++;
            n/= 2;
        }
        return c;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [&](int a, int b){
            int bitA = count1s(a);
            int bitB = count1s(b);
            
            if (bitA == bitB){
                return a < b;
            } 
            
            return bitA < bitB;
        });

        return arr;
    }
};