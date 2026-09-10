class Solution {
public:
    ListNode* partition(ListNode* head, int x) {

        ListNode* smallDummy = new ListNode(0);
        ListNode* bigDummy = new ListNode(0);

        ListNode* small = smallDummy;
        ListNode* big = bigDummy;

        while (head != NULL) {

            if (head->val < x) {
                small->next = head;
                small = small->next;
            }
            else {
                big->next = head;
                big = big->next;
            }

            head = head->next;
        }

        // Big list ka end NULL
        big->next = NULL;

        // Small list ko Big list se connect
        small->next = bigDummy->next;

        return smallDummy->next;
    }
};