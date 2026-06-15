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
    int countNodes (ListNode* head){
        if (head == nullptr){
            return 0;
        }

        int count = 0;
        ListNode* temp = head;
        while (temp != nullptr){
            count++;
            temp = temp->next;
        }

        return count;
    }
    ListNode* deleteMiddle(ListNode* head) {
        if (head == nullptr || head->next == nullptr){
            return nullptr;
        }
        int mid = countNodes(head);
        mid /= 2;

        ListNode* temp = head;
        for (int i=0; i<mid; i++){
            if (i == mid-1){
                ListNode* temp2 = temp->next;
                temp->next = temp2->next;
                delete temp2;
                break;
            } else {
                temp = temp->next;
            } 
        }

        return head;
    }
};