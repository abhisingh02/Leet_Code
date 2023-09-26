class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p = head, *q = head;
        while (n--) q = q->next;
        if (!q) return head->next;
        while (q->next) {
            p = p->next;
            q = q->next;
        }
        p->next = p->next->next;
        return head;
    }
};