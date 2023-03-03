#define _CRT_SECURE_NO_WARNINGS 1
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* dummynode = malloc(sizeof(struct ListNode));
    dummynode->next = head;
    struct ListNode* prev = dummynode;
    while (prev->next != NULL) {
        if (prev->next->val == val) {
            struct ListNode* tmp = prev->next;
            prev->next = prev->next->next;
            free(tmp);
        }
        else {
            prev = prev->next;
        }
    }
    return dummynode->next;
}
