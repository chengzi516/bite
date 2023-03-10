#define _CRT_SECURE_NO_WARNINGS 1
struct ListNode* detectCycle(struct ListNode* head) {
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) {
            struct ListNode* begin = head;
            struct ListNode* meet = slow;
            while (begin != meet) {
                begin = begin->next;
                meet = meet->next;
            }
            return meet;
        }


    }
    return NULL;
}
