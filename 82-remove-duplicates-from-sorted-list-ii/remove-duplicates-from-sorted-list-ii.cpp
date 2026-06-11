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
    ListNode* deleteDuplicates(ListNode* head) {
        map<int, int> m;

        ListNode* temp = head;

        while (temp != nullptr){
            m[temp->val]++;
            temp = temp->next;
        }

        ListNode* newHead = nullptr;
        temp = newHead;
        for (auto& a : m){
            if (a.second == 1) {
                ListNode* node = new ListNode(a.first);

                if (newHead == nullptr) {
                    newHead = node;
                    temp = node;
                } else {
                    temp->next = node;
                    temp = temp->next;
                }
            }
        }

        return newHead;
    }
};