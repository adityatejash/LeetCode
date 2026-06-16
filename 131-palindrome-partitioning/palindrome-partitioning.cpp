class Solution {
public:
    bool isPalindrome(string s){
        string t = s;
        reverse(t.begin(), t.end());

        return s == t;
    }

    void solve (string s, vector<vector<string>>& ans, vector<string>& temp){
        if (s.size() == 0){
            ans.push_back(temp);
            return;
        }

        for (int i=0; i<s.size(); i++){
            string part = s.substr(0, i+1);
            if (isPalindrome(part)){
                temp.push_back(part);
                solve(s.substr(i + 1), ans, temp);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;

        solve(s, ans, temp);

        return ans;
    }
};