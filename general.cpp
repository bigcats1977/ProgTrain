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


void swap(int* val1, int* val2)
{
    int temp = *val1;
    *val1 = *val2;
    *val2 = temp;
}
void quicksort(int* nums, int left, int right)
{
    int num = nums[left];
    int i = left, j = right;
    if (left >= right)
        return;
    while (i < j) {
        while (i<j && nums[j] >= num)
            j--;
        swap(&nums[i], &nums[j]);

        while (i < j && nums[i] <= num)
            i++;
        swap(&nums[i], &nums[j]);
    }
    quicksort(nums, left, i - 1);
    quicksort(nums, i + 1, right);
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
        if (nums[i] != -101)
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


int** matrix2addr(vector<vector<int>> matrix)
{
    int** p;
    int row = (int)matrix.size();
    int col = (int)matrix[0].size();

    p = (int**)malloc(sizeof(int*) * row);
    for (int i = 0; i < row; i++) {
        p[i] = (int*)malloc(sizeof(int) * col);
        for (int j = 0; j < col; j++) {
            p[i][j] = matrix[i][j];
        }
    }
    return p;
}
