class Solution {
public:
    vector<string> result;

    void solve (int ind, string& digits, string& temp, unordered_map<int, string>& m){
        if (ind >= digits.size()){
            result.push_back(temp);
            return;
        }

        char c = digits[ind];
        string s = m[c - '0']; 

        for (int i=0; i<s.size(); i++){
            temp.push_back(s[i]);
            solve(ind + 1, digits, temp, m);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return {};

        unordered_map<int, string> m = {
            {2, "abc"},
            {3, "def"},
            {4, "ghi"},
            {5, "jkl"},
            {6, "mno"},
            {7, "pqrs"},
            {8, "tuv"},
            {9, "wxyz"}
        };

        string temp = "";

        solve(0, digits, temp, m);

        return result;
    }
};