class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> m;

        for (int n : deck){
            m[n]++;
        }

        int g = 0;

        for (auto& a : m){
            g = gcd(g, a.second);
        }

        return g > 1;
    }
};