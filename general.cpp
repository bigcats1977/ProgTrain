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

// 根据数组构造二叉树
TreeNode* CreateBinaryTree(vector<int> nums)
{
    TreeNode* root = NULL, * node = NULL;
    vector<TreeNode*> vecTree(nums.size(), NULL);
    int i = 0;

    for (i = 0; i < (int)nums.size(); i++)
    {
        node = NULL;
        if (nums[i] != -1)
            node = new TreeNode(nums[i]); // 用 -1 表示null
        vecTree[i] = node;
        if (i == 0)
            root = node;
    }

    for (i = 0; i * 2 + 2 < (int)nums.size(); i++)
    {
        if (vecTree[i] != NULL)
        {
            // 线性存储转连式存储关键逻辑
            vecTree[i]->left = vecTree[i * 2 + 1];
            vecTree[i]->right = vecTree[i * 2 + 2];
        }
    }

    return root;
}
