#include "algorithm.h"

// 1. Two Sum
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int i, j;
    int* res = (int*)malloc(sizeof(int) * 2);
    memset(res, 0, sizeof(int) * 2);

    for (i = 0; i < numsSize; i++) {
        for (j = i + 1; j < numsSize; j++) {
            if (nums[j] == target - nums[i]) {
                *returnSize = 2;
                res[0] = i;
                res[1] = j;
                return res;
            }
        }
    }

    *returnSize = 0;
    return res;
}

// 3. Longest Substring Without Repeating Characters
int lengthOfLongestSubstring(char* s)
{
    int max = 0;
    int slow = -1, fast = 0;
    int pos[256];
    if (s == NULL || strlen(s) == 0)
        return 0;
    memset(&pos[0], -1, sizeof(int) * 256);
    for (fast = 0; fast < (int)strlen(s); fast++)
    {
        if (pos[s[fast]] > slow)
        {
            slow = pos[s[fast]];
        }

        pos[s[fast]] = fast;
        int len = fast - slow;
        max = max < len ? len : max;
    }
    return max;
}

// 19. Remove Nth Node From End of List
struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* fast = dummy, * slow = dummy;
    dummy->next = head;

    while (fast && n> 0) {
        n--;
        fast = fast->next;
    }
    fast = fast->next;
    while (fast)
    {
        fast = fast->next;
        slow = slow->next;
    }

    fast = slow->next;
    slow->next = slow->next->next;
    free(fast);

    slow = dummy->next;
    free(dummy);

    return slow;
}

// 20. Valid Parentheses
int checkParent(char *stack, int top)
{
    if (top < 1)
        return top;
    if ((stack[top - 1] == '{' && stack[top] == '}') ||
        (stack[top - 1] == '(' && stack[top] == ')') ||
        (stack[top - 1] == '[' && stack[top] == ']'))
        return top - 2;
    return top;
}
bool isValid(char* s)
{
#if 0
    int i, len = (int)strlen(s);
    if(len %2 == 1)
        return false;

    struct stack {
        int top;
        char* ch;
    }st;
    st.top = -1;
    st.ch = (char*) malloc(len*sizeof(char));

    for (i = 0; i < len; i++) {
        switch (s[i])
        {
        case '{':
            st.top++;
            st.ch[st.top] = '}';
            break;
        case '(':
            st.top++;
            st.ch[st.top] = ')';
            break;
        case '[':
            st.top++;
            st.ch[st.top] = ']';
            break;
        default:
            if (st.top < 0 || st.ch[st.top] != s[i]) {
                free(st.ch);
                return false;
            }
            st.top--;
            break;
        }
    }
    free(st.ch);
    if (st.top >= 0)
        return false;
    return true;
#else
    int i, len = (int)strlen(s);
    char* tempStack = (char*)malloc(len);
    int top = -1;
    if (len % 2 == 1)
        return false;
    for (i = 0; i < len; i++) {
        tempStack[++top] = s[i];
        top = checkParent(tempStack, top);
    }
    if (top > 0) return false;
    return true;
#endif
}

// 21. Merge Two Sorted Lists
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = NULL;
    
    struct ListNode* node1 = list1, * node2 =list2, * prenode = dummy;
    while (node1 != NULL && node2 != NULL) {
        if (node1->val <= node2->val) {
            prenode->next = node1;
            node1 = node1->next;
        }
        else {
            prenode->next = node2;
            node2 = node2->next;
        }

        prenode = prenode->next;
    }
    if (node1 != NULL)
        prenode->next = node1;
    if (node2 != NULL)
        prenode->next = node2;

    prenode = dummy->next;
    free(dummy);
    return prenode;
}

// 24. Swap Nodes in Pairs
struct ListNode* swapPairs(struct ListNode* head)
{
    struct ListNode * cur = head, *next, *prior;
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));

    dummy->next = head;
    prior = dummy;
    cur = head;
    while (cur && cur->next) {
        next = cur->next;
        prior->next = next;
        cur->next = next->next;
        next->next = cur;

        prior = cur;
        cur = cur->next;
    }

    cur = dummy->next;
    free(dummy);

    return cur;
}

// 26. Remove Duplicates from Sorted Array
int removeDuplicates(int* nums, int numsSize)
{
    int fast = 0 , slow = 0;

    for (fast = 0; fast < numsSize; fast++) {
        if (nums[fast] != nums[slow]) {
            nums[++slow] = nums[fast];
        }
    }
    return slow+1;
}

// 27. Remove Element
int removeElement(int* nums, int numsSize, int val)
{
    int i = 0, pos = 0;

    for (i = 0; i < numsSize; i++) {
        if (nums[i] != val) {
            nums[pos++] = nums[i];
        }
    }

    return pos;
}

// 28. Find the Index of the First Occurrence in a String
void getNext(int* next, char* s)
{
    int j = -1;
    next[0] = j;
    for (int i = 1; i < (int)strlen(s); i++) {
        if (j >= 0 && s[i] != s[j + 1]) {
            j = next[j];
        }
        if (s[i] == s[j + 1]) {
            j++;
        }
        next[i] = j;
    }
}
int strStr(char* haystack, char* needle)
{
    if(strlen(needle) == 0)
        return 0;
    int* next = (int*)malloc(strlen(needle) * sizeof(int));
    getNext(next, needle);
    int j = -1;
    for (int i = 0; i < (int)strlen(haystack); i++) {
        while (j >= 0 && haystack[i] != needle[j + 1]) {
            j = next[j];
        }
        if (haystack[i] == needle[j + 1]) {
            j++;
        }
        if (j == strlen(needle) - 1)
            return (int)(i - strlen(needle) + 1);
    }
    return -1;
}

// 34. Find First and Last Position of Element in Sorted Array
int* searchRange(int* nums, int numsSize, int target, int* returnSize)
{
    int *result= (int*)malloc(2*sizeof(int));
    *returnSize = 2;
    memset(result, -1, 2 * sizeof(int));

    int left = 0, right = numsSize - 1;
    int mid;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (nums[mid] == target)
            break;
        if (nums[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    if (left > right)
        return result;


    for (left = mid-1; left >= 0; left--) {
        if (nums[left] < target)
            break;
    }
    for (right = mid+1; right < numsSize; right++) {
        if (nums[right] > target)
            break;
    }

    result[0] = left + 1;
    result[1] = right - 1;

    return result;
}

// 35. Search Insert Position
int searchInsert(int* nums, int numsSize, int target)
{
    int left = 0, right = numsSize - 1;
    int mid;

    while (left <= right) {
        mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        if (nums[mid] > target)
        right = mid - 1;
        else
        left = mid + 1;
    }
    return left;
}

// 46. Permutations
int** permuteAns;
int   CurPermute;
int* permutePath;
int   CurMutePath;
void BackTrackPerMute(int* nums, int numsSize, bool *used)
{
    if (CurMutePath == numsSize) {
        permuteAns[CurPermute] = (int*)malloc(sizeof(int) * numsSize);
        memcpy(permuteAns[CurPermute++], permutePath, sizeof(int) * numsSize);
        return;
    }
    for (int i = 0; i < numsSize; i++) {
        if (used[i])
            continue;
        used[i] = true;
        permutePath[CurMutePath++] = nums[i];
        BackTrackPerMute(nums, numsSize, used);
        used[i] = false;
        CurMutePath--;
    }
}
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    int i = 0;
    int size = 1;
    bool* used = (bool*)malloc(sizeof(bool) * numsSize);
    memset(used, false, sizeof(bool) * numsSize);

    for (i = numsSize; i > 0; i--)
        size *= i;
    permuteAns = (int**)malloc(sizeof(int*) * size);
    *returnSize = size;
    (*returnColumnSizes) = (int*)malloc(sizeof(int) * size);
    for (i = 0; i < size; i++)
        (*returnColumnSizes)[i] = numsSize;
    permutePath = (int*)malloc(sizeof(int) * numsSize);
    CurPermute = 0;
    CurMutePath = 0;

    BackTrackPerMute(nums, numsSize, used);

    free(permutePath);
    free(used);
    return permuteAns;
}

// 49. Group Anagrams
char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes)
{
    if (strsSize == 0)
        return NULL;

    
    return NULL;
}

// 36. Valid Sudoku
bool isValidSudoku(char** board, int boardSize, int* boardColSize)
{
    bool freq1[9], freq2[9];
    int i, j;
    int t = 0, l = 0;
    char ch1, ch2;

    for (i = 0; i < 9; i++) {
        memset(freq1, false, sizeof(bool) * 9);
        memset(freq2, false, sizeof(bool) * 9);
        for (j = 0; j < 9; j++) {
            ch1 = board[i][j];
            if (ch1 != '.') {
                if (freq1[ch1 - '1'])
                    return false;
                freq1[ch1 - '1'] = true;
            }

            ch2 = board[j][i];
            if (ch2 != '.') {
                if (freq2[ch2 - '1'])
                    return false;
                freq2[ch2 - '1'] = true;
            }
        }
    }

    for (t = 0; t < 9; t += 3) {
        for (l = 0; l < 9; l += 3) {
            memset(freq1, false, sizeof(bool) * 9);
            for (i = 0; i < 3; i++) {
                for (j = 0; j < 3; j++) {
                    ch1 = board[i+t][j+l];
                    if (ch1 != '.') {
                        if (freq1[ch1 - '1'])
                            return false;
                        freq1[ch1 - '1'] = true;
                    }
                }
            }
        }
    }
    return true;
}

// 53. Maximum Subarray
int maxSubArray(int* nums, int numsSize)
{
    int sum = INT_MIN, curSum = 0;
    for (int i= 0; i < numsSize; i++)
    {
        curSum = curSum + nums[i] > nums[i] ? curSum + nums[i] : nums[i];
        sum = curSum > sum ? curSum : sum;
    }
    return sum;
}

// 69. Sqrt(x)
int mySqrt(int x)
{
    int left = 1, right = x;
    int mid = 0, val;
    if (x <= 0)
        return 0;
    while (left <= right) {
        mid = left + (right - left) / 2;
        val = x / mid;
        if (val == mid)
            return mid;
        if (val > mid)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return right;
}

// 70. Climbing Stairs
int climbStairs(int n)
{
    if (n <= 1)
        return n;
    int* temp = (int*)malloc(sizeof(int) * (n+ 1));
    int way;
    temp[1] = 1;
    temp[2] = 2;
    for (int i = 3; i <= n; i++) {
        temp[i] = temp[i - 2] + temp[i - 1];
    }
    way = temp[n];
    free(temp);
    return way;    
}

// 74. Search a 2D Matrix
bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target)
{
    int n = *matrixColSize;
    int left = 0, right = matrixSize * n - 1;
    int mid = 0, cur = 0;
    while (left <= right) {
        mid = left + (right - left) / 2;
        cur = matrix[mid / n][mid % n];
        if (cur == target)
            return true;
        if (cur < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return false;
}

// 76. Minimum Window Substring
char* minWindow(char* s, char* t)
{
    int tChar['z'+1] = {0};
    int count = 0;
    char* p = s, * q = s;
    int minlen = INT_MAX;

    while (t[count]) {
        tChar[t[count++]]++;
    }

    while (*q) {
        if (--tChar[*q++] >= 0) {
            count--;
        }
        while(tChar[*p] < 0)
            tChar[*p++]++;
        if (count == 0 && q - p < minlen) {
            minlen = (int)(q - p);
            s = p;
        }
    }
    if (minlen == INT_MAX)
        minlen = 0;
    s[minlen] = '\0';

    return s;
}

// 77. Combinations
int** CombAns;
int  CurComb;
int* CombPath;
int  CurPath;
void CombBackTrack(int n, int k, int start)
{
    if (CurPath == k) {
        CombAns[CurComb] = (int*)malloc(sizeof(int) * k);
        memcpy(CombAns[CurComb++], CombPath, sizeof(int) * k);
        return;
    }
    for (int i = start; i <= n - (k-CurPath) + 1; i++) {
        CombPath[CurPath++] = i;
        CombBackTrack(n, k, i + 1);
        CurPath--;
    }
}
int** combine(int n, int k, int* returnSize, int** returnColumnSizes)
{
    int i, j;
    int nums = 1;
    for (i = n, j = 1; j <= k; i--, j++) {
        nums *= i;
        nums /= j;
    }

    *returnSize = nums;
    CombAns = (int**)malloc(sizeof(int*) * nums);
    *returnColumnSizes = (int*)malloc(sizeof(int) * nums);
    CombPath = (int*)malloc(sizeof(int) * k);
    for (i = 0; i < nums; i++) {
        (*returnColumnSizes)[i] = k;
    }
    CurComb = 0;
    CurPath = 0;
    CombBackTrack(n, k, 1);

    free(CombPath);

    return CombAns;
}

// 83. Remove Duplicates from Sorted List
struct ListNode* deleteDuplicates(struct ListNode* head)
{
    struct ListNode* Dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    int preval = INT_MIN;
    Dummy->val = INT_MIN;
    Dummy->next = head;
    struct ListNode* prenode = Dummy, * node = head;
    while (prenode->next)
    {
        if (prenode->val == prenode->next->val) {
            node = prenode->next;
            prenode->next = node->next;
            free(node);
        }
        else {
            prenode = prenode->next;
        }
    }

    prenode = Dummy->next;
    free(Dummy);
    return prenode;
}

// 88. Merge Sorted Array
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    int cur1 = m - 1, cur2 = n - 1;
    for (int i = m + n - 1; i>=0; i--) {
        if (cur1 >= 0 && cur2 >= 0) {
            if (nums1[cur1] >= nums2[cur2]) {
                nums1[i] = nums1[cur1--];
            }
            else {
                nums1[i] = nums2[cur2--];
            }
        }
        else if (cur2 >= 0)
            nums1[i] = nums2[cur2--];
        else
            break;
    }
}

// 94. Binary Tree Inorder Traversal
void inorder(struct TreeNode* root, int* ans, int* index)
{
    if (!root)
        return;
    inorder(root->left, ans, index);
    ans[(*index)++] = root->val;
    inorder(root->right, ans, index);
}
int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
    int* ans = (int*)malloc(sizeof(int) * 100);
    int index = 0;
    inorder(root, ans, &index);
    *returnSize = index;
    return ans;
}

// 98. Validate Binary Search Tree
bool pretravel(struct TreeNode* root, long* preval)
{
    if (!root)
        return true;
    if (!pretravel(root->left, preval))
        return false;
    if (root->val <= *preval)
        return false;
    *preval = root->val;
    return (pretravel(root->right, preval));
}
bool isValidBST(struct TreeNode* root)
{
    long preval = LONG_MIN;
    return pretravel(root, &preval);
}

// 101. Symmetric Tree
bool CompTree(struct TreeNode* left, struct TreeNode *right)
{
    if (!left && !right)
        return true;
    if (!left || !right)
        return false;
    if (left->val != right->val)
        return false;
    if (!CompTree(left->left, right->right))
        return false;
    return CompTree(left->right, right->left);
}
bool isSymmetric(struct TreeNode* root)
{
    if (!root)
        return true;
    return CompTree(root->left, root->right);
}

// 102. Binary Tree Level Order Traversal
struct QNode {
    struct TreeNode* tree;
    struct QNode* next;
};
bool insertQueue(struct QNode** tail, struct TreeNode* node)
{
    if (!node)
        return false;
    struct QNode* qnode;
    qnode = (struct QNode*)malloc(sizeof(struct QNode));
    qnode->tree = node;
    qnode->next = NULL;
    (*tail)->next = qnode;
    (*tail) = (*tail)->next;
    return true;
}
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes)
{
    if (!root) {
        *returnSize = 0;
        (*returnColumnSizes)[0] = 0;
        return NULL;
    }

    int** ans = (int**)malloc(sizeof(int*));
    struct QNode* head = NULL, * tail = NULL, * curnode = NULL;
    struct QNode* qnode = (struct QNode*)malloc(sizeof(struct QNode));
    qnode->tree = root;
    qnode->next = NULL;
    int nodenum = 0;
    int high = 0;
    tail = qnode;
    head = (struct QNode*)malloc(sizeof(struct QNode));
    head->tree = NULL;
    head->next = qnode;
    nodenum = 1;

    *returnColumnSizes = (int*)malloc(sizeof(int) * 2000);
    while (nodenum > 0) {
        ans[high] = (int*)malloc(sizeof(int) * nodenum);
        (*returnColumnSizes)[high] = nodenum;

        int cur = 0;
        for (int i = nodenum - 1; i >= 0; i--) {
            curnode = head->next;
            ans[high][cur++] = curnode->tree->val;
            if (insertQueue(&tail, curnode->tree->left)) {
                nodenum++;
            }
            if (insertQueue(&tail, curnode->tree->right)) {
                nodenum++;
            }
            head->next = curnode->next;
            nodenum--;
            free(curnode);
        }
        high++;
    }
    free(head);

    *returnSize = high;

    return ans;
}

// 104. Maximum Depth of Binary Tree
int maxDepth(struct TreeNode* root)
{
    if (!root)
        return 0;
    return (int)fmax(maxDepth(root->left), maxDepth(root->right)) + 1;
}

// 112. Path Sum
void presum(struct TreeNode* root, int sum, bool* pFind)
{
    if (!root)
        return;
    sum -= root->val;
    if (!root->left && !root->right) {
        if (sum == 0)
            *pFind = true;
        return;
    }
    presum(root->left, sum, pFind);
    presum(root->right, sum, pFind);
}
bool hasPathSum(struct TreeNode* root, int targetSum)
{
    bool bFind = false;
    presum(root, targetSum, &bFind);
    return bFind;
}

// 116. Populating Next Right Pointers in Each Node
void connect_left_to_right(struct Node* left, struct Node* right)
{
    if (left && right) {
        left->next = right;
        connect_left_to_right(left->right, right->left);
    }
}
struct Node* connect(struct Node* root)
{
    if (root) {
        connect_left_to_right(root->left, root->right);
        connect(root->left);
        connect(root->right);
    }
    return root;
}

// 118. Pascal's Triangle
int** generate(int numRows, int* returnSize, int** returnColumnSizes)
{
    int** ans = NULL;
    *returnSize = numRows;
    ans = (int**)malloc(sizeof(int*) * numRows);
    *returnColumnSizes = (int*)malloc(sizeof(int) * numRows);
    for (int i = 0; i < numRows; i++) {
        (*returnColumnSizes)[i] = i+1;
        ans[i] = (int*)malloc(sizeof(int) * (i + 1));
        ans[i][0] = 1;
        ans[i][i] = 1;
        for (int j = 1; j < i; j++) {
            ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
        }
    }

    return ans;
}

// 121. Best Time to Buy and Sell Stock
int maxProfit(int* prices, int pricesSize)
{
    int profit = 0, max = 0;
    int pre = prices[0];
    for (int i = 1; i < pricesSize; i++) {
        profit = prices[i] - pre;
        if (profit <= 0) {
            pre = prices[i];
            continue;
        }
        else {
            max = profit > max ? profit : max;
        }
    }

    return max;
}
// 141. Linked List Cycle
bool hasCycle(struct ListNode* head)
{
    struct ListNode* fast = head, *slow = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
            return true;
    }
    return false;
}
// 142. Linked List Cycle II
struct ListNode* detectCycle(struct ListNode* head)
{
    struct ListNode* fast=head, * slow = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow) {
            struct ListNode* index1 = fast;
            struct ListNode* index2 = head;
            while (index1 != index2)
            {
                index1 = index1->next;
                index2 = index2->next;
            }
            return index1;
        }
    }

    return NULL;
}

// 144. Binary Tree Preorder Traversal
void preorder(struct TreeNode* root, int* ans, int* index)
{
    if (!root)
        return;
    ans[(*index)++] = root->val;
    preorder(root->left, ans, index);
    preorder(root->right, ans, index);
}
int* preorderTraversal(struct TreeNode* root, int* returnSize)
{
    int* ans = (int*)malloc(sizeof(int) * 100);
    int index = 0;

    preorder(root, ans, &index);
    *returnSize = index;
    return ans;
}

//145. Binary Tree Postorder Traversal
void postorder(struct TreeNode* root, int* ans, int* index)
{
    if (!root)
        return;
    postorder(root->left, ans, index);
    postorder(root->right, ans, index);
    ans[(*index)++] = root->val;
}
int* postorderTraversal(struct TreeNode* root, int* returnSize)
{
    int* ans = (int*)malloc(sizeof(int) * 100);
    int index = 0;
    postorder(root, ans, &index);
    *returnSize = index;
    return ans;
}

// 151. Reverse Words in a String
int reverseExtraspace(char* s)
{
    int len = (int)strlen(s);
    int newlen = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] != ' ') {
            if (newlen != 0) {
                s[newlen++] = ' ';
            }
            while (i < len && s[i] != ' ')
                s[newlen++] = s[i];
        }
    }
    s[newlen] = '\0';
    return newlen;
}
char* reverseWords(char* s)
{
    int len = (int)strlen(s);
    bool bWord = false;
    int begin = len, right = 0, end = -1;
    char* result = (char*)malloc(len+1);
    int pos = 0 ,j = 0;
    memset(result, 0, len+1);

    for (right = len - 1; right >=0; right--) {
        if ((s[right] == ' ')&& bWord)
        {
            begin = right + 1;
            bWord = false;
            if (pos > 0)
                result[pos++] = ' ';
            for (j = begin; j <= end; j++) {
                result[pos++] = s[j];
            }
            end = -1;
            continue;
        }
        if (s[right] != ' ' && !bWord) {
            end = right;
            bWord = true;
            continue;
        }
    }
    if (end >= 0) {
        if (pos > 0)
            result[pos++] = ' ';
        for (j = 0; j <= end; j++) {
            result[pos++] = s[j];
        }
    }

    return result;
}

// 160. Intersection of Two Linked Lists
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB)
{
    struct ListNode* nodeA = headA, * nodeB = headB;
    int lenA = 0, lenB = 0, diff;

    while (nodeA) {
        lenA++;
        nodeA = nodeA->next;
    }
    while (nodeB) {
        lenB++;
        nodeB = nodeB->next;
    }
    if (lenA > lenB) {
        diff = lenA - lenB;
        nodeA = headA;
        nodeB = headB;
    }
    else {
            diff = lenB - lenA;
            nodeB = headA;
            nodeA = headB;
    }
    while (diff) {
        diff--;
        nodeA = nodeA->next;
    }
    while (nodeB)
    {
        if (nodeA == nodeB)
            return nodeA;
        nodeA = nodeA->next;
        nodeB = nodeB->next;
    }
        
    return nodeB;
}

// 167. Two Sum II - Input Array Is Sorted
int quickfind(int* numbers, int numberSize, int target)
{
    int left = 0, right = numberSize - 1;
    int mid;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (numbers[mid] == target)
            return mid;
        if (numbers[mid] > target) {
            right = mid - 1;
        }
        else
            left = mid + 1;
    }
    return -1;
}
int* twoSumII(int* numbers, int numbersSize, int target, int* returnSize)
{
    *returnSize = 2;
    int* result = (int*)malloc(2 * sizeof(int));
#if 0
    //memset(result, -1, 2 * sizeof(int));
    int index;
    for (int i = 0; i < numbersSize; i++)    {
        index = quickfind(numbers, numbersSize, target - numbers[i]);
        if (index != -1 && index !=i)
        {
            result[0] = i > index ? index + 1 : i + 1;
            result[1] = i < index ? index + 1 : i + 1;
            return result;
        }
    }
#else
    int left = 0, right = numbersSize - 1;
    int sum;
    while (left < right) {
        sum = numbers[left] + numbers[right];
        if (sum == target) {
            result[0] = left + 1;
            result[1] = right + 1;
            return result;
        }
        if (sum < target) {
            left++;
        }
        else {
            right--;
        }
    }
#endif
    return result;
}

// 189. Rotate Array
void inverse(int* nums, int begin, int end)
{
    while (begin < end)
    {
        int temp = nums[begin];
        nums[begin++] = nums[end];
        nums[end--] = temp;
    }
}
void rotate(int* nums, int numsSize, int k)
{
    k = k % numsSize;
    if (k == 0)
        return;
    inverse(nums, 0, numsSize-1);
    inverse(nums, 0, k-1);
    inverse(nums, k, numsSize - 1);
    return;
#if 0
    int* buff = (int*)malloc(numsSize * sizeof(int));
    memcpy(buff, nums, numsSize * sizeof(int));
    int slow = 0, fast = k;
    int temp;
    int i, j;
    for (i = 0; i <numsSize; i++) {
        j = (i + k+1) % numsSize;
        nums[i] = buff[j];
        /*temp = nums[i];
        nums[i] = nums[j];
        nums[j] = i;*/
    }
    /*for (fast = k; fast < numsSize; fast++) {
        temp = nums[slow];
        nums[slow++] = nums[fast];
        nums[fast] = temp;
    }*/
#endif
}

// 200. Number of Islands
void SearchIsland(char** grid, int r, int c, int sr, int sc)
{
    if (sr < 0 || sr >= r || sc < 0 || sc >= c)
        return;
    if (grid[sr][sc] == '0')
        return;
    grid[sr][sc] = '0';

    SearchIsland(grid, r, c, sr - 1, sc);
    SearchIsland(grid, r, c, sr, sc - 1);
    SearchIsland(grid, r, c, sr + 1, sc);
    SearchIsland(grid, r, c, sr, sc + 1);
}
int numIslands(char** grid, int gridSize, int* gridColSize)
{
    int ans = 0;

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] == '1') {
                SearchIsland(grid, gridSize, gridColSize[i], i, j);
                ans++;
            }
        }
    }
    return ans;
}
// 202. Happy Number
bool isHappy(int n)
{
    int cur = n;
    int sum = n;
    int *his = (int*) malloc(sizeof(int)*1000);
    int hisnum = 0;
    memset(his, 0, sizeof(int) * 1000);

    while (sum != 1) {
        for (int i = 0; i < hisnum; i++) {
            if (his[i] == cur) {
                free(his);
                return false;
            }
        }
        sum = 0;
        his[hisnum++] = cur;
        while (cur > 0) {
            sum += (cur % 10) * (cur % 10);
            cur = cur / 10;
        }
        cur = sum;
    }

    free(his);
    return true;
}

// 203. Remove Linked List Elements
ListNode* removeElements(ListNode* head, int val)
{
    ListNode* dummy = (ListNode*)malloc(sizeof(ListNode));
    dummy->next = head;
    ListNode* node = dummy, *temp = NULL;

    while (node->next != NULL) {
        if (node->next->val == val) {
            temp = node->next;
            node->next = node->next->next;
            free(temp);
        }
        else {
            node = node->next;
        }
    }

    temp = dummy->next;
    free(dummy);
    return temp;
}

// 205. Isomorphic Strings
//void SWAP(int* p, int* q)
//{
//    int buf;
//    buf = *p;
//    *p = *q;
//    *q = buf;
//    return;
//}
//void quicksort(int* freq, int left, int right)
//{
//    if (left >= right)
//        return;
//
//    int i = left, j = right;
//    int temp;
//    int key=freq[i];
//
//    while (i < j) {
//        while (i<j && freq[j]>=key)
//            j--;
//        SWAP(&freq[i], &freq[j]);
//        i++;
//        while (i<j && freq[i]>=key)
//            i++;
//        SWAP(&freq[i], &freq[j]);
//        j--;
//    }
//
//    quicksort(freq, left, i - 1);
//    quicksort(freq, i + 1, right);
//}

bool isIsomorphic(char* s, char* t)
{
    int swS[128] = { 0 };
    int swT[128] = { 0 };
    int i;
    for (i = 0; i < (int)strlen(s); i++) {
        if (swS[s[i]] == 0 && swT[t[i]] == 0) {
            swS[s[i]] = t[i];
            swT[t[i]] = s[i];
        }
        else if (swS[s[i]] != t[i] || swT[t[i] != s[i]])
            return false;
    }

    return true;
}

// 206. Reverse Linked List
struct ListNode* reverseList(struct ListNode* head)
{
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* node;
    dummy->next = NULL;

    while (head != NULL)
    {
        node = head;
        head = head->next;
        node->next = dummy->next;
        dummy->next = node;
    }

    node = dummy->next;
    free(dummy);
    return node;
}

// 209. Minimum Size Subarray Sum
int minSubArrayLen(int target, int* nums, int numsSize)
{
    int fast = 0, slow = 0; 
    int sum = 0, len = INT_MAX;
    for (fast = 0; fast < numsSize; fast++)
    {
        sum += nums[fast];
        while(sum >= target)
        {
            if (fast - slow + 1 < len) {
                len = fast - slow + 1;
            }

            sum -= nums[slow];
            slow++;
        }
    }
    if (len == INT_MAX)
        return 0;
    return len;
}

// 212. Word Search II
void DepthFindWord(char** board, int r, int c, int sr, int sc, char* word, bool *bfind)
{
    if (strlen(word) == 0 || *bfind)
        return;
    if (sr < 0 || sc < 0 || sr >= r || sc >= c)
        return;
    if (board[sr][sc] != word[0])
        return;
    if (strlen(word) == 1) {
        *bfind = true;
        return;
    }

    DepthFindWord(board, r, c, sr - 1, sc, &word[1], bfind);
    DepthFindWord(board, r, c, sr, sc - 1, &word[1], bfind);
    DepthFindWord(board, r, c, sr + 1, sc, &word[1], bfind);
    DepthFindWord(board, r, c, sr, sc + 1, &word[1], bfind);
}
char** findWords(char** board, int boardSize, int* boardColSize, char** words, int wordsSize, int* returnSize)
{
    char** ans = (char**)malloc(sizeof(char*)*wordsSize);

    int findnums = 0;
    bool bfind;
    for (int w = 0; w < wordsSize; w++) {
        bfind = false;
        for (int i = 0; i < boardSize; i++) {
            if (bfind)
                break;
            for (int j = 0; j < boardColSize[0]; j++) {
                DepthFindWord(board, boardSize, boardColSize[0], i, j, words[w], &bfind);
                if (bfind) {
                    int len = (int)strlen(words[w]);
                    ans[findnums] = (char*)malloc(sizeof(char)*(len + 1));
                    memset(ans[findnums], 0, sizeof(char) * (len + 1));
                    memcpy(ans[findnums], words[w], sizeof(char) * len);
                    findnums++;
                    break;
                }
            }
        }
    }

    *returnSize = findnums;
    return ans;
}

// 217. Contains Duplicate
bool quicksort4Duplicate(int* nums, int begin, int end)
{
    if (begin >= end)
        return true;

    int pivot = nums[begin];
    int low = begin, high = end;
    while (low < high) {
        while (low < high && nums[high] >= pivot) {
            if (nums[high] == pivot)
                return false;
            high--;
        }
        nums[low] = nums[high];
        while (low < high && nums[low] <= pivot) {
            if (nums[low] == pivot)
                return false;
            low++;
        }
        nums[high] = nums[low];
    }
    nums[low] = pivot;

    if (!quicksort4Duplicate(nums, begin, low - 1))
        return false;
    if (!quicksort4Duplicate(nums, low + 1, end))
        return false;
    return true;
}
bool containsDuplicate(int* nums, int numsSize)
{
#define PRIME 997
    struct Data {
        int val;
        struct Data* next;
    }HTable[PRIME];
    int i;

    struct Data* pre, * cur;
    for (i = 0; i < PRIME; i++) {
        HTable[i].val = INT_MIN;
        HTable[i].next = NULL;
    }
    for (i = 0; i < numsSize; i++) {
        int index = abs(nums[i] % PRIME);
        if (HTable[index].val == INT_MIN) {
            HTable[index].val = nums[i];
            continue;
        }
        else if (HTable[index].val == nums[i]) {
            return true;
        }
        pre = &HTable[index];
        while (pre->next) {
            if (pre->next->val == nums[i]) {
                return true;
            }
            pre = pre->next;
        }
        cur = (struct Data*)malloc(sizeof(struct Data));
        cur->val = nums[i];
        cur->next = NULL;
        pre->next = cur;
    }
    return false;
}

// 226. Invert Binary Tree
struct TreeNode* invertTree(struct TreeNode* root)
{
    struct TreeNode* temp;
    if (!root)
        return root;

    temp = root->right;
    root->right = root->left;
    root->left = temp;

    if (root->left)
        invertTree(root->left);
    if (root->right)
        invertTree(root->right);
    return root;
}

// 232. Implement Queue using Stacks
typedef struct {
    int         stackin[100];
    int         stackout[100];
    int         indexin;
    int         indexout;
} MyQueue;

MyQueue* myQueueCreate() {
    MyQueue* myQ = (MyQueue*)malloc(sizeof(MyQueue));
    myQ->indexin = myQ->indexout = -1;
    return myQ;
}

void myQueuePush(MyQueue* obj, int x) {
    obj->stackin[++(obj->indexin)] = x;
}

int myQueuePeek(MyQueue* obj) {
    int top;
    if (obj->indexout < 0) {
        for (int i = obj->indexin; i >= 0; i--) {
            top = obj->stackin[(obj->indexin)--];
            obj->stackout[++(obj->indexout)] = top;
        }
    }

    top = obj->stackout[obj->indexout];
    return top;
}
int myQueuePop(MyQueue* obj) {
    int top = myQueuePeek(obj);
    obj->indexout--;
    return top;
}

bool myQueueEmpty(MyQueue* obj) {
    return (obj->indexin<0 && obj->indexout < 0);
}

void myQueueFree(MyQueue* obj) {
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);

 * int param_2 = myQueuePop(obj);

 * int param_3 = myQueuePeek(obj);

 * bool param_4 = myQueueEmpty(obj);

 * myQueueFree(obj);
*/

// 235. Lowest Common Ancestor of a Binary Search Tree
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q)
{
    struct TreeNode* node;
    if (!root)
        return root;

    if (root->val > p->val && root->val > q->val) {
        node = lowestCommonAncestor(root->left, p, q);
        if (node)
            return node;
    }else if (root->val < p->val && root->val < q->val) {
        node = lowestCommonAncestor(root->right, p, q);
        if (node)
            return node;
    }

    return root;
}

// 242. Valid Anagram
bool isAnagram(char* s, char* t)
{
    int m = (int)strlen(s), n = (int)strlen(t);
    int nums[26] = { 0 };
    int i;
    if (m != n)
        return false;

    for (i = 0; i < m; i++)
        nums[s[i] - 'a']++;
    for (i = 0; i < n; i++) {
        nums[t[i]-'a']--;
        if (nums[t[i]-'a'] < 0)
            return false;
    }
    return true;
}

// 278. First Bad Version
bool isBadVersion(int version)
{
    return true;
}
int firstBadVersion(int n)
{
    int left = 1, right = n;
    int mid;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (!isBadVersion(mid)) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return left;
}
// 283. Move Zeroes
void moveZeroes(int* nums, int numsSize)
{
    int slow = 0, fast = 0;
    for (fast = 0; fast < numsSize; fast++) {
        if (nums[fast] != 0)
            nums[slow++] = nums[fast];
    }
    for (; slow < numsSize; slow++)
        nums[slow] = 0;
}

// 344. Reverse String
void reverseString(char* s, int sSize)
{
    char c;
    for (int i = 0; i < sSize / 2; i++) {
        c = s[i];
        s[i] = s[sSize - 1 - i];
        s[sSize - 1 - i] = c;
    }
}

// 345. Reverse Vowels of a String
bool isVowel(char ch)
{
    switch (ch) {
    case 'a':
    case 'A':
    case 'e':
    case 'E':
    case 'i':
    case 'I':
    case 'o':
    case 'O':
    case 'u':
    case 'U':
        return true;
    default:
        return false;
    }
    return false;
}
char* reverseVowels(char* s)
{
    int left = 0, right = (int)strlen(s) - 1;
    char ch;
    while (left < right) {
        while (left < right && !isVowel(s[left]))
            left++;
        while (left < right && !isVowel(s[right]))
            right--;
        ch = s[left];
        s[left++] = s[right];
        s[right--] = ch;
    }
    return s;
}

// 349. Intersection of Two Arrays
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize)
{
    int i = 0;
    int repeat[1000] = { 0 };
    int* result = (int*)malloc(sizeof(int) * 1000);
    memset(result, 0, sizeof(int) * 1000);
    *returnSize = 0;

    for (i = 0; i < nums1Size; i++) {
        repeat[nums1[i]]= 1;
    }

    for (i = 0; i < nums2Size; i++) {
        if (repeat[nums2[i]] > 0) {
            result[(*returnSize)++] = nums2[i];
            repeat[nums2[i]] = 0;
        }
    }

    return result;
}

// 350. Intersection of Two Arrays II
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize)
{
    int i = 0;
    int repeat[1001] = { 0 };
    int* result = (int*)malloc(sizeof(int) * 1000);
    memset(result, 0, sizeof(int) * 1000);
    *returnSize = 0;

    for (i = 0; i < nums1Size; i++) {
        repeat[nums1[i]] ++;
    }

    for (i = 0; i < nums2Size; i++) {
        if (repeat[nums2[i]] > 0) {
            result[(*returnSize)++] = nums2[i];
            repeat[nums2[i]] --;
        }
    }

    return result;
}

// 367. Valid Perfect Square
bool isPerfectSquare(int num)
{
    int left = 1, right = num;
    int mid, val;

    while (left <= right)
    {
        mid = left + (right - left) / 2;
        val = num / mid;
        if (val == mid) {
            if (mid * mid == num)
                return true;
            right = mid - 1;
        }
        else if (val > mid)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return false;
}

// 383. Ransom Note
bool canConstruct(char* ransomNote, char* magazine)
{
    int m = (int)strlen(ransomNote), n = (int)strlen(magazine);
    int nums[26] = { 0 };
    int i;

    if (m > n)
        return false;

    for (i = 0; i < n; i++)
        nums[magazine[i] - 'a']++;
    for (i = 0; i < m; i++) {
        nums[ransomNote[i] - 'a']--;
        if (nums[ransomNote[i] - 'a'] < 0)
            return false;
    }
    return true;
}

// 387. First Unique Character in a String
int firstUniqChar(char* s)
{
    struct charinfo {
        int  freq;
        int  place;
    };
    int i = 0;
    struct charinfo info[26] = { 0 };
    int min = INT_MAX;
    for (i = 0; i < (int)strlen(s); i++) {
        info[s[i] - 'a'].freq++;
        if (info[s[i] - 'a'].freq == 1) {
            info[s[i] - 'a'].place = i;
        }
    }
    for (i = 0; i < 26; i++) {
        if (info[i].freq == 1) {
            min = min > info[i].place ? info[i].place : min;
        }
    }
    
    return min == INT_MAX ? -1 : min;
}

// 392. Is Subsequence
bool isSubsequence(char* s, char* t)
{
    char* slow = s, * fast = t;
    if (*slow == 0)
        return true;
    if (*fast == 0)
        return false;
    while (*fast != 0)
    {
        if (*slow == *fast)
        {
            slow++;
            if (*slow == 0)
                return true;
        }
        fast++;
    }
    return false;
}

// 409. Longest Palindrome
int longestPalindrome(char* s)
{
    int hashval[52] = { 0 };
    int temp = 0;
    int longPal = 0;
    int i;
    bool bSingle = false;
    for (i = 0; i < (int)strlen(s); i++) {
        if (s[i] >= 'a')
            hashval[s[i] - 'a'+26]++;
        else
            hashval[s[i] - 'A']++;
    }
    for (i = 0; i < 52; i++) {
        if (hashval[i] % 2 == 0)
            longPal += hashval[i];
        else {
            longPal += hashval[i] - 1;
            bSingle = true;
        }
    }
    if (bSingle)
        longPal ++;
    return longPal;
}

// 509. Fibonacci Number
int fib(int n)
{
    int ans;
    int* FibNum = (int*)malloc(sizeof(int) * (n + 1));
    for (int i = 0; i <= n; i++) {
        if (i < 2)
            FibNum[i] = i;
        else
            FibNum[i] = FibNum[i - 1] + FibNum[i - 2];
    }
    ans = FibNum[n];
    free(FibNum);
    return ans;
}

// 523. Continuous Subarray Sum
bool checkSubarraySum(int* nums, int numsSize, int k)
{
    int cur = 0;
    int i;
    int zeros = 0;
    int* vals = (int *)malloc(k * sizeof(int));
    memset(vals, -1, k * sizeof(int));

    if (numsSize < 2)
        return false;

    for (i = 0; i < numsSize; i++) {
        if (nums[i]%k == 0)
        {
            zeros++;
            if (zeros > 1)
                return true;
            continue;
        }
        zeros = 0;
        cur = (cur + nums[i]) % k;
        if (cur == 0 || vals[cur] != -1)
            return true;
        else
            vals[cur] = i;
    }
    return false;
}

// 541. Reverse String II
char* reverseStr(char* s, int k)
{
    int len = (int)strlen(s);
    int i = 0;

    for (i = 0; i < len; i += 2 * k) {
        if (i + k <= len)
            reverseString(&s[i], k);
        else
            reverseString(&s[i], len - i);
    }
    return s;
}

// 542. 01 Matrix
#if 0
void calAdjDist(int** mat, int r, int c, int** result, int sr, int sc, int range)
{
    if (sr < 0 || sr >= r || sc < 0 || sc >= c)
        return;
    if ((range == 0 || mat[sr][sc] == 1) && (result[sr][sc] == 0 || result[sr][sc] > range)) {
        result[sr][sc] = range;
        calAdjDist(mat, r, c, result, sr - 1, sc, range + 1);
        calAdjDist(mat, r, c, result, sr, sc - 1, range + 1);
        calAdjDist(mat, r, c, result, sr + 1, sc, range + 1);
        calAdjDist(mat, r, c, result, sr, sc + 1, range + 1);
    }
}
int** updateMatrix(int** mat, int matSize, int* matColSize, int* returnSize, int** returnColumnSizes)
{
    int** ans = (int**)malloc(sizeof(int*) * matSize);
    int col = *matColSize;
    *returnSize = matSize;
    *returnColumnSizes = (int*)malloc(sizeof(int) * matSize);
    for (int i = 0; i < matSize; i++) {
        (*returnColumnSizes)[i] = col;
        ans[i] = (int*)malloc(sizeof(int) * col);
        memset(ans[i], 0, sizeof(int) * col);
    }
    for (int i = 0; i < matSize; i++) {
        for (int j = 0; j < col; j++) {
            if (mat[i][j] == 0) {
                calAdjDist(mat, matSize, col, ans, i, j, 0);
            }
        }
    }
    return ans;
}
#else
int** find_minus_one(int** ret, int matrixSize, int* matrixColSize, int row, int col, int* size) {
    int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
    int** result = (int**)malloc(4 * sizeof(int*));
    (*size) = 0;
    for (int i = 0; i < 4; i++) {
        int x = row + dir[i][0];
        int y = col + dir[i][1];
        if (x > -1 && x<matrixSize && y>-1 && y < matrixColSize[0]) {
            if (ret[x][y] == -1) {
                result[(*size)++] = (int*)malloc(2 * sizeof(int));
                result[(*size) - 1][0] = x;
                result[(*size) - 1][1] = y;
            }
        }
    }
    return result;
}
int** updateMatrix(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = matrixSize;
    returnColumnSizes[0] = matrixColSize;
    int** stack = (int**)malloc(matrixSize * matrixColSize[0] * sizeof(int*));
    int count = 0;
    int** ret = (int**)malloc(matrixSize * sizeof(int*));
    for (int i = 0; i < matrixSize; i++) {
        ret[i] = (int*)malloc(matrixColSize[i] * sizeof(int));
        for (int j = 0; j < matrixColSize[i]; j++) {
            if (matrix[i][j] == 0) {
                ret[i][j] = 0;
                stack[count++] = (int*)malloc(2 * sizeof(int));
                stack[count - 1][0] = i;
                stack[count - 1][1] = j;
            }
            else {
                ret[i][j] = -1;
            }
        }
    }
    while (count > 0) {
        int** stack_tmp = (int**)malloc(matrixSize * matrixColSize[0] * sizeof(int*));
        int count_tmp = 0;
        for (int i = 0; i < count; i++) {
            int x = stack[i][0];
            int y = stack[i][1];
            free(stack[i]);
            int size = 0;
            int** tmp = find_minus_one(ret, matrixSize, matrixColSize, x, y, &size);
            for (int j = 0; j < size; j++) {
                ret[tmp[j][0]][tmp[j][1]] = ret[x][y] + 1;
                stack_tmp[count_tmp++] = (int*)malloc(2 * sizeof(int));
                stack_tmp[count_tmp - 1][0] = tmp[j][0];
                stack_tmp[count_tmp - 1][1] = tmp[j][1];
            }
        }
        free(stack);
        stack = stack_tmp;
        count = count_tmp;
    }
    return ret;
}
#endif

// 557. Reverse Words in a String III
//reverseString(s, size);
char* reverseWordsIII(char* s)
{
    int start = 0;
    int len = (int)strlen(s);
    for (int i = 0; i <= len; i++) {
        if (s[i] == ' ' || i == len) {
                reverseString(&s[start], i - start);
            start = i + 1;
        }
    }
    return s;
}

// 566. Reshape the Matrix
int** matrixReshape(int** mat, int matSize, int* matColSize, int r, int c, int* returnSize, int** returnColumnSizes)
{
    int** reMat = NULL;
    if (r * c != matSize * matColSize[0]) {
        *returnSize = matSize;
        *returnColumnSizes = matColSize;
        return mat;
    }

    *returnSize = r;
    reMat = (int**)malloc(sizeof(int*) * r);
    *returnColumnSizes = (int*)malloc(sizeof(int) * r);
    for (int i = 0; i < r; i++) {
        reMat[i] = (int*)malloc(sizeof(int) * c);
        returnColumnSizes[0][i] = c;
        for (int j = 0; j < c; j++) {
            int pos = i * c + j;
            reMat[i][j] = mat[pos / (*matColSize)][pos % (*matColSize)];
        }
    }

    return reMat;
}

// 567. Permutation in String
bool checkInclusion(char* s1, char* s2)
{
    int len1 = (int)strlen(s1), len2 = (int)strlen(s2);
    int freq1[26] = { 0 };
    int freq2[26] = { 0 };
    int i;

    if (len1 > len2)
        return false;
    for (i = 0; i < len1; i++) {
        freq1[s1[i] - 'a']++;
        freq2[s2[i] - 'a']++;
    }
    if (memcmp(freq1, freq2, sizeof(int) * 26) == 0)
        return true;

    for (i = len1; i < len2; i++) {
        freq2[s2[i - len1] - 'a']--;
        freq2[s2[i] - 'a']++;
        if (memcmp(freq1, freq2, sizeof(int) * 26) == 0)
            return true;
    }
    return false;
}

// 589. N - ary Tree Preorder Traversal
void preTraver(struct NNode* root, int* result, int* count)
{
    if (!root)
        return;

    result[(*count)++] = root->val;
    for (int i = 0; i < root->numChildren; i++) {
        preTraver(root->children[i], result, count);
    }
}
int* preorder(struct NNode* root, int* returnSize)
{
    int count = 0;
    int* temp = (int*)malloc(sizeof(int) * 10000);
    int* result = NULL;

    preTraver(root, temp, &count);
    if (count > 0)
    {
        result = (int*)malloc(sizeof(int) * count);
        memcpy(result, temp, sizeof(int) * count);
    }

    free(temp);

    *returnSize = count;
    return result;
}

// 617. Merge Two Binary Trees
struct TreeNode* priorMerge(struct TreeNode* root1, struct TreeNode* root2)
{
    if (!root1)
        return root2;
    if (!root2)
        return root1;
    root1->val += root2->val;

    root1->left = priorMerge(root1->left, root2->left);
    root1->right = priorMerge(root1->right, root2->right);
    return root1;
}
struct TreeNode* mergeTrees(struct TreeNode* root1, struct TreeNode* root2)
{
    return priorMerge(root1, root2);
}

// 695. Max Area of Island
void depthIsland(int** grid, int row, int col, int sr, int sc, int* area)
{
    if (sr < 0 || sr >= row || sc < 0 || sc >= col)
        return;
    if (grid[sr][sc] == 0)
        return;
    (*area)++;
    grid[sr][sc] = 0;

    depthIsland(grid, row, col, sr - 1, sc, area);
    depthIsland(grid, row, col, sr, sc - 1, area);
    depthIsland(grid, row, col, sr + 1, sc, area);
    depthIsland(grid, row, col, sr, sc + 1, area);
}
int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize)
{
    int maxarea = 0;
    int curarea = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < *gridColSize; j++) {
            if (grid[i][j] == 0)
                continue;
            curarea = 0;
            depthIsland(grid, gridSize, *gridColSize, i, j, &curarea);
            maxarea = maxarea < curarea ? curarea : maxarea;
        }
    }
    return maxarea;
}

// 704. Binary Search
int search(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;
    int mid;

    while (left <= right) {
        mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        else if (nums[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return -1;
}

// 707. Design Linked List
// MyLinkedList

// 724. Find Pivot Index
int pivotIndex(int* nums, int numsSize)
{
#if 0
    int suml=0, sumr = 0;
    /*suml = (int*)malloc((numsSize+1) * sizeof(int));
    memset(suml, 0, (numsSize + 1) * sizeof(int));*/
    int i;
    for (i = 0; i < numsSize; i++) {
        suml += nums[i];
    }
    sumr = suml;
    for (i = numsSize - 1; i >= 0; i--) {
        suml -= nums[i];
        sumr -= nums[numsSize - i];
        if (suml == sumr)
            return i;
    }
    return -1;
#else
    int* suml, total;
    suml = (int*)malloc((numsSize + 1) * sizeof(int));
    memset(suml, 0, (numsSize + 1) * sizeof(int));
    int i;
    for (i = 1; i <= numsSize; i++) {
        suml[i] = suml[i - 1] + nums[i - 1];
    }
    total = suml[numsSize];
    for (i = 0; i < numsSize; i++) {
        total -= nums[i];
        if (suml[i] == total)
            break;
    }

    free(suml);
    if (i == numsSize)
        return -1;
    return i;
#endif
}

// 733. Flood Fill
void depthTravel(int** image, int row, int col, int srcClr, int sr, int sc, int color)
{
    if (sr <0 || sr >= row || sc<0 || sc >=col)
        return;
    if (image[sr][sc] != srcClr)
        return;

    image[sr][sc] = color;
    depthTravel(image, row, col, srcClr, sr - 1, sc, color);
    depthTravel(image, row, col, srcClr, sr, sc - 1, color);
    depthTravel(image, row, col, srcClr, sr + 1, sc, color);
    depthTravel(image, row, col, srcClr, sr, sc + 1, color);
}
int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int color, int* returnSize, int** returnColumnSizes)
{
    int i;
    *returnSize = imageSize;
    *returnColumnSizes = (int*)malloc(sizeof(int) * imageSize);
    for (i = 0; i < imageSize; i++)
        (*returnColumnSizes)[i] = imageColSize[i];

    if (color == image[sr][sc])
        return image;

    depthTravel(image, imageSize, imageColSize[0], image[sr][sc], sr, sc, color);

    return image;
}

// 766. Toeplitz Matrix
bool isToeplitzMatrix(int** matrix, int matrixSize, int* matrixColSize)
{
    for (int i = 0; i < matrixSize - 1; i++) {
        for (int j = 0; j < *matrixColSize - 1; j++) {
            if (matrix[i][j] != matrix[i + 1][j + 1])
                return false;
        }
    }
    return true;
    int i,j;
    int m, n;
    int val;

    m = 0;
    for (n = 0; n < *matrixColSize; n++) {
        val = matrix[m][n];
        for (i = m + 1, j = n + 1; i < matrixSize && j < *matrixColSize; i++, j++) {
            if(val != matrix[i][j])
                return false;
        }
    }
    n = 0;
    for (m = 1; m < matrixSize; m++) {
        val = *(*(matrix + m) + n);
        for (i = m + 1, j = n + 1; i < matrixSize && j < *matrixColSize; i++, j++) {
            if (val != matrix[i][j])
                return false;
        }
    }

    return true;
}

// 784. Letter Case Permutation
/*
* Input: s = "a1b2"
Output: ["a1b2","a1B2","A1b2","A1B2"]
*/
char  **LCAns;
int   CurLC;
char*  LCPath;
int   CurLCPath;
void backTrackLCPerm(char* s, int len, int cur)
{
    if (cur == len) {
        LCAns[CurLC] = (char*)malloc(len+1);
        memset(LCAns[CurLC],0, len + 1);
        memcpy(LCAns[CurLC++], LCPath, len);
        return;
    }
    LCPath[CurLCPath++] = s[cur];
    backTrackLCPerm(s, len, cur+1);
    CurLCPath--;

    if (s[cur] >= 'a' && s[cur] <= 'z') {
        LCPath[CurLCPath++] = s[cur] - 0x20;
        backTrackLCPerm(s, len, cur + 1);
        CurLCPath--;
    }
    else if (s[cur] >= 'A' && s[cur] <= 'Z') {
        LCPath[CurLCPath++] = s[cur] + 0x20;
        backTrackLCPerm(s, len, cur + 1);
        CurLCPath--;
    }
}
char** letterCasePermutation(char* s, int* returnSize)
{
    int len = (int)strlen(s);
    LCAns = (char**)malloc(sizeof(char*) * 4096);
    LCPath = (char*)malloc(len+1);
    memset(LCPath, 0, len + 1);
    CurLCPath = 0;
    backTrackLCPerm(s, len, 0);
    free(LCPath);
    *returnSize = CurLC;
    return LCAns;
}
// 844. Backspace String Compare
void procBS(char* s, int* pos)
{
    int bsNum = 0;
    if (*pos < 0)
        return;
    while (*pos >= 0 && (s[*pos] == '#' || bsNum > 0)) {
        if (s[*pos] == '#') {
            bsNum++;
            (*pos)--;
            continue;
        }
        if (bsNum > 0) {
            (*pos)--;
            bsNum--;
        }
    }
}
bool backspaceCompare(char* s, char* t)
{
    int fast1 = (int)strlen(s)-1, fast2 = (int)strlen(t) - 1;

    while (fast1 >= 0 || fast2 >= 0) {
        procBS(s, &fast1);
        procBS(t, &fast2);
        if (fast1 < 0 || fast2 < 0)
            break;
        if (s[fast1] != t[fast2])
            return false;
        fast1--;
        fast2--;
    }
    procBS(s, &fast1);
    procBS(t, &fast2);
    if (fast1 >= 0 || fast2 >= 0)
        return false;
    
    return true;
}

// 876. Middle of the Linked List
struct ListNode* middleNode(struct ListNode* head)
{
    struct ListNode* Dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    Dummy->next = head;
    struct ListNode* fast = Dummy, * slow = Dummy;

    while (fast != NULL) {
        slow = slow->next;
        fast = fast->next;
        if (fast != NULL)
            fast = fast->next;
    }
    free(Dummy);
    return slow;
}

// 904. Fruit Into Baskets
int totalFruit(int* fruits, int fruitsSize)
{
    int slow = 0;
    int result = 1;
    int other = -1;
    int len = 0;
    for (int i=1; i < fruitsSize; i++) {
        if (fruits[i] != other && fruits[i] != fruits[slow]) {
            if (other == -1) {
                other = fruits[i];
            }
            // change type
            else {
                other = fruits[i];
                slow = i - 1;
                for (int j = slow-1; j >= 0; j--) {
                    if (fruits[j] != fruits[i - 1])
                        break;
                    slow = j;
                }
            }
        }
        len = i - slow + 1;
        result = len > result ? len : result;
    }
    return result;
}
// 977. Squares of a Sorted Array
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    int left = 0, right = numsSize - 1;
    int sql, sqr;
    int* result = (int*)malloc(numsSize * sizeof(int));

    *returnSize = numsSize;
    memset(result, 0, numsSize * sizeof(int));

    for (int i = numsSize-1; i >= 0; i--) {
        sql = nums[left] * nums[left];
        sqr = nums[right] * nums[right];
        if (sql >= sqr) {
            result[i] = sql;
            left++;
        }
        else {
            result[i] = sqr;
            right--;
        }
    }

    return result;
}

// 994. Rotting Oranges
int infectable(int i, int j, int rows, int cols, int** grid) {
    if (i > 0 && grid[i - 1][j] == 2) return 1;
    if (j > 0 && grid[i][j - 1] == 2) return 1;
    if (i < rows - 1 && grid[i + 1][j] == 2) return 1;
    if (j < cols - 1 && grid[i][j + 1] == 2) return 1;
    return 0;
}
int orangesRotting(int** grid, int gridSize, int* gridColSize)
{
    int matrix_changed;
    int rounds = 0;
    int has_ones;
    do {
        matrix_changed = 0;
        has_ones = 0;
        for (int i = 0; i < gridSize; i++)
            for (int j = 0; j < gridColSize[i]; j++)
                if (grid[i][j] == 1)
                    if (infectable(i, j, gridSize, gridColSize[i], grid)) {
                        grid[i][j] = -1;
                        matrix_changed = 1;
                    }
                    else {
                        has_ones = 1;
                    }
        if (matrix_changed) {
            rounds++;
            for (int i = 0; i < gridSize; i++)
                for (int j = 0; j < gridColSize[i]; j++)
                    if (grid[i][j] == -1) grid[i][j] = 2;
        }

    } while (matrix_changed);

    return (has_ones) ? -1 : rounds;
}

// 1047. Remove All Adjacent Duplicates In String
char* removeDuplicates(char* s)
{
    int i;
    int idx = -1;
    int len = (int)strlen(s);

    char* res = (char*)malloc(len);
    
    for (i = 0; i < len; i++)
    {
        if (idx >= 0 && res[idx] == s[i])
            idx--;
        else {
            res[++idx] = s[i];
        }
    }
    res[++idx] = '\0';

    return res;
}

// 1239. Maximum Length of a Concatenated String with Unique Characters
int maxLength(char** arr, int arrSize)
{
    int i;// , j;
    char ch;
    int* arrnum;
    int* letfreq;
    arrnum = (int*)malloc(arrSize * sizeof(int));
    letfreq = (int*)malloc(arrSize * 26 * sizeof(int));
    memset(arrnum, 0, arrSize * sizeof(int));
    memset(letfreq, 0, arrSize * 26 * sizeof(int));

    for (i = 0; i < arrSize; i++) {
        ch = arr[i][0];
        while (ch != '\0')
        {
            letfreq[ch - 'a'] = 1;
            arrnum[i] ++;
            if (arrnum[i] == 26)
                return 26;
        }
    }

    return 0;
}

// 1323. Maximum 69 Number
int maximum69Number(int num)
{
    int temp = num;
    int ans = 3000;
    int digits[4] = { 0 };
    int i = 0;
    for (i = 3; i >= 0; i--)
    {
        digits[i] = temp % 10;
        temp = (temp - digits[i]) / 10;
        if (temp == 0)
            break;
    }
    for (i = 0; i < 4; i++) {
        if (digits[i] == 6)
            return ans + num;
        ans /= 10;
    }
    return num;
}

// 1480. Running Sum of 1d Array
int* runningSum(int* nums, int numsSize, int* returnSize)
{
    int* result = (int*)malloc(numsSize * sizeof(int));

    *returnSize = numsSize;
    memset(result, 0, numsSize * sizeof(int));
    result[0] = nums[0];
    for (int i = 1; i < numsSize; i++) {
        result[i] = result[i-1]+nums[i];
    }

    return result;
}

// 1544. Make The String Great
char* makeGood(char* s)
{
    int len = (int)strlen(s);
    char* ans = (char*)malloc(len+1);
    memset(ans, 0, len+1);
    int top = -1;
    for (int i = 0; i < len; i++) {
        if (top >= 0 && (ans[top] == s[i] - 0x20 || ans[top] == s[i] + 0x20)) {
            top--;
        }
        else {
            ans[++top] = s[i];
        }
    }
    ans[++top] = '\0';
    return ans;
}

// 1662. Check If Two String Arrays are Equivalent
bool arrayStringsAreEqual(char** word1, int word1Size, char** word2, int word2Size)
{
    int *len1;
    int *len2;

    int i;
    char a, b;
    int w1 = 0;
    int w2 = 0;
    int w1idx = 0;
    int w2idx = 0;
    int w1off = 0;
    int w2off = 0;

    len1 = (int*)malloc(word1Size * sizeof(int));
    len2 = (int*)malloc(word2Size * sizeof(int));

    for (i = 0; i < word1Size; i++) len1[i] = (int)strlen(word1[i]);
    for (i = 0; i < word2Size; i++) len2[i] = (int)strlen(word2[i]);
    for (i = 0; i < word1Size; i++) w1 += len1[i];
    for (i = 0; i < word2Size; i++) w2 += len2[i];

    if (w1 != w2) {
        free(len1);
        free(len2);
        return false; // impossible if they are not the same size !
    } 


    int w1c = len1[0]; //sum of all len's so far .. 
    int w2c = len2[0];
    for (i = 0; i < w1; i++) {

        a = b = 0;

        if (i >= w1c) {
            w1off = 0;
            w1c += len1[++w1idx];
        }

        if (i >= w2c) {
            w2off = 0;
            w2c += len2[++w2idx];
        }

        a = word1[w1idx][w1off++];
        b = word2[w2idx][w2off++];

        if (a != b) {
            free(len1);
            free(len2);
            return false;
        }

    }

    free(len1);
    free(len2);

    return true;
}

// 1832. Check if the Sentence Is Pangram
bool checkIfPangram(char* sentence)
{
    int letters[26] = { 0 };
    int count = 26;
    int i;
    for (i = 0; i < (int)strlen(sentence); i++) {
        if (letters[sentence[i] - 'a'] == 0)
        {
            letters[sentence[i] - 'a']--;
            count--;
        }
    }
    return count > 0 ? false : true;
}

// 2131. Longest Palindrome by Concatenating Two Letter Words
int longestPalindrome(char** words, int wordsSize)
{
    int longPal = 0;
    int freq[26][26] = { 0 };
    int a, b;
    int i;
    for (i = 0; i < wordsSize; i++) {
        a = words[i][0] - 'a';
        b = words[i][1] - 'a';
        if (freq[b][a]) {
            longPal += 4;
            freq[b][a]--;
        }
        else
            freq[a][b]++;
    }
    for(i = 0; i < 26; i++) {
        if (freq[i][i])
        {
            longPal += 2;
            break;
        }
    }

    return longPal;
}

// ½£Ö¸ Offer 58 - II.×óÐý×ª×Ö·û´®
string reverseLeftWords(string s, int n)
{
    reverseString(&*s.begin(), n);
    reverseString(&*s.begin() + n, (int)s.length() - n);
    reverseString(&*s.begin(), (int)s.length());

    return s;
}