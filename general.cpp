#include "general.h"



ListNode* CreateListNode(vector<int> nums)
{
    ListNode* head = NULL, * node = NULL;
    if (nums.size() <= 0)
        return NULL;

    for (int i = (int)nums.size() - 1; i >= 0; i--)
    {
        node = (ListNode*)malloc(sizeof(ListNode));
        node->val = nums[i];
        node->next = head;
        head = node;
    }

    return head;
}

void quicksort(int* nums, int begin, int end)
{
    if (begin >= end)
        return;

    int pivot = nums[begin];
    int low = begin, high = end;
    while (low < high) {
        while (low < high && nums[high] >= pivot)
            high--;
        nums[low] = nums[high];
        while (low < high && nums[low] <= pivot)
            low++;
        nums[high] = nums[low];
    }
    nums[low] = pivot;

    quicksort(nums, begin, low - 1);
    quicksort(nums, low+1, end);
}
