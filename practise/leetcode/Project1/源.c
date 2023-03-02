#define _CRT_SECURE_NO_WARNINGS 1
struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL)
        return NULL;
    struct ListNode* prev = NULL;
    struct ListNode* cur = head;
    while (cur) {
        struct ListNode* new = cur->next;
        cur->next = prev;
        prev = cur;
        cur = new;
    }
    return prev;

}
struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* cur = head;
    struct ListNode* pre = head;
    while (cur && cur->next) {
        cur = cur->next->next;
        pre = pre->next;
    }
    return pre;
}
struct ListNode* FindKthToTail(struct ListNode* pListHead, int k) {
    // write code here
    if (pListHead == NULL || k <= 0)
        return NULL;
    struct ListNode* pre = pListHead;
    struct ListNode* cur = pListHead;
    while (k--) {
        if (cur)
            cur = cur->next;
        else
            return NULL;
    }
    while (cur) {
        cur = cur->next;
        pre = pre->next;
    }
    return pre;
}
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    //˼����ȡ����ָ�룬�ֱ�ָ��list1��list2��Ȼ��Ƚϴ�С������ŵ�����������������ȷ��һ��head��tail��������롣
    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;
    if (list1 == NULL)
    {
        return list2;
    }
    if (list2 == NULL)
    {
        return list1;
    }
    while (list1 != NULL && list2 != NULL)
    {
        if (list1->val < list2->val)
        {
            // Ϊ��
            if (head == NULL)
            {
                head = tail = list1;

            }
            else
            {
                tail->next = list1;
                tail = list1;
            }
            list1 = list1->next;
        }
        else
        {
            // Ϊ��
            if (head == NULL)
            {
                head = tail = list2;
            }
            else
            {
                tail->next = list2;
                tail = list2;
            }
            list2 = list2->next;


        }
    }
    if (list1 == NULL)
    {
        tail->next = list2;
    }
    if (list2 == NULL)
    {
        tail->next = list1;
    }
    return head;


}