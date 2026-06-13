class Solution {
public:
    int solve (string& s, vector<int>& v){
        int sum = 0;
        for (int i=0; i<s.size(); i++){
            int ind = s[i] - 'a';
            sum += v[ind];
        }

        return sum % 26;
    }

    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";

        for (string s : words){
            int a = solve(s, weights);
            a = 26 - a - 1;
            char c = 'a' + a;
            ans += c;
        }

        return ans;
    }
};