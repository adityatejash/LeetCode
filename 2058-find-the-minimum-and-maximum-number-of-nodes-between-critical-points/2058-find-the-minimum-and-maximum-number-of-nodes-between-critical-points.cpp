class Solution {
public:
    vector<int> localMaximaMinima(ListNode* head) {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr) {
            return {};
        }

        ListNode* t1 = head;
        ListNode* t2 = head->next;
        ListNode* t3 = head->next->next;

        vector<int> v;
        int i = 2;

        while (t3 != nullptr) {
            int a = t1->val;
            int b = t2->val;
            int c = t3->val;

            if (b > a && b > c) {
                v.push_back(i);
            }

            if (b < a && b < c) {
                v.push_back(i);
            }

            t1 = t1->next;
            t2 = t2->next;
            t3 = t3->next;

            i++;
        }

        return v;
    }

    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> v = localMaximaMinima(head);

        if (v.size() < 2) {
            return {-1, -1};
        }

        int minimum = INT_MAX;

        for (int i = 1; i < v.size(); i++) {
            minimum = min(minimum, v[i] - v[i - 1]);
        }

        int maximum = v.back() - v.front();

        return {minimum, maximum};
    }
};