class Solution {
public:
    string solve (const string& s, const int& k) {
        vector<string> v;
        int i=0;
        while (i < s.size()) {
            v.push_back(s.substr(i, k));
            i += k;
        }

        string newS = "";
        for (string st : v) {
            int n = 0;

            for (char c : st) {
                n += c - '0';
            }

            newS += to_string(n);
        }

        return newS;
    }
    
    string digitSum(string s, int k) {
        while (s.size() > k) {
            s = solve(s, k);
        }  

        return s;
    }
};