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
    ListNode* createNode (unordered_set<int>& s, ListNode* head){
        ListNode* newHead = new ListNode(-1);
        ListNode* temp = newHead;

        while (head != nullptr){
            if (s.find(head->val) == s.end()){
                temp->next = new ListNode(head->val);
                temp = temp->next;
            }
            head = head->next;
        }

        newHead = newHead->next;

        return newHead;
    }
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> s;
        for (int i : nums){
            s.insert(i);
        }

        return createNode(s, head);
    }
};