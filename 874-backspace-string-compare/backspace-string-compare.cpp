class Solution {
public:
    string solve (string& s){
        string newS = "";

        for (char c : s){
            if (c >= 'a' && c <= 'z') newS += c;

            if (c == '#' && !newS.empty()) newS.pop_back();
        }

        return newS;
    }
    bool backspaceCompare(string s, string t) {
        return solve(s) == solve(t);
    }
};