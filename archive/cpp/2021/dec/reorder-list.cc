#include "common.h"

class Solution
{
public:
    ListNode *reorderList(ListNode *head, int len)
    {
        if (len == 0)
            return nullptr;
        if (len == 1)
            return head;
        if (len == 2)
            return head->next;
        ListNode *tail = reorderList(head->next, len - 2);
        ListNode *tmp = tail->next;
        tail->next = tail->next->next;
        tmp->next = head->next;
        head->next = tmp;
        return tail;
    }

    void reorderList(ListNode *head)
    { // recursive
        ListNode *tail = nullptr;
        tail = reorderList(head, getLength(head));
    }

    int getLength(ListNode *head)
    {
        int len = 0;
        while (head != nullptr)
        {
            ++len;
            head = head->next;
        }
        return len;
    }
};