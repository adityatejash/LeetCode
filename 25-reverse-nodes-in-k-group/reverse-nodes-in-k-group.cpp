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
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<int> v;

        ListNode* temp = head;
        while (temp != nullptr){
            v.push_back(temp->val);
            temp = temp->next;
        }

        for (int i=0; i+k<=v.size(); i+=k){
            reverse(v.begin()+i, v.begin()+i+k);
        }

        temp = head;
        for (int i=0; i<v.size(); i++){
            temp->val = v[i];
            temp = temp->next;
        }

        return head;

    }
};