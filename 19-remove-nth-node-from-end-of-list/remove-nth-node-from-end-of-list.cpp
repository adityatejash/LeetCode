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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        vector<int> v;

        while (temp != nullptr){
            v.push_back(temp->val);
            temp = temp->next;
        }

        n = v.size() - n;
        
        ListNode* root = nullptr;
        temp = nullptr;

        for (int i = 0; i < v.size(); i++) {
            if (i == n) continue;

            if (root == nullptr) {
                root = new ListNode(v[i]);
                temp = root;
            } else {
                temp->next = new ListNode(v[i]);
                temp = temp->next;
            }
        }

        return root;
    }
};