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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int rem = b - a + 2;

        ListNode* first = list1;
        while (a > 1) {
            first = first->next;
            a--;
        }

        ListNode* second = first;
        while (rem > 0) {
            second = second->next;
            rem--;
        }

        first->next = list2;

        ListNode* temp = list2;
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = second;

        return list1;
    }
};