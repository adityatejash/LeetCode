class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        vector<int> v (n, 0);

        for (int i=1; i<n; i+=2){
            v[i] = 1;
        }

        int count1 = 0;
        for (int i=0; i<n; i++){
            int num = s[i] - '0';
            if (num != v[i]) count1++;
        }

        for (int i=0; i<n; i++){
            if (v[i] == 0) v[i] = 1;
            else v[i] = 0;
        }

        int count2 = 0;
        for (int i=0; i<n; i++){
            int num = s[i] - '0';
            if (num != v[i]) count2++;
        }

        return min(count1,count2);

    }
};