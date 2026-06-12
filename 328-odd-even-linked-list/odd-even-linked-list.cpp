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
    ListNode* createList (vector<int>& v1, vector<int>& v2){
        if (v1.size() == 0) return nullptr;

        ListNode* head = new ListNode(v1[0]);
        ListNode* temp = head;
        for (int i=1; i<v1.size(); i++){
            temp->next = new ListNode(v1[i]);
            temp = temp->next;
        }

        for (int i=0; i<v2.size(); i++){
            temp->next = new ListNode(v2[i]);
            temp = temp->next;
        }

        return head;
    }
    ListNode* oddEvenList(ListNode* head) {
        vector<int> v1;
        vector<int> v2;

        ListNode* temp = head;
        bool isOdd = true;
        while (temp != nullptr){
            if (isOdd) {
                v1.push_back(temp->val);
                isOdd = false;
            } else {
                v2.push_back(temp->val);
                isOdd = true;
            }
            temp = temp->next;
        }

        return createList(v1, v2);
    }
};