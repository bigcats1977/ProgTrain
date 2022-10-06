#include "general.h"



struct ListNode* CreateListNode(vector<int> nums)
{
    struct ListNode* head = NULL, * node = NULL;
    if (nums.size() <= 0)
        return NULL;

    for (int i = (int)nums.size() - 1; i >= 0; i--)
    {
        node = (struct ListNode*)malloc(sizeof(struct ListNode));
        node->val = nums[i];
        node->next = head;
        head = node;
    }

    return head;
}
