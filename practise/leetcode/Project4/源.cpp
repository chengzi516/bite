#define _CRT_SECURE_NO_WARNINGS 1
class Partition {
public:
    ListNode* partition(ListNode* pHead, int x) {
        struct ListNode* heada, * taila, * headb, * tailb;
        heada = taila = (struct ListNode*)malloc(sizeof(struct ListNode));
        headb = tailb = (struct ListNode*)malloc(sizeof(struct ListNode));
        struct ListNode* cur = pHead;
        while (cur) {
            if (cur->val < x) {
                taila->next = cur;
                taila = taila->next;
            }
            else {
                tailb->next = cur;
                tailb = tailb->next;
            }
            cur = cur->next;
        }
        taila->next = tailb->next = NULL; //将两者的末位统统置空
        taila->next = headb->next;
        pHead = heada->next;
        free(heada);
        free(headb);
        return pHead;


    }
};

class PalindromeList {
public:
    struct ListNode* returnmid(struct ListNode* head) {
        struct ListNode* p1, * p2;
        p1 = p2 = head;
        while (p1 && p1->next) {
            p1 = p1->next->next;
            p2 = p2->next;
        }
        return p2;


    }
    struct ListNode* reverse(struct ListNode* head) {

        struct ListNode* cur = head, * newhead = NULL;
        while (cur) {
            struct ListNode* next = cur->next;
            cur->next = newhead;
            newhead = cur;
            cur = next;
        }
        return newhead;
    }
    bool chkPalindrome(ListNode* A) {
        // write code here
        struct ListNode* mid = returnmid(A);
        struct ListNode* mid2 = reverse(mid);
        while (A && mid2) {
            if (mid2->val != A->val)
                return false;
            mid2 = mid2->next;
            A = A->next;
        }
        return true;
    }
};

struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
    struct ListNode* taila = headA, * tailb = headB;
    int lena = 1, lenb = 1;

    while (taila->next) {
        taila = taila->next;
        lena++;
    }
    while (tailb->next) {
        tailb = tailb->next;
        lenb++;
    }
    if (taila != tailb)
        return NULL;
    int gap = abs(lena - lenb);
    struct ListNode* list1 = headA;
    struct ListNode* list2 = headB;
    if (lena < lenb) {
        list1 = headB;
        list2 = headA;
    }
    while (gap--) {
        list1 = list1->next;
    }
    while (list1 != list2)
    {
        list1 = list1->next;
        list2 = list2->next;
    }
    return list1;
}
hasCycle(struct ListNode* head) {
    struct ListNode* slow = head, * fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return true;
        }

    }
    return false;
}