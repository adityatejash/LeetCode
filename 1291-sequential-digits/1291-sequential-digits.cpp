class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        int m = to_string(low).size();
        int M = to_string(high).size();

        string s = "123456789";
        vector<int> ans;

        for (int l=m; l<=M; l++){
            for (int i=0; i+l<=s.size(); i++){
                string t = s.substr(i, l);
                int n = stoi(t);

                if (n >= low && n <= high){
                    ans.push_back(n);
                }
            }
        }

        return ans;
    }
};