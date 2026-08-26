class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;

        // Check if k nodes are available
        for (int i = 0; i < k; i++) {
            if (temp == nullptr)
                return head;
            temp = temp->next;
        }

        // Reverse first k nodes
        ListNode* prev = nullptr;
        ListNode* curr = head;

        for (int i = 0; i < k; i++) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        // Recursively reverse remaining nodes
        head->next = reverseKGroup(curr, k);

        return prev;
    }
};
