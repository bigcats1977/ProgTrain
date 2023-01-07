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

// 2. Add Two Numbers
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    int sum = 0;
    struct ListNode* Dummy, *prior, *node;
    if (!l1)
        return l2;
    if (!l2)
        return l1;
    Dummy = (struct ListNode*)calloc(sizeof(struct ListNode), 1);
    Dummy->next = l1;
    prior = Dummy;
    while (l1 && l2) {
        sum += l1->val + l2->val;
        l1->val = sum % 10;
        sum /= 10;
        prior = l1;
        l1 = l1->next;
        l2 = l2->next;
    }
    if (l2)  {
        prior->next = l2;
        l1 = l2;
    }
    while (l1) {
        sum += l1->val;
        l1->val = sum % 10;
        sum /= 10;
        prior = l1;
        l1 = l1->next;
    }
    if (sum > 0) {
        node = (struct ListNode*)calloc(sizeof(struct ListNode), 1);
        node->val = sum;
        prior->next = node;
    }

    prior = Dummy->next;
    free(Dummy);
    return prior;
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

// 5. Longest Palindromic Substring
int maxpalstr(char* s, int l, int r)
{
    while (l >= 0 && r < (int)strlen(s) && s[l] == s[r]) {
        l--;
        r++;
    }
    return (r - l - 1);
}
char* longestPalindromeI(char* s)
{
    int maxlen = 0, start = 0;
    for (int i = 0; i < (int)strlen(s); i++) {
        int len1 = maxpalstr(s, i, i);
        int len2 = maxpalstr(s, i, i + 1);
        int len = len1 > len2 ? len1 : len2;
        if (len > maxlen) {
            maxlen = len;
            start = i - ((maxlen - 1) / 2);
        }
    }
    char* ans = (char*)calloc(maxlen+1, 1);
    memcpy(ans, &s[start], maxlen);
    return ans;
}

// 11. Container With Most Water
int maxArea(int* height, int heightSize)
{
    int left = 0, right = heightSize - 1;
    int max = 0, water = 0;
    
    while (left < right)
    {
        water = (right - left) * (int)fmin(height[left], height[right]);
        max = max < water ? water : max;
        if (height[left] < height[right])
            left++;
        else
            right--;
    }
    return max;
}

// 15. 3Sum
int threeCmp(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    qsort(nums, numsSize, sizeof(int), threeCmp);

    int** ans = (int**)malloc(sizeof(int*)*(numsSize * numsSize));
    (*returnColumnSizes) = (int*)malloc(sizeof(int) * (numsSize * numsSize));
    *returnSize = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > 0)
            return ans;

        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }

        int left = i + 1;
        int right = numsSize - 1;
        while (left < right) {
            if (nums[i] + nums[left] + nums[right] > 0)
                right--;
            else if(nums[i] + nums[left] + nums[right] < 0)
                left++;
            else {
                ans[(*returnSize)] = (int*)malloc(sizeof(int) * 3);
                (*returnColumnSizes)[(*returnSize)] = 3;
                ans[(*returnSize)][0] = nums[i];
                ans[(*returnSize)][1] = nums[left];
                ans[(*returnSize)][2] = nums[right];
                (*returnSize)++;
                while (left < right && nums[right] == nums[right - 1]) right--;
                while (left < right && nums[left] == nums[left + 1]) left++;
                left++;
                right--;
            }
        }
    }

    return ans;
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

// 25. Reverse Nodes in k - Group
struct ListNode* reverseKGroup(struct ListNode* head, int k)
{
    if (k == 1)
        return head;

    struct ListNode* Dummy, * pre, * first, * last, * node, * newpre;
    int resnum;
    Dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    Dummy->next = head;
    pre = last = Dummy;
    while (last) {
        resnum = k;
        while (last && resnum > 0)  {
            last = last->next;
            resnum--;
        }
        if (!last)
            break;

        resnum = k;
        newpre = first = pre->next;
        pre->next = last->next;
        while (resnum)
        {
            node = first;
            first = first->next;
            node->next = pre->next;
            pre->next = node;
            resnum--;
        }
        pre = last = newpre;
    }
    first = Dummy->next;
    free(Dummy);
    return first;
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

// 33. Search in Rotated Sorted Array
int searchRotated(int* nums, int numsSize, int target)
{
    int left = 0, right = numsSize - 1, mid;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (nums[mid] == target)
            return mid;
        if (nums[mid] < nums[right]) {
            if (target > nums[mid] && target <= nums[right]) left = mid + 1;
            else right = mid - 1;
        }
        else {
            if (target < nums[mid] && target >= nums[left]) right = mid - 1;
            else left = mid + 1;
        }
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

// 43. Multiply Strings
char* multiply(char* num1, char* num2)
{
    if (num1[0] == '0' || num2[0] == '0')
        return (char*)"0";

    int i, j;
    int len1 = (int)strlen(num1), len2 = (int)strlen(num2);
    int maxlen = len1 + len2 + 1;
    char* ans = (char*)calloc(maxlen, 1);
    
    for (i = len1 - 1; i >= 0; i--) {
        for (j = len2 - 1; j >= 0; j--) {
            char multis = (num1[i] - '0') * (num2[j] - '0');
            int ii = i + j + 1;
            ans[ii] += multis % 10;
            ans[ii - 1] += multis / 10;
            multis = ans[ii];
            if (multis >= 10) {
                ans[ii] = multis % 10;
                ans[ii - 1] += multis / 10;
            }
        }
    }

    for (i = 0; i < maxlen-1; i++)
        ans[i] += '0';
    if (ans[0] == '0') ans++;
    return ans;
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

// 48. Rotate Image
void rotate(int** matrix, int matrixSize, int* matrixColSize)
{
    int i, j, temp;
    int* tempcol;
    for (i = 0; i < matrixSize / 2; i++) {
        tempcol = matrix[i];
        matrix[i] = matrix[matrixSize - 1 - i];
        matrix[matrixSize - 1 - i] = tempcol;
    }
    for (i = 0; i < matrixSize; i++) {
        for (j = i + 1; j < matrixColSize[i]; j++) {
            temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}

// 49. Group Anagrams
#define HASHSZ 200
struct groupInfo {
    int cnt[26];
    int idx;
    struct groupInfo* next;
};
/* accumulate each count for hash function */
int hashFunc(int* cnt)
{
    int val = 0;
    for (int i = 0; i < 26; i++) {
        val += cnt[i];
    }
    return (val % HASHSZ);
}
struct groupInfo** initTable(void)
{
    struct groupInfo** table = (struct groupInfo**)malloc(sizeof(struct groupInfo*) * HASHSZ);
    memset(table, 0, sizeof(struct groupInfo*) * HASHSZ);

    return table;
}
int findTable(struct groupInfo** table, int val, int* cnt)
{
    struct groupInfo* head = table[val];
    while (head) {
        if (0 == memcmp(head->cnt, cnt, sizeof(int) * 26)) {
            return head->idx;
        }
        head = head->next;
    }
    return -1;
}
void insertTable(struct groupInfo** head, int* cnt, int index)
{
    struct groupInfo* node = (struct groupInfo*)malloc(sizeof(struct groupInfo));
    memcpy(node->cnt, cnt, sizeof(int) * 26);
    node->idx = index;
    node->next = *head;
    *head = node;
}
char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    //iterate n strings
    //increase letter count
    //use the value to be hash, insert or get index
    int i, j, idx, col, sz, val;
    int cnt[26];

    *returnSize = 0;
    *returnColumnSizes = (int*)malloc(sizeof(int) * strsSize);
    memset(*returnColumnSizes, 0, sizeof(int) * strsSize);
    char*** returnBuf = (char***)malloc(sizeof(char**) * strsSize);
    for (i = 0; i < strsSize; i++) {
        //dynamic alloc
        returnBuf[i] = (char**)malloc(sizeof(char*));
    }

    struct groupInfo** tbl = initTable();

    for (i = 0; i < strsSize; i++) {
        memset(cnt, 0, sizeof(int) * 26);
        sz = (int)strlen(strs[i]);
        for (j = 0; j < sz; j++) {
            cnt[strs[i][j] - 'a']++;
        }

        val = hashFunc(cnt);
        idx = findTable(tbl, val, cnt);
        if (idx == -1) {
            //get new index
            idx = *returnSize;
            insertTable(&tbl[val], cnt, idx);
            (*returnSize)++;
        }

        char* str = (char*)malloc(sizeof(char) * (sz + 1));
        memcpy(str, strs[i], sz);
        str[sz] = '\0';

        col = (*returnColumnSizes)[idx];
        (*returnColumnSizes)[idx]++;
        returnBuf[idx] = (char**)realloc(returnBuf[idx], sizeof(char*) * (*returnColumnSizes)[idx]);
        returnBuf[idx][col] = str;
    }

    for (i = (*returnSize); i < strsSize; i++) {
        free(returnBuf[i]);
    }
    returnBuf = (char***)realloc(returnBuf, sizeof(char**) * (*returnSize));
    *returnColumnSizes = (int*)realloc(*returnColumnSizes, sizeof(int) * (*returnSize));

    return returnBuf;
}
#if 0
struct groupInfo {
    int no;
    int nums;
    int times[26];
    struct groupInfo* next;
};
char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes)
{
    int i, j, k;
    int count = 0;
    bool bFind;
    struct groupInfo* prior, *node;
    struct groupInfo* group = (struct groupInfo*)malloc(sizeof(struct groupInfo) * strsSize);
    memset(group, 0, sizeof(struct groupInfo) * strsSize);

    for (i = 0; i < strsSize; i++) {
        group[i].no = -1;
        for (k = 0; k < (int)strlen(strs[i]); k++) {
            group[i].times[strs[i][k] - 'a']++;
        }
        bFind = false;
        for (j = 0; j < i; j++) {
            if (group[j].no < 0)
                continue;
            if (memcmp(group[j].times, group[i].times, sizeof(int) * 26) == 0) {
                bFind = true;
                node = (struct groupInfo*)malloc(sizeof(struct groupInfo));
                node->no = i;
                node->nums = 0;
                node->next = NULL;
                prior = &group[j];
                prior->nums++;
                while (prior->next != NULL)
                    prior = prior->next;
                prior->next = node;
                break;
            }
        }
        if (!bFind) {
            group[i].no = i;
            group[i].nums = 1;
            count++;
        }
    }

    char*** ans = (char***)malloc(sizeof(char**) * strsSize);
    (*returnColumnSizes) = (int*)malloc(sizeof(int*) * count);
    count = 0;
    for (i = 0; i < strsSize; i++) {
        if (group[i].no != -1) {
            ans[count] = (char**)malloc(sizeof(char*) * group[i].nums);
            (*returnColumnSizes)[count] = group[i].nums;
            node = &group[i];
            for (j = 0; j < group[i].nums; j++) {
                int len = (int)strlen(strs[node->no]);
                ans[count][j] = (char*)malloc(len+1);
                memcpy(ans[count][j], strs[node->no], len);
                ans[count][j][len] = '\0';
                node = node->next;
            }
            count++;
        }
    }
    *returnSize = count;
    
    return ans;
}
#endif

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

// 56. Merge Intervals
void swapInter(int** inter1, int** inter2)
{
    int temp[2];
    int sizes = sizeof(int) * 2;
    memcpy(temp, *inter1, sizes);
    memcpy(*inter1, *inter2, sizes);
    memcpy(*inter2, temp, sizes);
}
void sortInter(int** intervals, int left, int right)
{
    if (left >= right)
        return;
    int temp[2];
    temp[0] = intervals[left][0];
    temp[1] = intervals[left][1];
    int i = left, j = right;
    while (i < j)
    {
        while (i < j && temp[0] <= intervals[j][0])
            j--;
        swapInter(&intervals[i], &intervals[j]);
        while (i < j && temp[0] >= intervals[i][0])
            i++;
        swapInter(&intervals[i], &intervals[j]);
    }

    sortInter(intervals, left, i - 1);
    sortInter(intervals, i + 1, right);
}
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes)
{
    int** ans;
    int count = 0;
    sortInter(intervals, 0, intervalsSize - 1);
    ans = (int**)malloc(sizeof(int*) * intervalsSize);
    (*returnColumnSizes) = (int*)malloc(sizeof(int) * intervalsSize);
    ans[count] = (int*)malloc(sizeof(int) * 2);
    ans[count][0] = intervals[0][0];
    ans[count][1] = intervals[0][1];
    (*returnColumnSizes)[count] = 2;
    for (int i = 1; i < intervalsSize; i++) {
        if (intervals[i][0] <= ans[count][1]) {
            ans[count][1] = (int)fmax(ans[count][1], intervals[i][1]);
        }
        else {
            count++;
            ans[count] = (int*)malloc(sizeof(int) * 2);
            (*returnColumnSizes)[count] = 2;
            ans[count][0] = intervals[i][0];
            ans[count][1] = intervals[i][1];
        }
    }
    *returnSize = count + 1;

    return ans;
}

// 59. Spiral Matrix II
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes)
{
    int i, j, m, k = 0;
    int** ans;
    *returnSize = n;
    ans = (int**)malloc(sizeof(int*) * n);
    (*returnColumnSizes) = (int*)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++) {
        ans[i] = (int*)malloc(sizeof(int) * n);
        (*returnColumnSizes)[i] = n;
    }
    i = 0, j = 0;
    m = 1;
    int begin = 0, end = n;
    while (begin < end) {
        i = begin, j = begin;
        for (; j < end; j++) {
            ans[i][j] = m++;
        }
        j--;
        i++;
        for (; i < end; i++) {
            ans[i][j] = m++;
        }

        j--;
        i--;
        for (; j >= begin; j--) {
            ans[i][j] = m++;
        }
        j++;
        i--;
        for (; i > begin; i--) {
            ans[i][j] = m++;
        }
        begin++, end--;
    }
    return ans;
}

// 62. Unique Paths
int uniquePaths(int m, int n)
{
    int i, j;
    int** dp = (int**)calloc(m, sizeof(int*));
    for (i = 0; i < m; i++) {
        dp[i] = (int*)calloc(n, sizeof(int));
        dp[i][0] = 1;
    }
    for (j = 1; j < n; j++)
        dp[0][j] = 1;
    for (i = 1; i < m; i++) {
        for (j = 1; j < n; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    int ans = dp[m - 1][n - 1];
    for (i = 0; i < m; i++)
        free(dp[i]);
    free(dp);
    return ans;
}

// 63. Unique Paths II
int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize)
{
    int i, j;
    bool block = false;
    int** dp = (int**)calloc(obstacleGridSize,sizeof(int*));
    block = false;
    for (i = 0; i < obstacleGridSize; i++) {
        dp[i] = (int*)calloc(obstacleGridColSize[i], sizeof(int));
        if (obstacleGrid[i][0])
            block = true;
        if (!block)
            dp[i][0] = 1;
    }
    for (i = 0; i < obstacleGridColSize[0] && obstacleGrid[0][i] == 0; i++) {
        dp[0][i] = 1;
    }
    for (i = 1; i < obstacleGridSize; i++) {
        block = false;
        for (j = 1; j < obstacleGridColSize[i]; j++) {
            if (obstacleGrid[i][j])
                continue;
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    int ans = dp[obstacleGridSize - 1][obstacleGridColSize[0] - 1];
    for (i = 0; i < obstacleGridSize; i++)
        free(dp[i]);
    free(dp);
    return ans;
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

// 75. Sort Colors
void sortColors(int* nums, int numsSize)
{
    int left = 0, right = numsSize - 1;
    int mid = 0;
    while (mid <= right) {
        switch (nums[mid]) {
        case 0:
            swap(&nums[mid], &nums[left]);
            left++;
            mid++;
            break;
        case 1:
            mid++;
            break;
        case 2: 
            swap(&nums[mid], &nums[right]);
            right--;
            break;
        }
    }
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

// 79. Word Search
int  searchpos[4][2] = { {-1,0,},{1,0},{0,-1},{0,1} };
bool searchword(char** board, bool** bmark, int m, int n, int i, int j, char* word)
{
    bool bflag[4] = { 0 };

    if (i < 0 || i >= m || j < 0 || j >= n)
        return false;

    if (strlen(word) == 0)
        return true;
    for (int k = 0; k < 4; k++)
    {
        int ni = i + searchpos[k][0], nj = j + searchpos[k][1];

        if (ni < 0 || ni >= m || nj < 0 || nj >= n)
            continue;
        if (bmark[ni][nj])
            continue;
        if (board[ni][nj] == word[0]) {
            if (strlen(word) == 1)
                return true;
            bmark[ni][nj] = true;
            if (searchword(board, bmark, m, n, ni, nj, &word[1]))
                return true;
            bmark[ni][nj] = false;
        }
    }
    return false;
}
bool exist(char** board, int boardSize, int* boardColSize, char* word)
{
    int i, j;
    bool** bmark = (bool**)calloc(boardSize, sizeof(bool*));
    for (i = 0; i < boardSize; i++)
        bmark[i] = (bool*)calloc(boardColSize[0], sizeof(bool));

    for (i = 0; i < boardSize; i++) {
        for (j = 0; j < boardColSize[0]; j++) {
            if (board[i][j] == word[0]) {
                bmark[i][j] = true;
                if (searchword(board, bmark, boardSize, boardColSize[0], 0, 0, &word[1]))
                    return true;
                bmark[i][j] = false;
            }
        }
    }
    return false;
}

// 82. Remove Duplicates from Sorted List II
struct ListNode* deleteDuplicatesII(struct ListNode* head)
{
    if (!head || !head->next)
        return head;

    struct ListNode* Dummy = (struct ListNode*)calloc(sizeof(struct ListNode), 1);
    Dummy->next = head;
    struct ListNode* prenode = Dummy, * node = head;
    int preval = INT_MIN;

    while (node) {
        if (node->val == preval) {
            prenode->next = node->next;
            free(node);
            node = prenode->next;
        }
        else {
            if (!node->next)
                break;
            preval = node->val;
            if (node->next->val == preval) {
                prenode->next = node->next;
                free(node);
                node = prenode->next;
            }
            else {
                prenode = node;
                node = node->next;
            }
        }
    }
    node = Dummy->next;
    free(Dummy);
    return node;
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

// 103. Binary Tree Zigzag Level Order Traversal
int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes)
{
    *returnSize = 0;
    (*returnColumnSizes) = (int*)malloc(sizeof(int) * 1000);
    (*returnColumnSizes)[0] = 0;
    if (!root)
        return NULL;

    int index = 0, begin = 0,height=0, size;
    bool bOrder = true;
    int** ans = (int**)malloc(sizeof(int*) * 2048);
    struct TreeNode** nodequeue = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 2048);
    struct TreeNode* node = NULL;
    nodequeue[index++] = root;
    while (begin < index) {
        size = index - begin;
        ans[height] = (int*)malloc(sizeof(int) * size);
        (*returnColumnSizes)[height] = size;
        for (int i = 0; i < size; i++) {
            node = nodequeue[begin+i];
            if (bOrder)
                ans[height][i] = node->val;
            else
                ans[height][size-i-1] = node->val;
            if(node->left)
                nodequeue[index++] = node->left;
            if (node->right)
                nodequeue[index++] = node->right;
        }
        begin += size;
        bOrder = !bOrder;
        height++;
    }
    free(nodequeue);

    *returnSize = height;
    return ans;
}

// 104. Maximum Depth of Binary Tree
int maxDepth(struct TreeNode* root)
{
    if (!root)
        return 0;
    return (int)fmax(maxDepth(root->left), maxDepth(root->right)) + 1;
}

// 105. Construct Binary Tree from Preorder and Inorder Traversal
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize)
{
    if (preorderSize <= 0)
        return NULL;

    struct TreeNode* root = (struct TreeNode*)calloc(sizeof(struct TreeNode), 1);
    int left,right, i;
    root->val = preorder[0];
    if (preorderSize == 1)
        return root;
    for (i = 0; i < inorderSize; i++) {
        if (inorder[i] == preorder[0])
        {
            left = i;
            right = preorderSize - i - 1;
            break;
        }
    }
    root->left = buildTree(&preorder[1], left, &inorder[0], left);
    root->right = buildTree(&preorder[i+1], right, &inorder[i+1], right);
    return root;
}

// 108. Convert Sorted Array to Binary Search Tree
struct TreeNode* sortedArrayToBST(int* nums, int numsSize)
{
    if (numsSize == 0)
        return NULL;
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = nums[numsSize / 2];
    root->left = sortedArrayToBST(&nums[0], numsSize / 2);
    if (numsSize / 2 + 1 > numsSize - 1)
        root->right = NULL;
    else
        root->right = sortedArrayToBST(&nums[numsSize / 2 + 1], (numsSize - 1) / 2);
    return root;
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

// 113. Path Sum II
int** pathSumAns = NULL;
void findPath(struct TreeNode* root, int target, int* path, int *curlen, int* returnSize, int** returnColumnSizes)
{
    if (!root)
        return;
    path[(*curlen)++] = root->val;
    if (target - root->val == 0 && !root->left && !root->right) {
        pathSumAns[*returnSize] = (int*)malloc(sizeof(int) * (*curlen));
        (*returnColumnSizes)[*returnSize] = *curlen;
        memcpy(pathSumAns[*returnSize], path, sizeof(int) * (*curlen));
        (*returnSize)++;
        (*curlen)--;
        return;
    }
    findPath(root->left, target - root->val, path, curlen, returnSize, returnColumnSizes);
    findPath(root->right, target - root->val, path, curlen, returnSize, returnColumnSizes);
    (*curlen)--;
    return;
}
int** pathSum(struct TreeNode* root, int targetSum, int* returnSize, int** returnColumnSizes)
{
    int sumpath[5000] = { 0 };
    int curlen = 0;

    *returnSize = 0;
    pathSumAns = (int**)malloc(sizeof(int*) * 4096);
    *returnColumnSizes = (int*)calloc(sizeof(int), 4096);

    findPath(root, targetSum, sumpath, &curlen, returnSize, returnColumnSizes);
    
    return pathSumAns;
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

// 117. Populating Next Right Pointers in Each Node II
struct Node* connect2(struct Node* root)
{
    if (!root)
        return root;

    struct Node** tempqueue = (struct Node**)malloc(sizeof(struct Node* )*6000);
    struct Node* pre, * next;
    int head = 0, tail = 0;
    tempqueue[tail++] = root;
    while (tail > head)
    {
        int end = tail;
        for (int i = head; i < end; i++) {
            pre = tempqueue[i];
            next = NULL;
            if (i < end - 1)
            {
                next = tempqueue[i+1];
            }
            pre->next = next;
            if (pre->left) {
                tempqueue[tail++] = pre->left;
            }
            if (pre->right) {
                tempqueue[tail++] = pre->right;
            }
        }
        head = end;
    }
    free(tempqueue);
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

// 119. Pascal's Triangle II
int* getRow(int rowIndex, int* returnSize)
{
    int* ans = (int*)malloc(sizeof(int) * (rowIndex + 1));
    *returnSize = rowIndex + 1;
    long temp = 1;
    for (int i = 0; i < rowIndex + 1; i++) {
        ans[i] = temp;
        temp = (temp * (rowIndex - i) / (i + 1));

    }
    return ans;
}

// 120. Triangle
//[[-1], [2, 3], [1, -1, -3]]
//int minTotalUtil(int** triangle, int m, int h, int j)
//{
//    if (h == m) {
//        return 0;
//    }
//    return triangle[h][j] + (int)fmin(minTotalUtil(triangle, m, h + 1, j), minTotalUtil(triangle, m, h + 1, j + 1));
//}
int minimumTotal(int** triangle, int triangleSize, int* triangleColSize)
{
    //return minTotalUtil(triangle, triangleSize, 0, 0);
    if (triangleSize == 1)
    {
        return triangle[0][0];
    }
    int i, j;
    int sum = INT_MAX;
    int** total = (int**)malloc(triangleSize*sizeof(int*));
    total[0] = (int*)malloc(sizeof(int));
    total[0][0] = triangle[0][0];
    for (i = 1; i < triangleSize; i++) {
        total[i] = (int*)malloc((i+1)*sizeof(int));
        total[i][0] = total[i - 1][0] + triangle[i][0];
        for (j = 1; j < i; j++) {
            total[i][j] = triangle[i][j] + (int)fmin(total[i-1][j], total[i-1][j - 1]);
        }
        total[i][i] = total[i - 1][i-1] + triangle[i][i];
    }
    for (j = 0; j < triangleSize; j++) {
        sum = total[triangleSize - 1][j] < sum ? total[triangleSize - 1][j] : sum;
    }
    for (i = 0; i < triangleSize; i++)
        free(total[i]);
    free(total);
    return sum;
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

// 134. Gas Station
int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize)
{
    int curSum = 0;
    int totalSum = 0;
    int start = 0;
    for (int i = 0; i < gasSize; i++) {
        curSum += gas[i] - cost[i];
        totalSum += gas[i] - cost[i];
        if (curSum < 0) {
            start = i + 1;
            curSum = 0;
        }
    }
    if (totalSum < 0)
        return -1;
    return start;
#if 0
    for (int i = 0; i < gasSize; i++)
    {
        int rest = gas[i] - cost[i];
        int index = (i+1) % gasSize;
        while (rest > 0 && index != i) {
            rest += gas[index] - cost[index];
            int index = (i + 1) % gasSize;
        }
        if (rest >= 0 && index == i)
            return i;
    }
    return -1;
#endif
}

// 136. Single Number
int singleNumber(int* nums, int numsSize)
{
    int number = nums[0];
    for (int i = 1; i < numsSize; i++) {
        number ^= nums[i];
    }
    return number;
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

// 143. Reorder List
void reorderList(struct ListNode* head)
{
    struct ListNode* temp=head, *pre=NULL, *last, *next;
    while (temp->next && temp->next->next)
    {
        next = temp->next;
        last = temp;
        while (last->next) {
            pre = last;
            last = last->next;
        }

        pre->next = NULL;
        temp->next = last;
        last->next = next;
        temp = temp->next->next;
    }
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

// 153. Find Minimum in Rotated Sorted Array
int findMin(int* nums, int numsSize)
{
    int target = INT_MIN;
    int left = 0, right = numsSize - 1, mid;
    if (numsSize == 1)
        return nums[0];
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (nums[mid + 1] < nums[mid])
            return nums[mid + 1];
        if (mid > 1 && nums[mid] < nums[mid - 1])
            return nums[mid];
        if (nums[mid] < nums[right])
            right = mid - 1;
        else
            left = mid + 1;
    }
    return nums[mid];
}


// 155. Min Stack
#define MAXNUM 30000
typedef struct {
    int minstack[MAXNUM];
    int top;
    int minval;
} MinStack;
MinStack* minStackCreate() {
    MinStack* obj = (MinStack*)calloc(sizeof(MinStack), 1);
    obj->top = -1;
    obj->minval = INT_MAX;
    return obj;
}
void minStackPush(MinStack* obj, int val) {
    if (obj->top < MAXNUM) {
        obj->minstack[++(obj->top)] = val;
        if (obj->minval > val)
            obj->minval = val;
    }
}
void minStackPop(MinStack* obj) {
    if (obj->top < 0)
        return;
    if (obj->minval == obj->minstack[obj->top])
    {
        obj->minval = INT_MAX;
        for (int i = 0; i < obj->top; i++) {
            if (obj->minval > obj->minstack[i])
                obj->minval = obj->minstack[i];
        }
    }
    obj->top--;
}
int minStackTop(MinStack* obj) {
    if (obj->top < 0 || obj->top >= MAXNUM)
        return -1;
    return obj->minstack[obj->top];
}
int minStackGetMin(MinStack* obj) {
    return obj->minval;
}
void minStackFree(MinStack* obj) {
    obj->top = -1;
    obj->minval = INT_MAX;
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

// 162. Find Peak Element
int findPeakElement(int* nums, int numsSize)
{
    int i;
    if (numsSize == 1 || nums[0] > nums[1])
        return 0;
    for (i = 1; i < numsSize - 1; i++)
    {
        if (nums[i] > nums[i + 1] && nums[i] > nums[i - 1])
            return i;
    }
    if (nums[i] > nums[i - 1])
        return i;
    return 0;
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

// 169. Majority Element
int majorityElement(int* nums, int numsSize)
{
    int major = nums[0], count = 1;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == major)
            count++;
        else
            count--;
        if (count < 0) {
            major = nums[i];
            count = 1;
        }
    }
    return major;
}

// 187. Repeated DNA Sequences
//int getbase(char c)
//{
//    int base = 2;
//    switch (c) {
//    case 'C':
//        base = 3;
//        break;
//    case 'G':
//        base = 5;
//        break;
//    case 'T':
//        base = 7;
//        break;
//    case 'A':
//    default:
//        base = 11;
//        break;
//    }
//    return base;
//}
char** findRepeatedDnaSequences(char* s, int* returnSize)
{
    int i, j, num;
    int count = (int)strlen(s);
    *returnSize = 0;
    if (count <= 10) {
        return NULL;
    }

    char** ans = (char**)malloc(sizeof(char*) * count);
    long* hashval = (long*)calloc(count - 9, sizeof(long));
    for (i = 0; i <= count - 10; i++) {
        num = 0;
        for (j = 0; j < 10; j++) {
            hashval[i] += hashval[i] * 4 + s[i+j];//(int)pow(getbase(s[i + j - 1]), j);
        }
    }
    for (int i = 0; i < count - 10; i++) {
        long curval = hashval[i];
        for (j = i + 1; j <= count - 10; j++) {
            if (hashval[i] > 0 && hashval[i] == hashval[j])
            {
                hashval[j] = -1;
                if (curval == hashval[i]) {
                    ans[(*returnSize)] = (char*)calloc(11, 1);
                    memcpy(ans[(*returnSize)++], &s[i], 10);
                    curval = -1;
                }
            }
        }
    }

    return ans;
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

// 190. Reverse Bits
uint32_t reverseBits(uint32_t n)
{
    uint32_t ans = 0;
    for (int i = 0; i < 32; i++) {
        ans <<= 1;
        ans += n % 2;
        n >>= 1;
    }
    return ans;
}

// 191. Number of 1 Bits
int hammingWeight(uint32_t n)
{
    int num = 0;
    while (n) {
        if (n % 2)
            num++;
        n >>= 1;
    }
    return num;
}

// 199. Binary Tree Right Side View
int* rightSideView(struct TreeNode* root, int* returnSize)
{
    *returnSize = 0;
    if (!root) {
        return NULL;
    }
    int* ans = (int*)malloc(sizeof(int) * 100);
    struct TreeNode* Queue[100], *node = NULL;
    int start =0, index = 0, height = 0;
    Queue[index++] = root;
    while (start < index)
    {
        int end = index;
        node = NULL;
        for (int i = start; i < end; i++) {
            node = Queue[i];
            if (node->left)
                Queue[index++] = node->left;
            if (node->right)
                Queue[index++] = node->right;
        }
        if(node)
            ans[height++] = node->val;
        start = end;
    }
    *returnSize = height;
    return ans;
}

// 198. House Robber
int rob(int* nums, int numsSize)
{
    if (numsSize == 1)
        return nums[0];
    int* robval = (int*)calloc(numsSize, sizeof(int));
    robval[0] = nums[0];
    robval[1] = (int)fmax(nums[0], nums[1]);
    //int robs0 = nums[0], robs1 = nums[1];
    for (int i = 2; i < numsSize; i++) {
        robval[i] = (int)fmax(robval[i - 2] + nums[i], robval[i - 1]);
    }
    int ans = robval[numsSize - 1];
    free(robval);
    return ans;
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

// 215. Kth Largest Element in an Array
int klargecmp(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}
int findKthLargest(int* nums, int numsSize, int k)
{
    qsort(nums, numsSize,sizeof(int), klargecmp);

    return nums[numsSize - k];
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

// 222. Count Complete Tree Nodes
int countNodes(struct TreeNode* root)
{
    int lheight = 0, rheight = 0;
    struct TreeNode* leftNode = root, * rightNode = root;
    if (!root)
        return 0;
    while (leftNode) {
        lheight++;
        leftNode = leftNode->left;
    }
    while (rightNode) {
        rheight++;
        rightNode = rightNode->right;
    }
    if (lheight == rheight)
        return (1 << lheight) - 1;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// 223. Rectangle Area
int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2)
{
    int area1 = (ax2 - ax1) * (ay2 - ay1);
    int area2 = (bx2 - bx1) * (by2 - by1);
    int area3 = (int)fmax(fmin(ax2,bx2)-fmax(ax1,bx1),0) * (int)fmax(fmin(ay2, by2) - fmax(ay1, by1), 0);

    return area1 + area2 - area3;
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

// 230. Kth Smallest Element in a BST
void midtrace(struct TreeNode* root, int * kth, int *k)
{
    if (!root)
        return ;
    midtrace(root->left, kth, k);
    if (*kth != INT_MIN)
        return;
    (*k)--;
    if ((*k) == 0) {
        *kth = root->val;
        return;
    }
    midtrace(root->right, kth, k);
}
int kthSmallest(struct TreeNode* root, int k)
{
    int kth = INT_MIN;
    midtrace(root, &kth, &k);
    return kth;
}

// 231. Power of Two
bool isPowerOfTwo(int n)
{
    if (n == 1)
        return true;
    if (n <= 0)
        return false;
    while (n > 1)
    {
        if (n % 2)
            return false;
        n /= 2;
    }
    return true;
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
    struct TreeNode* node = NULL;
    if (!root)
        return root;

    if (root->val > p->val && root->val > q->val) {
        node = lowestCommonAncestor(root->left, p, q);
    }else if (root->val < p->val && root->val < q->val) {
        node = lowestCommonAncestor(root->right, p, q);
    }
    if (node)
        return node;

    return root;
}

// 236. Lowest Common Ancestor of a Binary Tree
struct TreeNode* lowestCommonAncestorBT(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q)
{
    if (!root)
        return root;
    if (p == root || q == root)
        return root;
    struct TreeNode* locl = lowestCommonAncestor(root->left, p, q);
    struct TreeNode* locr = lowestCommonAncestor(root->right, p, q);
    if (locl && locr)
        return root;
    if(locl)
        return locl;
    return locr;
}

// 238. Product of Array Except Self
int* productExceptSelf(int* nums, int numsSize, int* returnSize)
{
    int* ans;
    ans = (int*)malloc(numsSize * sizeof(int));
    *returnSize = numsSize;
    int i,prefix;
    ans[numsSize - 1] = nums[numsSize - 1];
    for (i = numsSize - 2; i >= 0; i--) {
        ans[i] = ans[i + 1] * nums[i];
    }
    prefix = nums[0];
    ans[0] = ans[1];
    for (i = 1; i < numsSize - 1; i++) {
        ans[i] = ans[i + 1] * prefix;
        prefix *= nums[i];
    }
    ans[numsSize - 1] = prefix;
    return ans;
}

// 240. Search a 2D Matrix II
//bool searchMatrixII(int** matrix, int matrixSize, int* matrixColSize, int target)
bool searchMatrixII(vector<vector<int>> matrix, int matrixSize, int* matrixColSize, int target)
{
    int left = 0, right = matrixColSize[0] - 1, colm;
    int top = 0, bottom = matrixSize - 1, rowm;
    /*while (left <= right) {
        colm = left + (right - left) / 2; */
    for(colm=left;colm<=right;colm++)
    {
        top = 0, bottom = matrixSize - 1;
        if (matrix[top][colm] > target || matrix[bottom][colm] < target)
            continue;
        while (top <= bottom) {
            rowm = top + (bottom - top) / 2;
            if (matrix[rowm][colm] == target)
                return true;
            else if (matrix[rowm][colm] > target)
                bottom = rowm - 1;
            else
                top = rowm + 1;
        }
        //top = 0, bottom = matrixSize - 1;
        //rowm = top + (bottom - top) / 2;
        //if (matrix[rowm][colm] > target)
        //    right = colm - 1;
        //else
        //    left = colm + 1;
    }
    return false;
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

// 263. Ugly Number
bool isUgly(int n)
{
    int prior = n;
    while (n)
    {
        if (n == 1)
            return true;
        if (n % 2 == 0)
            n /= 2;
        if (n % 3 == 0)
            n /= 3;
        if (n % 5 == 0)
            n /= 5;
        if (prior == n)
            return false;
        prior = n;
    }
    return false;
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

// 290. Word Pattern
bool wordPattern(char* pattern, char* s)
{
    int pidx = 0, sidx = 0, plen = (int)strlen(pattern), slen = (int)strlen(s);
    int start = -1;
    char** whash = (char**)malloc(sizeof(char*) * 26);
    memset(whash, 0, sizeof(char*) * 26);
    while (sidx < slen) {
        if (sidx == slen - 1 || s[sidx] == ' ') {
            if (pidx >= plen)
                return false;
            int index = pattern[pidx++] - 'a';
            int len = sidx - start;
            len += (sidx == (slen - 1)) ? 1 : 0;
            if (!whash[index]) {
                for (int i = 0; i < 26; i++) {
                    if (i != index && whash[i] && !strncmp(whash[i], &s[start + 1], len - 1))
                        return false;
                }
                whash[index] = (char*)malloc(len);
                memcpy(whash[index], &s[start + 1], len - 1);
                whash[index][len - 1] = '\0';
            }
            else if (strncmp(whash[index], &s[start + 1], len - 1))
                return false;
            start = sidx;
        }
        sidx++;
    }
    return pidx != plen ? false : true;
}

// 297. Serialize and Deserialize Binary Tree
#if 0
/** Encodes a tree to a single string. */
typedef struct treequeue {
    struct TreeNode* tnode;
    struct treequeue* next;
}TreeQueue;
#define INVALIDTREEVAL      -1001
TreeQueue* tqHead = NULL, *tqTail = NULL;
void PushTNode(struct TreeNode* tnode)
{
    TreeQueue* node = (TreeQueue*)calloc(1, sizeof(TreeQueue));
    node->tnode = tnode;
    node->next = NULL;
    if (!tqTail) {
        tqHead = tqTail = node;
    }
    else {
        tqTail->next = node;
        tqTail = node;
    }
}
struct TreeNode* PopTNode()
{
    if (!tqHead)
        return NULL;

    struct TreeNode* tnode;
    TreeQueue* node = tqHead;
    tqHead = tqHead->next;
    if (!tqHead)
        tqTail = NULL;
    tnode = node->tnode;
    free(node);
    return tnode;
}
char* serialize(struct TreeNode* root) {
    int* nodeval = NULL;
    int  INVALID = -2000;
    long cur = 0;
    char* ans = (char*)calloc(120200, sizeof(char));
    ans[cur++] = '[';
    if (!root) {
        ans[cur++] = ']';
        return &ans[0];
    }

    tqHead = tqTail = NULL;
    bool bValid = true;
    int  i=0, base = 1, len;
    struct TreeNode* tnode;
    long lastpos = cur;
    PushTNode(root);
    while (bValid)
    {
        bValid = false;
        for (i = 0; i < base; i++)
        {
            tnode = PopTNode();
            if (!tnode) {
                PushTNode(NULL);
                PushTNode(NULL);
                memcpy(&ans[cur], "null,", 5);
                cur += 5;
            }
            else
            {
                PushTNode(tnode->left);
                PushTNode(tnode->right);
                bValid |= (tnode->left || tnode->right);
                len = sprintf(&ans[cur], "%d,", tnode->val);
                cur += len;
                lastpos = cur;
            }
        }
        base *= 2;
    }
    if (ans[lastpos -1] == ',')
        lastpos--;
    ans[lastpos++] = ']';
    ans[lastpos++] = '\0';
    return &ans[0];
}

/** Decodes your encoded data to tree. */
struct TreeNode* createBTTree(int* data, int num, int cur)
{
    if (cur > num || data[cur-1] == INVALIDTREEVAL)
        return NULL;

    struct TreeNode* tnode;
    tnode = (struct TreeNode*)calloc(1, sizeof(struct TreeNode));
    tnode->val = data[cur-1];

    tnode->left = createBTTree(data, num, 2 * cur);
    tnode->right = createBTTree(data, num, 2 * cur+1);
    return tnode;
}
struct TreeNode* deserialize(char* data) {
    if (!data)
        return NULL;
    int len = (int)strlen(data);
    if (len <= 2)
        return NULL;
    if(data[0] != '[' || data[len-1] != ']')
        return NULL;

    int* digdata = (int*)malloc(20000*sizeof(int));
    int num = 0;
    char buffer[8];
    int i, pos=0;
    for (i = 1; i < len; i++) {
        if (data[i] == ' ')
            continue;
        if (data[i] == ',' || data[i] == ']') {
            buffer[pos++] = '\0';
            if (0 == strlen(buffer)) {
                pos = 0;
            }
            else if (0 == strcmp(buffer, "null"))
                digdata[num++] = INVALIDTREEVAL;
            else
                digdata[num++] = atoi(buffer);
            memset(buffer, 0, 8);
            pos = 0;
        }
        else {
            buffer[pos++] = data[i];
        }
    }

    struct TreeNode* root = createBTTree(digdata, num, 1);
    free(digdata);

    return root;
}
#else

void DFS(struct TreeNode* root, char* ans, int* ansIdx, char* tmp)
{
    if (!root)
    {
        ans[(*ansIdx)++] = 'N'; /* means NULL */
        ans[(*ansIdx)++] = '#';
        return;
    }

    sprintf(tmp, "%d#", root->val);
    int len = (int)strlen(tmp);
    memcpy(&ans[*ansIdx], tmp, sizeof(char) * len);
    *ansIdx += len; /* update index */
    DFS(root->left, ans, ansIdx, tmp);
    DFS(root->right, ans, ansIdx, tmp);
}

/** Encodes a tree to a single string. */
char* serialize(struct TreeNode* root) {
    char* ans = (char*)calloc(100000, sizeof(char));
    char* tmp = (char*)calloc(7, sizeof(char));
    int ansIdx = 0;
    DFS(root, ans, &ansIdx, tmp);
    return ans;
}

struct TreeNode* DeDFS(char* data, int len, int* dataIdx)
{
    if (*dataIdx >= len)
        return NULL;

    if (data[*dataIdx] == 'N')
    {
        (*dataIdx) += 2;
        return NULL;
    }

    struct TreeNode* root = (struct TreeNode*)calloc(1, sizeof(struct TreeNode));
    int negative = 0;
    if (data[(*dataIdx)] == '-')
    {
        (*dataIdx)++;
        negative = 1;
    }
    while (data[(*dataIdx)] != '#')
    {
        root->val *= 10;
        root->val += data[(*dataIdx)++] - 0x30;
    }
    if (negative)
        root->val *= -1;
    (*dataIdx)++;

    root->left = DeDFS(data, len, dataIdx);
    root->right = DeDFS(data, len, dataIdx);
    return root;
}

/** Decodes your encoded data to tree. */
struct TreeNode* deserialize(char* data) {
    struct TreeNode* root;
    int dataIdx = 0;
    root = DeDFS(data, (int)strlen(data), &dataIdx);
    return root;
}
#endif

// 299. Bulls and Cows
char* getHint(char* secret, char* guess)
{
    int i;
    int len = (int)strlen(secret);
    int bulls = 0, cows = 0;
    int freqA[10] = { 0 };
    int freqB[10] = { 0 };
    char* ans = (char*)calloc(10, sizeof(char));
    for (i = 0; i < len; i++) {
        if (secret[i] == guess[i])
            bulls++;
        else {
            freqA[secret[i] - '0']++;
            freqB[guess[i] - '0']++;
        }
    }
    for (i = 0; i < 10; i++)
    {
        if (freqA[i] < freqB[i])
            cows += freqA[i];
        else
            cows += freqB[i];
    }
    sprintf(ans, "%dA%dB", bulls, cows);
    return &ans[0];
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

// 347. Top K Frequent Elements
int* topKFrequent(int* nums, int numsSize, int k, int* returnSize)
{
    int i;
    int* freq = (int*)calloc(20001, sizeof(int));
    for (i = 0; i < numsSize; i++) {
        freq[nums[i]]++;
    }

    return NULL;
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

// 374. Guess Number Higher or Lower
int guess(int num)
{
    return 0;
}
int guessNumber(int n)
{
    int left = 1, right = n;
    int mid;
    while (left <= right) {
        mid = left + (right - left) / 2;
        switch (guess(mid)) {
        case -1:
            right = mid - 1;
            break;
        case 1:
            left = mid + 1;
            break;
        case 0:
            return mid;
            break;
        }
    }
    return left;
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

// 394. Decode String
char* decodeString(char* s)
{
    char* result = (char*)calloc(8192, sizeof(char));
    char* temp = NULL;
    int pos = 0;
    int x, count, j;
    for (int i = 0; i < (int)strlen(s); ) {
        x = 0;
        count = 0;

        while (s[i] - '0' >= 0 && s[i] - '0' <= 9 && (int)strlen(s)) {
            x = x * 10 + s[i] - '0';
            i++;
        }

        if (s[i] == '[') {
            i++;
            count = 1;
        }
        j = i;

        while (count != 0 && j < (int)strlen(s)) {
            if (s[j] == '[') count++;
            else if (s[j] == ']') count--;
            j++;
        }

        if (x > 0)
        {
            char sub[30] = { 0 };
            memcpy(sub, &s[i], j - i - 1);
            temp  = decodeString(&sub[0]);
        }

        while (x--)
        {
            memcpy(&result[pos], temp, strlen(temp));
            pos += (int)strlen(temp);
        }

        i = j;
        if (s[i] - 'a' >= 0 && s[i] - 'a' < 26 || s[i] - 'A' >= 0 && s[i] - 'A' < 26) {
            result[pos++] = s[i];
            i++;
        }
    }
    return result;
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

// 415. Add Strings
char* addStrings(char* num1, char* num2)
{
    int len1 = (int)strlen(num1);
    int len2 = (int)strlen(num2);
    int len = len1 > len2 ? len1 + 1 : len2 + 1;
    char* ans = (char*)malloc(len+1);
    int val =0;
    memset(ans, 0, len + 1);
    while (len1 && len2) {
        val += num1[len1-- - 1] - '0' + num2[len2-- - 1] - '0';
        ans[len-- - 1] = val % 10 + '0';
        val /= 10;
    }
    while(len1) {
        val += num1[len1-- - 1] - '0';
        ans[len-- -1] = val % 10 + '0';
        val /= 10;
    }
    while (len2) {
        val += num2[len2-- - 1] - '0';
        ans[len-- -1] = val % 10 + '0';
        val /= 10;
    }
    if (val > 0)
        ans[len-- - 1] = '1';
    return &ans[len];
}

// 424. Longest Repeating Character Replacement
int characterReplacement(char* s, int k)
{
    int start = 0, i = 0;
    int counter = 0, maxlen = 0;
    int len = (int)strlen(s);
    int freq[26] = { 0 };
    for ( i = 0; i < len; i++) {
        freq[s[i] - 'A']++;
        counter = (int)fmax(counter, freq[s[i] - 'A']);
        if (i - start + 1 - counter > k) {
            freq[s[start] - 'A']--;
            start++;
        }
        maxlen = (int)fmax(maxlen, i - start + 1);

    }

    return maxlen;
}

// 435. Non - overlapping Intervals
/*
Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.
*/
#if 0
void swapInter(int** inter1, int** inter2)
{
    int temp[2];
    int sizes = sizeof(int) * 2;
    memcpy(temp, *inter1, sizes);
    memcpy(*inter1, *inter2, sizes);
    memcpy(*inter2, temp, sizes);
}
void sortInter(int** intervals, int left, int right)
{
    if (left >= right)
        return;
    int temp[2];
    temp[0] = intervals[left][0];
    temp[1] = intervals[left][1];
    int i = left, j = right;
    while (i < j)
    {
        while (i < j && temp[0] <= intervals[j][0])
            j--;
        swapInter(&intervals[i], &intervals[j]);
        while (i < j && temp[0] >= intervals[i][0])
            i++;
        swapInter(&intervals[i], &intervals[j]);
    }

    sortInter(intervals, left, i - 1);
    sortInter(intervals, i + 1, right);
}
#endif
int cmp(const void* a, const void* b) {
    int* t1 = *(int**)a;
    int* t2 = *(int**)b;
    int dif = t1[1] - t2[1];
    if (dif == 0)
        dif = t1[0] - t2[0];
    return  dif;
}
int eraseOverlapIntervals(int** intervals, int intervalsSize, int* intervalsColSize)
{
    if (intervalsSize < 2)
        return 0;
    //sortInter(intervals, 0, intervalsSize - 1);
    qsort(intervals, intervalsSize, sizeof(int*), cmp);

    int i = 0, j = 1;
    int ans = 0;
    while (j < intervalsSize) {
        if (intervals[i][1] <= intervals[j][0]) {
            i=j; j++;
        }
        else if (intervals[i][1] < intervals[j][1]) {
            ans++;
            j++;
        }
        else if (intervals[i][1] >= intervals[j][1])
        {
            ans++;
            i = j; j++;
        }
    }
    return ans;
}

// 438. Find All Anagrams in a String
int* findAnagrams(char* s, char* p, int* returnSize)
{
    int sLen = (int)strlen(s);
    int pLen = (int)strlen(p);
    if (pLen > sLen) {
        *returnSize = 0;
        return NULL;
    }

    int pchar[26] = { 0 };
    int schar[26] = { 0 };
    int nums = 0;
    int i = 0;
    int* res = (int*)malloc(sizeof(int) * (sLen - pLen + 1));
    for (i = 0; i < pLen; i++) {
        pchar[p[i] - 'a']++;
        schar[s[i] - 'a']++;
    }
    for (i=pLen; i <= sLen; i++) {
        if (memcmp(pchar, schar, 26 * sizeof(int)) == 0) {
            res[nums++] = i - pLen;
        }
        schar[s[i - pLen] - 'a']--;
        if(i<sLen)
            schar[s[i] - 'a']++;
    }
    *returnSize = nums;
    return res;
}

// 450. Delete Node in a BST
struct TreeNode* deleteNode(struct TreeNode* root, int key)
{
    struct TreeNode* temp = NULL;
    if (!root)
        return root;
    if (root->val == key) {
        if (!root->left && !root->right)
            return NULL;
        if (!root->left)
            return root->right;
        if (!root->right)
            return root->left;

        temp = root->right;
        while (temp->left != NULL)
            temp = temp->left;
        temp->left = root->left;
        return root->right;
    }
    if (root->val > key) {
        root->left = deleteNode(root->left, key);
    }
    else {
        root->right = deleteNode(root->right, key);
    }
    return root;
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

// 547. Number of Provinces
void dfsProvinces(int** isConnected, int isConnectedSize, int* isConnectedColSize, int index)
{
    int i = 0;
    for (i = 0; i < isConnectedSize; i++) {
        if (isConnected[index][i])
        {
            isConnected[index][i] = 0;
            isConnected[i][index] = 0;
            dfsProvinces(isConnected, isConnectedSize, isConnectedColSize, i);
        }
    }
}
int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize)
{
    int i, j;
    int count = 0;

    for (i = 0; i < isConnectedSize; i++) {
        for (j = 0; j < isConnectedColSize[i]; j++)
        {
            if (isConnected[i][j]) {
                count++;
                dfsProvinces(isConnected, isConnectedSize, isConnectedColSize, i);
            }
        }
    }
    return count;
}

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

// 560. Subarray Sum Equals K
int subarraySum(int* nums, int numsSize, int k)
{
    int temp[20000000] = { 0 };
    int idx = 1, sum = 0, count = 0;
    temp[10000000] = 1;
    for (int i = 0; i < numsSize; i++)
    {
        sum += nums[i];
        count += temp[sum - k + 10000000];
        temp[sum + 10000000]++;
    }
    return count;
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

// 572. Subtree of Another Tree
bool compsubtree(struct TreeNode* root1, struct TreeNode* root2)
{
    if (!root1 && !root2)
        return true;
    if (!root1 || !root2)
        return false;
    if (root1->val != root2->val)
        return false;
    if (!compsubtree(root1->left, root2->left))
        return false;
    if (!compsubtree(root1->right, root2->right))
        return false;
    return true;
}
bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot)
{
    if (!root && !subRoot)
        return true;
    if (!root || !subRoot)
        return false;
    if (root->val == subRoot->val)
    {
        if (compsubtree(root, subRoot))
            return true;
    }
    if (isSubtree(root->left, subRoot))
        return true;
    if (isSubtree(root->right, subRoot))
        return true;
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
struct TreeNode* mergeTrees(struct TreeNode* root1, struct TreeNode* root2)
{
    if (!root1)
        return root2;
    if (!root2)
        return root1;
    root1->val += root2->val;

    root1->left = mergeTrees(root1->left, root2->left);
    root1->right = mergeTrees(root1->right, root2->right);
    return root1;
}

// 653. Two Sum IV - Input is a BST
void prefindtarget(struct TreeNode* root, int* vals, int* nums)
{
    if (!root)
        return;

    prefindtarget(root->left, vals, nums);
    vals[(*nums)++] = root->val;
    prefindtarget(root->right, vals, nums);
}
bool findTarget(struct TreeNode* root, int k)
{
    int* treeval = (int*)malloc(sizeof(int) * 10000);
    int  nums = 0;

    prefindtarget(root, treeval, &nums);
    int left = 0, right = nums - 1;
    int diff;
    while (left < right)
    {
        diff = k - treeval[left];
        if (diff == treeval[right])
            return true;
        else if (diff < treeval[right])
            right--;
        else
            left++;
    }
    return false;
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

// 700. Search in a Binary Search Tree
struct TreeNode* searchBST(struct TreeNode* root, int val)
{
    if (!root)
        return NULL;

    if (root->val == val)
        return root;
    if (root->val > val) {
        return searchBST(root->left, val);
    }

    return searchBST(root->right, val);
}

// 701. Insert into a Binary Search Tree
struct TreeNode* insertIntoBST(struct TreeNode* root, int val)
{
    if (!root)
    {
        struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        node->val = val;
        node->left = node->right = NULL;
        return node;
    }

    if (root->val > val) {
        root->left = insertIntoBST(root->left, val);
    }
    else {
        root->right = insertIntoBST(root->right, val);
    }
    return root;
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

// 706. Design HashMap
// myself HashMap


// 707. Design Linked List
// MyLinkedList

// 713. Subarray Product Less Than K
int numSubarrayProductLessThanK(int* nums, int numsSize, int k)
{
    int count = 0;
    if (k <= 1)
        return count;

    int i1 = 0;
    int prod = 1;

    for (int i2 = 0; i2 < numsSize; i2++) {
        prod *= nums[i2];

        while (prod >= k) {
            prod /= nums[i1];
            ++i1;
        }

        count += i2 - i1 + 1;
    }

    return count;
}

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
    suml = (int*)calloc((numsSize + 1) , sizeof(int));
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

// 746. Min Cost Climbing Stairs
int minCostClimbingStairs(int* cost, int costSize)
{
    int dp0 = 0, dp1 = 0;
    for (int i = 2; i <= costSize; i++) {
        int dpi = (int)fmin(dp0 + cost[i - 2], dp1 + cost[i - 1]);
        dp0 = dp1;
        dp1 = dpi;
    }
    return dp1;
}

// 763. Partition Labels
int* partitionLabels(char* s, int* returnSize)
{
    int i, count = (int)strlen(s);
    int last[26] = { 0 };

    for (i = 0; i < count; i++) {
        last[s[i] - 'a'] = i;
    }

    *returnSize = 0;
    int j = 0, anchor = 0;
    int* ans = (int*)malloc(sizeof(int)* count);

    for (int i = 0; i < count; ++i) {
        j = j > last[s[i] - 'a'] ? j : last[s[i] - 'a'];
        if (i == j) {
            ans[(*returnSize)++] = i - anchor + 1;
            anchor = i + 1;
        }
    }
    return ans;
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
    LCPath = (char*)calloc(len + 1, 1);
    CurLCPath = 0;
    CurLC = 0;
    backTrackLCPerm(s, len, 0);
    free(LCPath);
    *returnSize = CurLC;
    return LCAns;
}

// 841. Keys and Rooms
void dfsroom(int** rooms, int* roomsColSize, int cur, bool* visited)
{
    visited[cur] = true;
    for (int i = 0; i < roomsColSize[cur]; i++) {
        if (!visited[rooms[cur][i]]) {
            dfsroom(rooms, roomsColSize, rooms[cur][i], visited);
        }
    }
}
bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize)
{
    bool* visited = (bool*)calloc(roomsSize, sizeof(bool));
    dfsroom(rooms, roomsColSize, 0, visited);
    for (int i = 0; i < roomsSize; i++) {
        if (!visited[i])
            return false;
    }
    return true;
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

// 944. Delete Columns to Make Sorted
int minDeletionSize(char** strs, int strsSize)
{
    int ans = 0;
    if (strsSize <= 1)
        return 0;

    for (int i = 0; i < (int)strlen(strs[0]); i++) {
        for (int j = 1; j < strsSize; j++) {
            if (strs[j][i] < strs[j - 1][i]) {
                ans++;
                break;
            }
        }
    }
    return ans;
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

// 986. Interval List Intersections
int** intervalIntersection(int** firstList, int firstListSize, int* firstListColSize, int** secondList, int secondListSize, int* secondListColSize, int* returnSize, int** returnColumnSizes)
{
    int first = 0, second = 0;
    int count = 0;

    int** ans = (int**)calloc(firstListSize + secondListSize, sizeof(int*));
    (*returnColumnSizes) = (int*)malloc(sizeof(int) * (firstListSize + secondListSize));

    while (first < firstListSize && second < secondListSize) {
        int start = (int)fmax(firstList[first][0], secondList[second][0]);
        int end = (int)fmin(firstList[first][1], secondList[second][1]);
        if (start <= end) {
            ans[count] = (int*)malloc(sizeof(int) * 2);
            (*returnColumnSizes)[count] = 2;
            ans[count][0] = start;
            ans[count][1] = end;
            count++;
        }
        if (firstList[first][1] < secondList[second][1])
            first++;
        else if (firstList[first][1] > secondList[second][1])
            second++;
        else //equal
        {
            first++;
            second++;
        }
    }

    *returnSize = count;
    return ans;
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

// 997. Find the Town Judge
int findJudge(int n, int** trust, int trustSize, int* trustColSize)
{
    int i;
    int* person = (int*)calloc(n+1, sizeof(int));
    int* judge = (int*)calloc(n + 1, sizeof(int));
    for (i = 0; i < trustSize; i++)
    {
        person[trust[i][0]] = 1;
        judge[trust[i][1]]++;
    }
    for (i = 1; i <= n; i++)
    {
        if (person[i] != 1 && judge[i] == n-1)
            return i;
    }
    return -1;
}

// 1046. Last Stone Weight
void swapStone(char* a, char* b, size_t size)
{
    do
    {
        char tmp = *a;
        *(a++) = *b;
        *(b++) = tmp;
    } while (--size > 0);
}

/// Take an (otherwise valid) heap where the last element may be out of
/// order and restore the heap property.
void heap_sift_up(void* base, size_t nmemb, size_t size,
    int (*cmp)(const void*, const void*))
{
    if (!nmemb) return;
    for (size_t child_idx = nmemb - 1; child_idx; )
    {
        size_t parent_idx = (child_idx + 1) / 2 - 1;
        void* parent = (char*)base + parent_idx * size;
        void* child = (char*)base + child_idx * size;
        if (cmp(parent, child) <= 0)
            break;
        swapStone((char*)parent, (char*)child, size);
        child_idx = parent_idx;
    }
}

/// Take an (otherwise valid) heap where the first element may be out of
/// order and restore the heap property.
void heap_sift_down(void* base, size_t nmemb, size_t size,
    int (*cmp)(const void*, const void*))
{
    size_t parent_idx = 0;
    size_t limit = nmemb / 2;
    while (parent_idx < limit)
    {
        size_t child_idx = (parent_idx + 1) * 2 - 1;
        void* parent = (char*)base + parent_idx * size;
        void* child = (char*)base + child_idx * size;
        if (child_idx + 1 < nmemb && cmp(child, (char*)child + size) >= 0)
        {
            ++child_idx;
            child = (char*)child + size;
        }
        if (cmp(parent, child) <= 0)
            break;
        swapStone((char*)parent, (char*)child, size);
        parent_idx = child_idx;
    }
}

/// Reorder an array so that it becomes a valid binary min heap.
static void heap_heapify(void* base, size_t nmemb, size_t size,
    int (*cmp)(const void*, const void*))
{
    for (size_t i = 2; i <= nmemb; ++i)
        heap_sift_up(base, i, size, cmp);
}

/// Return -1/0/1 if the first argument is
/// GREATER than / equal to / SMALLER than the second argument.
static int cmp_int_rev(const void* ptr1, const void* ptr2)
{
    int a = *(int*)ptr1, b = *(int*)ptr2;
    return (a < b) - (a > b);
}

int lastStoneWeight(int* stones, int stones_length)
{
    // reorder `stones` so that it becomes a binary max heap (greatest value first)
    heap_heapify(stones, stones_length, sizeof(*stones), cmp_int_rev);

    // repeatedly process the two heaviest stones
    while (stones_length > 1)
    {
        // remove the heaviest stone from the heap by storing its weight in `stone1`,
        // then replace the first element of the heap (the heaviest stone)
        // with the last element (the lightest stone)
        // and restore the heap property by calling `heap_sift_down`
        int stone1 = stones[0];
        stones[0] = stones[--stones_length];
        heap_sift_down(stones, stones_length, sizeof(*stones), cmp_int_rev);

        if (stone1 == stones[0])
            // if both stones have equal weight,
            // remove the second stone from the heap
            // by replacing the first element (the second stone)
            // with the last element and shrinking the heap
            stones[0] = stones[--stones_length];
        else
            // if the second stone is smaller,
            // replace the first element (the second stone)
            // with the difference of the two stones
            stones[0] = stone1 - stones[0];

        // the first element has changed, we have to restore the heap property
        heap_sift_down(stones, stones_length, sizeof(*stones), cmp_int_rev);
    }

    return stones_length == 0 ? 0 : *stones;
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

// 1091. Shortest Path in Binary Matrix
int eight[8][2] = { {1,1}, {1,0},{0,1},{-1,1},{1,-1},{-1,0},{0,-1},{-1,-1} };
void  dfsBM(int** grid, int gridSize, int i, int j)
{
    int k, m, n;
    if (i < 0 || i >= gridSize || j < 0 || j >= gridSize)
        return ;
    if (i == gridSize - 1 && j == gridSize - 1)
    {
        return ;
    }
    for (k = 0; k < 8; k++) {
        m = i + eight[k][0];
        n = j + eight[k][1];
        if (m < 0 || m >= gridSize || n < 0 || n >= gridSize)
            continue;
        if (grid[m][n] != 0)
            continue;

        grid[m][n] = grid[i][j] + 1;
        dfsBM(grid, gridSize, m, n);
    }
}
int shortestPathBinaryMatrix(int** grid, int gridSize, int* gridColSize)
{
    if (grid[0][0] == 1 || grid[gridSize-1][gridSize-1] == 1)
        return -1;

    grid[0][0] = 1;
    dfsBM(grid, gridSize, 0, 0);

    return grid[gridSize - 1][gridSize - 1];
}

// 1143. Longest Common Subsequence
int longestCommonSubsequence(char* text1, char* text2)
{
    int m = (int)strlen(text1), n = (int)strlen(text2);
    int i, j;
    int** ans = (int**)malloc((m+1) * sizeof(int*));
    ans[0] = (int*)calloc((n + 1), sizeof(int));
    for (i = 0; i < m; i++) {
        ans[i + 1] = (int*)malloc((n + 1) * sizeof(int));
        ans[i + 1][0] = ans[i][0];
        for (j = 0; j < n; j++) {
            ans[i + 1][j + 1] = text1[i] == text2[j] ? ans[i][j] + 1 : (int)fmax(ans[i + 1][j], ans[i][j + 1]);
        }
    }
    int max = ans[m][n];
    for (i = 0; i < m; i++)
        free(ans[i]);
    free(ans);
    return max;
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

// 1249. Minimum Remove to Make Valid Parentheses
char* minRemoveToMakeValid(char* s)
{
    char* result = (char*)calloc(strlen(s) + 1, sizeof(char));
    int* stack = (int*)malloc(strlen(s) * sizeof(int));
    int idx = -1;
    int i;
    for (i = 0; i < (int)strlen(s); i++)
        if (s[i] == '(')
            stack[++idx] = i;
        else if (s[i] == ')')
        {
            if (idx >= 0)
                idx--;
            else
                s[i] = ' ';
        }
    for (i = 0; i <= idx; i++)
        s[stack[i]] = ' ';
    int id = 0;
    for (int i = 0; i < (int)strlen(s); i++)
        if (s[i] != ' ')
            result[id++] = s[i];
    return result;
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
    int* result = (int*)calloc(numsSize, sizeof(int));

    *returnSize = numsSize;
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

// 1557. Minimum Number of Vertices to Reach All Nodes
int* findSmallestSetOfVertices(int n, int** edges, int edgesSize, int* edgesColSize, int* returnSize)
{
    int* ans = (int*)malloc(n * sizeof(int));
    int* temp = (int*)calloc(n, sizeof(int));
    int count = 0, i = 0;

    for (i = 0; i < edgesSize; i++) {
        temp[edges[i][0]] = 1;
    }
    for (i = 0; i < edgesSize; i++) {
        temp[edges[i][1]] = 0;
    }
    for (i = 0; i < n; i++) {
        if (temp[i] == 1)
            ans[count++] = i;
    }
    *returnSize = count;
    return ans;
}

// 1657. Determine if Two Strings Are Close
int cmpfunc(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}
bool closeStrings(char* word1, char* word2)
{
    int len1 = (int)strlen(word1), len2 = (int)strlen(word2);
    int freq1[26] = { 0 }, freq2[26] = { 0 };
    bool alp1[26] = { false }, alp2[26] = { false };
    int i;
    if (len1 != len2)
        return false;
    for (i = 0; i < len1; i++) {
        alp1[word1[i] - 'a'] = true;
        alp2[word2[i] - 'a'] = true;
        freq1[word1[i] - 'a']++;
        freq2[word2[i] - 'a']++;
    }
    if (0 != memcmp(alp1, alp2, 26))
        return false;

    qsort(freq1, 26, sizeof(int), cmpfunc);
    qsort(freq2, 26, sizeof(int), cmpfunc);
    if (0 != memcmp(freq1, freq2, 26*sizeof(int)))
        return false;

    return true;
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

// 1704. Determine if String Halves Are Alike
bool IsVowels(char ch) {
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
    }
    return false;
}
bool halvesAreAlike(char* s)
{
    int left = 0, right = (int)strlen(s);
    int lnum = 0, rnum = 0;
    while (left < right) {
        if (IsVowels(s[left++]))
            lnum++;
        if (IsVowels(s[right--]))
            rnum++;
    }
    if (lnum == rnum)
        return true;
    return false;
}

// 1823. Find the Winner of the Circular Game
int findTheWinner(int n, int k)
{
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = (ans + k) % i;
    return ans + 1;
    int i, j, index=0;
    bool* found = (bool*)calloc(n, sizeof(bool));
    for (i = 0; i < n - 1; i++) {
        j = k;
        while (j > 0) {
            index = (++index) % n;
            if (found[index])
            {
                continue;
            }
            j--;
        }
        found[index] = true;
    }
    for (i = 0; i < n; i++)
        if (!found[i])
            break;
    free(found);
    return i==0?n:i;
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