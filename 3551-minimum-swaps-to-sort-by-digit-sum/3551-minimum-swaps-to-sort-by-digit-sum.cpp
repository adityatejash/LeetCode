class Solution {
public:
    int digitSum (int n) {
        int sum = 0;

        while (n) {
            sum += n % 10;
            n /= 10;
        }

        return sum;
    }

    int minSwap(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int swaps = 0;

        unordered_map<int, int> pos;

        for (int i=0; i<n; i++) {
            pos[b[i]] = i;
        }

        for (int i=0; i<n; i++) {
            if (a[i] != b[i]) {
                int j = pos[a[i]];

                pos[b[i]] = j;
                pos[a[i]] = i;

                swap(b[i], b[j]);
                swaps++;
            }
        }

        return swaps;
    }

    int minSwaps(vector<int>& nums) {
        unordered_map<int, int> m;

        for (int n : nums) {
            m[n] = digitSum(n);
        }

        vector<pair<int, int>> v(m.begin(), m.end());

        sort(v.begin(), v.end(), [](auto& a, auto& b){
            if (a.second == b.second) {
                return a.first < b.first;
            }
            return a.second < b.second;
        });

        vector<int> ans;
        for (int i=0; i<v.size(); i++) {
            ans.push_back(v[i].first);
        }

        return minSwap (nums, ans);
    }
};