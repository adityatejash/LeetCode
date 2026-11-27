class Solution {
public:
    bool checkString(string s) {
        vector<int> v;

        for (int i=0; i<s.size(); i++) {
            if (s[i] == 'a') v.push_back(i);
        }

        for (int i=0; i<s.size(); i++) {
            if (s[i] == 'b') v.push_back(i);
        }

        for (int i=1; i<s.size(); i++) {
            if (s[i-1] > s[i]) return false;
        }

        return true;
    }
};