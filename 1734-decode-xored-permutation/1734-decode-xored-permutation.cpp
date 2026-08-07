class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int n = encoded.size() + 1;

        int total = 0;
        for (int i = 1; i<= n; i++){
            total ^= i;
        }

        int odd = 0;
        for (int i=1; i<encoded.size(); i+=2){
            odd ^= encoded[i];
        }

        vector<int> ans(n);
        ans[0] = total ^ odd;

        for (int i=0; i<encoded.size(); i++){
            ans[i+1] = ans[i] ^ encoded[i];
        }

        return ans;
    }
};