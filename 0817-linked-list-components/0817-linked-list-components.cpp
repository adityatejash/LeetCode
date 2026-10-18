/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> s (nums.begin(), nums.end());
        
        vector<vector<int>> vec;
        vector<int> v;
        
        ListNode* temp = head;

        while (temp != nullptr) {
            if (s.count(temp->val)) {
                v.push_back(temp->val);
            } else {
                if (!v.empty()) {
                    vec.push_back(v);
                    v.clear();
                }
            }

            temp = temp->next;
        }

        if (!v.empty()) {
            vec.push_back(v);
        }

        return vec.size();
    }
};