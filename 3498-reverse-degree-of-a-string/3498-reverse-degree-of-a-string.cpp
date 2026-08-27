class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0;

        for (int i=0; i<s.size(); i++) {
            int revInd = 27 - (s[i] - 'a' + 1);

            sum += revInd * (i + 1);
        }

        return sum;
    }
};