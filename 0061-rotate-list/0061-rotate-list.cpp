class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0)
            return head;

        // Find length and last node
        int n = 1;
        ListNode* tail = head;

        while (tail->next) {
            tail = tail->next;
            n++;
        }

        // Avoid unnecessary rotations
        k = k % n;
        if (k == 0)
            return head;

        // Make circular list
        tail->next = head;

        // Find new tail
        int steps = n - k;
        ListNode* newTail = head;

        for (int i = 1; i < steps; i++) {
            newTail = newTail->next;
        }

        // New head
        ListNode* newHead = newTail->next;

        // Break the circle
        newTail->next = nullptr;

        return newHead;
    }
};