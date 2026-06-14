class Solution {
public:
    void merge(vector<int>& v, int l, int m, int h) {
        vector<int> temp;

        int i = l;
        int j = m + 1;

        while (i <= m && j <= h) {
            if (v[i] > v[j])
                temp.push_back(v[j++]);
            else
                temp.push_back(v[i++]);
        }

        while (i <= m)
            temp.push_back(v[i++]);

        while (j <= h)
            temp.push_back(v[j++]);

        for (int z = l; z <= h; z++) {
            v[z] = temp[z - l];
        }
    }

    void mergeSort(vector<int>& v, int l, int h) {
        if (l >= h) return;

        int m = l + (h - l) / 2;

        mergeSort(v, l, m);
        mergeSort(v, m + 1, h);

        merge(v, l, m, h);
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};