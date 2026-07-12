class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int> s(arr.begin(), arr.end());
        vector<int> v(s.begin(), s.end());

        unordered_map<int, int> m;
        for (int i=0; i<v.size(); i++){
            m[v[i]] = i + 1; 
        }

        for (int i=0; i<arr.size(); i++){
            if (m.find(arr[i]) != m.end()){
                arr[i] = m[arr[i]];
            }
        }

        return arr;

    }
};