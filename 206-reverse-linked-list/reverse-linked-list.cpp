class Solution {
public:
    ListNode* insertAtBegin(ListNode* head) {
        ListNode* newHead = nullptr;

        while (head != nullptr) {
            ListNode* node = new ListNode(head->val);

            node->next = newHead;
            newHead = node;

            head = head->next;
        }

        return newHead;
    }

    ListNode* reverseList(ListNode* head) {
        return insertAtBegin(head);
    }
};