class Solution {
public:
    bool solve (string s, string word){
        if (word.find(s) != string::npos){
            return true;
        }
        return false;
    }
    int numOfStrings(vector<string>& patterns, string word) {
        int ans = 0;
        for (string s : patterns){
            if (solve(s, word)) ans++;
        }

        return ans;
    }
};