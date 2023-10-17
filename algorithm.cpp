#include "algorithm.h"
int cmpfun(const void* a, const void* b) {
    return (*(int*)a) - (*(int*)b);
}
int Rcmpfun(const void* a, const void* b) {
    return (*(int*)b) - (*(int*)a);
}
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

// 4. Median of Two Sorted Arrays
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    if (nums1Size > nums2Size)
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);

    int m = nums1Size;
    int n = nums2Size;
    int left = 0, right = m;

    while (left <= right) {
        int partition1 = (left + right) / 2;
        int partition2 = (m + n + 1) / 2 - partition1;

        int maxLeft1 = (partition1 == 0) ? INT_MIN : nums1[partition1 - 1];
        int minRight1 = (partition1 == m) ? INT_MAX : nums1[partition1];

        int maxLeft2 = (partition2 == 0) ? INT_MIN : nums2[partition2 - 1];
        int minRight2 = (partition2 == n) ? INT_MAX : nums2[partition2];

        if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
            if ((m + n) % 2 == 0) {
                return (double)(fmax(maxLeft1, maxLeft2) + fmin(minRight1, minRight2)) / 2;
            }
            else {
                return (double)fmax(maxLeft1, maxLeft2);
            }
        }
        else if (maxLeft1 > minRight2) {
            right = partition1 - 1;
        }
        else {
            left = partition1 + 1;
        }
    }
    return 0;
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

// 7. Reverse Integer
int reverse(int x)
{
    long long result = 0;

    while (x)
    {
        result = result * 10 + x % 10;
        x = x / 10;
        if (result > INT_MAX || result < INT_MIN)
            return 0;
    }
    return (int)result;
}

// 8. String to Integer (atoi)
int myAtoi(char* s) {
    long long min = (long long)pow(2, 31);
    long long max = (long long)pow(2, 31) - 1;
    long long ans = 0;
    bool digit = false;
    int flag = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            digit = true;
            ans = ans * 10 + s[i] - '0';
            if (ans > min)
                break;
            continue;
        }
        if (digit)
            break;
        if (s[i] == '+' || s[i] == '-') {
            if (flag != 0)
                return 0;
            flag = 1;
            if (s[i] == '-')
                flag = -1;
            continue;
        }
        if (s[i] != ' ')
            return 0;
        if (flag != 0)
            return 0;
    }
    if (flag != 0)
        ans *= flag;
    min *= -1;
    //printf("ans%d,max %d, min %d", ans,max,min);
    ans = ans > max ? max : ans;
    ans = ans < min ? min : ans;
    return (int)ans;
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
int maxArea(vector<int>& height)
{
    int left = 0, right = (int)height.size() - 1;
    int area = 0;
    int cur;
    while (left < right) {
        cur = (right - left) * min(height[left], height[right]);
        area = area > cur ? area : cur;
        if (height[left] > height[right])
            right--;
        else
            left++;
    }
    return area;
}

// 14. Longest Common Prefix
char* longestCommonPrefix(char** strs, int strsSize)
{
    int len = (int)strlen(strs[0]);
    for (int i = 1; i < strsSize; i++) {
        int j = 0;
        while (j < (int)strlen(strs[i]) && strs[i][j] == strs[0][j])
            j++;
        len = (int)fmin(len, j);
    }
    strs[0][len] = 0;
    return strs[0];
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

// 16. 3Sum Closest
int threeSumClosest(int* nums, int numsSize, int target)
{
    long long res = INT_MAX;
    qsort(nums, numsSize, sizeof(int), cmpfun);

    for (int i = 0; i < numsSize - 2; i++)
    {
        int l = i + 1, h = numsSize - 1;
        while (l < h) {
            long long sum = nums[i] + nums[l] + nums[h];
            if (fabs(target - sum) < fabs(target - res)) {
                res = sum;
            }
            else if (sum > target)
                h--;
            else
                l++;
        }
    }
    return (int)res;
}


// 17. Letter Combinations of a Phone Number
char lettermap[8][4] = {
    {'a','b','c', 0},
    {'d','e','f', 0},
    {'g','h','i', 0},
    {'j','k','l', 0},
    {'m','n','o', 0},
    {'p','q','r', 's'},
    {'t','u','v', 0},
    {'w','x','y', 'z'},
};
char lc_path[4] = { 0 };
void bt_letterComb(char* digits, int len, int pos, int* count, char** ans)
{
    if (pos == len)
    {
        ans[*count] = (char*)calloc(len + 1, sizeof(char));
        memcpy(ans[*count], lc_path, len * sizeof(char));
        (*count)++;
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        char letter = lettermap[digits[pos] - '2'][i];
        if (letter == 0)
            continue;
        lc_path[pos++] = letter;
        bt_letterComb(digits, len, pos, count, ans);
        pos--;
    }
}
char** letterCombinations(char* digits, int* returnSize)
{
    *returnSize = 0;
    int len = (int)strlen(digits);
    if (len == 0)
        return NULL;

    char** ans = (char**)malloc(sizeof(char*) * (int)pow(4, len));
    bt_letterComb(digits, len, 0, returnSize, ans);
    return ans;
}

// 19. Remove Nth Node From End of List
struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    struct ListNode* dummy = (struct ListNode*)calloc(1, sizeof(struct ListNode));
    struct ListNode* fast = head, * slow = dummy, *temp;
    dummy->next = head;
    for (int i = 0; i < n; i++)
        fast = fast->next;
    while (fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    temp = slow->next;
    slow->next = temp->next;
    free(temp);
    head = dummy->next;
    free(dummy);
    return head;
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
    //int i, len = (int)strlen(s);
    //char* tempStack = (char*)malloc(len);
    //int top = -1;
    //if (len % 2 == 1)
    //    return false;
    //for (i = 0; i < len; i++) {
    //    tempStack[++top] = s[i];
    //    top = checkParent(tempStack, top);
    //}
    //if (top > 0) return false;
    //return true;
    int len = (int)strlen(s);
    int top = -1;
    char* stack = (char*)calloc(len, sizeof(char));
    for (int i = 0; i < len; i++) {
        if (s[i] == '(') stack[++top] = ')';
        else if (s[i] == '[') stack[++top] = ']';
        else if (s[i] == '{') stack[++top] = '}';
        else if (top == -1 || stack[top] != s[i])
            return false;
        else
            top--;
    }
    if (top >= 0)
        return false;
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

// 22. Generate Parentheses
char Parentpath[17] = { 0 };
int  Parentplen = 0;
void bpParent(int n, int left, int right, int* count, char** ans)
{
    if (left == 0 && right == 0)
    {
        ans[*count] = (char*)calloc(2 * n + 1, sizeof(char));
        memcpy(ans[(*count)++], Parentpath, 2 * n * sizeof(char));
        return;
    }
    if (left > 0)
    {
        Parentpath[Parentplen++] = '(';
        bpParent(n, left - 1, right, count, ans);
        Parentplen--;
    }
    if (right > 0 && right > left)
    {
        Parentpath[Parentplen++] = ')';
        bpParent(n, left, right - 1, count, ans);
        Parentplen--;
    }
}
char** generateParenthesis(int n, int* returnSize) {
    *returnSize = 0;
    Parentplen = 0;
    char** ans = (char**)malloc(10000 * sizeof(char*));

    bpParent(n, n, n, returnSize, ans);
    return ans;
}

// 24. Swap Nodes in Pairs
struct ListNode* swapPairs(struct ListNode* head)
{
    struct ListNode* Dummy, *prior, * nextnode;

    Dummy = (struct ListNode*)calloc(1, sizeof(struct ListNode));
    Dummy->next = head;
    prior = Dummy;
    while (prior->next != NULL && prior->next->next != NULL)
    {
        nextnode = prior->next->next;
        prior->next->next = nextnode->next;
        nextnode->next = prior->next;
        prior->next = nextnode;
        prior = nextnode->next;
    }

    head = Dummy->next;
    free(Dummy);
    return head;
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
vector<int> searchRange(vector<int>& nums, int target)
{
    vector<int> res(2, -1);
    int left = 0, right = (int)nums.size() - 1;
    int mid;
    if (right < 0)
        return res;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (nums[mid] == target)
            break;
        else if (nums[mid] > target)
            right = mid - 1;
        else
            left = mid + 1;
    }
    if (left > right)
        return res;

    left = mid - 1;
    while (left >= 0 && nums[left] == target)
        left--;
    right = mid + 1;
    while (right < (int)nums.size() && nums[right] == target)
        right++;
    res[0] = left + 1, res[1] = right - 1;

    return res;
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

// 39. Combination Sum
int cbpath[40] = { 0 };
int cbplen = 0;
void cbbacktrack(int* candidates, int start, int n, int target, int* count, int** col, int** ans)
{
    if (target == 0)
    {
        (*col)[*count] = cbplen;
        ans[*count] = (int*)malloc(cbplen * sizeof(int));
        memcpy(ans[(*count)++], cbpath, cbplen * sizeof(int));
        return;
    }
    for (int i = start; i < n; i++)
    {
        if (target < candidates[i])
            continue;
        cbpath[cbplen++] = candidates[i];
        cbbacktrack(candidates, i, n, target - candidates[i], count, col, ans);
        cbplen--;
    }
}
int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes)
{
    *returnColumnSizes = (int*)malloc(1000 * sizeof(int));
    int** ans = (int**)malloc(1000 * sizeof(int*));
    cbplen = 0;
    *returnSize = 0;
    cbbacktrack(candidates, 0, candidatesSize, target, returnSize, returnColumnSizes, ans);

    return ans;
}

// 40. Combination Sum II
int cbSum2Path[30];
int cbSum2Len;
int cbSum2Cmp(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}
void btcbSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes, int ** ans, int start, int sum)
{
    if (sum == target) {
        ans[*returnSize] = (int*)malloc(sizeof(int) * cbSum2Len);
        (*returnColumnSizes)[*returnSize] = cbSum2Len;
        memcpy(ans[*returnSize], cbSum2Path, cbSum2Len * sizeof(int));
        (*returnSize)++;
        /*for (int i = 0; i < cbSum2Len; i++)
            printf("%d ", cbSum2Path[i]);
        printf("\r\n");*/
        return;
    }

    for (int i = start; i < candidatesSize && sum + candidates[i] <= target; i++) {
        if (i > start && candidates[i] == candidates[i - 1] )
            continue;
        cbSum2Path[cbSum2Len++] = candidates[i];
        sum += candidates[i];
        //used[i] = true;

        btcbSum2(candidates, candidatesSize, target, returnSize, returnColumnSizes, ans, i+1, sum);
        sum -= candidates[i];
        //used[i] = false;
        cbSum2Len--;
    }
}
int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes)
{
    int** ans = (int**)malloc(sizeof(int*) * 1000);
    (*returnColumnSizes) = (int*)malloc(sizeof(int) * 1000);
    cbSum2Len = 0;
    *returnSize = 0;
    //bool* used = (bool*)calloc(candidatesSize, sizeof(bool));

    qsort(candidates, candidatesSize, sizeof(int), cbSum2Cmp);
    btcbSum2(candidates, candidatesSize,target, returnSize, returnColumnSizes, ans, 0, 0);

    //free(used);
    return ans;
}

// 43. Multiply Strings
char* multiply(char* num1, char* num2)
{
    if (num1[0] == '0' || num2[0] == '0')
        return (char*)"0";
    int len1 = (int)strlen(num1);
    int len2 = (int)strlen(num2);
    char* ans = (char*)calloc(len1 + len2 + 1, sizeof(char));
    for (int i = len1 - 1; i >= 0; i--) {
        for (int j = len2 - 1; j >= 0; j--) {
            char multi = (num1[i] - '0') * (num2[j] - '0');
            int pos = i + j + 1;
            ans[pos] += multi % 10;
            ans[pos - 1] += multi / 10;
            if (ans[pos] >= 10) {
                ans[pos - 1] += ans[pos] / 10;
                ans[pos] = ans[pos] % 10;
            }
        }
    }

    for (int i = 0; i < len1 + len2; i++) {
        ans[i] += '0';
    }
    if (ans[0] == '0') ans++;
    return ans;
}

// 45. Jump Game II
int jumpII(int* nums, int numsSize) {
    double curDis = 0, NextDis = 0;
    int ans = 0;
    if (numsSize <= 1)
        return ans;

    for (int i = 0; i < numsSize; i++) {
        NextDis = fmax(nums[i] + i, NextDis);
        if (i == curDis) {
            if (curDis >= numsSize - 1)
                return ans;
            ans++;
            curDis = NextDis;
        }
    }
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

// 47. Permutations II
int path47s[8] = { 0 };
int plen47s = 0;

void backtrack(int* nums, int n, int* count, int** colnum, int** ans, bool* visited)
{
    if (plen47s == n) {
        (*colnum)[*count] = n;
        ans[*count] = (int*)malloc(n * sizeof(int));
        memcpy(ans[(*count)++], path47s, n * sizeof(int));
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1])
            continue;
        if (!visited[i]) {
            visited[i] = true;
            path47s[plen47s++] = nums[i];
            backtrack(nums, n, count, colnum, ans, visited);
            plen47s--;
            visited[i] = false;
        }
    }
}
int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), cmpfun);
    *returnSize = 0;
    plen47s = 0;
    int count = 1;
    int i = 0;
    for (i = 1; i <= numsSize; i++)
        count *= i;
    *returnColumnSizes = (int*)malloc(count * sizeof(int));
    int** ans = (int**)malloc(count * sizeof(int*));
    bool* visited = (bool*)calloc(count, sizeof(bool));
    backtrack(nums, numsSize, returnSize, returnColumnSizes, ans, visited);
    free(visited);

    return ans;
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

// 54. Spiral Matrix
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize)
{
    int m = matrixSize, n = matrixColSize[0];
    int* ans = (int*)calloc(m * n, sizeof(int));
    *returnSize = m * n;
    int row, col;
    int rowB = 0, rowE = m - 1, colB = 0, colE = n - 1;
    int count = 0;
    int dir = 0;
    while (rowB <= rowE && colB <= colE) {
        switch (dir) {
        case 0:
            for (col = rowB; col <= colE; col++)
                ans[count++] = matrix[rowB][col];
            rowB++;
            break;
        case 1:
            for (row = rowB; row <= rowE; row++)
                ans[count++] = matrix[row][colE];
            colE--;
            break;
        case 2:
            for (col = colE; col >= colB; col--)
                ans[count++] = matrix[rowE][col];
            rowE--;
            break;
        case 3:
            for (row = rowE; row >= rowB; row--)
                ans[count++] = matrix[row][colB];
            colB++;
            break;
        }
        dir = (dir + 1) % 4;
    }
    return ans;
}

// 55. Jump Game
bool canJump(int* nums, int numsSize)
{
    int Cover = 0;
    if (numsSize == 1)
        return true;
    for (int i = 0; i <= Cover; i++)
    {
        Cover = (int)fmax(Cover, i + nums[i]);
        if (Cover >= (numsSize - 1))
            return true;
    }
    return false;
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

// 57. Insert Interval
int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, int newIntervalSize, int* returnSize, int** returnColumnSizes)
{
    int count = 0;
    int** ans = (int**)malloc((intervalsSize + 1) * sizeof(int*));
    *returnSize = 0;
    *returnColumnSizes = (int*)malloc((intervalsSize + 1) * sizeof(int));
    int i = 0;
    while (i < intervalsSize) {
        if (newInterval[1] < intervals[i][0])
        {
            ans[count] = (int*)malloc(2 * sizeof(int));
            (*returnColumnSizes)[count] = 2;
            memcpy(ans[count++], newInterval, 2 * sizeof(int));
            while (i < intervalsSize) {
                ans[count] = (int*)malloc(2 * sizeof(int));
                (*returnColumnSizes)[count] = 2;
                memcpy(ans[count++], intervals[i++], 2 * sizeof(int));
            }
            *returnSize = count;
            return ans;
        }
        else if (newInterval[0] > intervals[i][1]) {
            ans[count] = (int*)malloc(2 * sizeof(int));
            (*returnColumnSizes)[count] = 2;
            memcpy(ans[count++], intervals[i++], 2 * sizeof(int));
        }
        else {
            newInterval[0] = newInterval[0] < intervals[i][0] ? newInterval[0] : intervals[i][0];
            newInterval[1] = newInterval[1] > intervals[i][1] ? newInterval[1] : intervals[i][1];
            i++;
        }
    }

    ans[count] = (int*)malloc(2 * sizeof(int));
    (*returnColumnSizes)[count] = 2;
    memcpy(ans[count++], newInterval, 2 * sizeof(int));

    *returnSize = count;
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

// 72. Edit Distance
int minsolve(int i, int j, int m, int n, char* word1, char* word2, int** dp)
{
    if (i == m)
        return n - j;
    if (j == n)
        return m - i;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (word1[i] == word2[j])
        return dp[i][j] = minsolve(i + 1, j + 1, m, n, word1, word2, dp);
    else {
        int val = minsolve(i + 1, j, m, n, word1, word2, dp);
        val = (int)fmin(val, minsolve(i, j + 1, m, n, word1, word2, dp));
        val = (int)fmin(val, minsolve(i + 1, j + 1, m, n, word1, word2, dp));
        return val + 1;
    }
}

int minDistance(char* word1, char* word2) {
    int i = 0, j = 0;
    int m = (int)strlen(word1), n = (int)strlen(word2);
    int** dp = (int**)malloc(m * sizeof(int*));
    for (i = 0; i < m; i++) {
        dp[i] = (int*)malloc(n * sizeof(int));
        for (j = 0; j < n; j++)
            dp[i][j] = -1;
    }
    int ans = minsolve(0, 0, m, n, word1, word2, dp);
    for (i = 0; i < m; i++)
        free(dp[i]);
    free(dp);
    return ans;
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
void BTcombine(int begin, int n, int k, int* Path, int* len, int** result, int* cursor)
{
    if ((*len) == k)
    {
        memcpy(result[(*cursor)++], Path, sizeof(int) * k);
        return;
    }
    for (int i = begin; i <= n; i++) {
        Path[(*len)++] = i;
        BTcombine(i + 1, n, k, Path, len, result, cursor);
        (*len)--;
    }
}
int** combine(int n, int k, int* returnSize, int** returnColumnSizes)
{
    int i;
    int count = 1;
    int Path[20] = { 0 };
    int len = 0;
    int** ans;
    for (i = 1; i <= k; i++) {
        count = count * (n - i + 1) / i;
    }
    ans = (int**)malloc(sizeof(int*) * count);
    (*returnColumnSizes) = (int*)malloc(sizeof(int) * count);
    for (i = 0; i < count; i++) {
        ans[i] = (int*)malloc(sizeof(int) * k);
        (*returnColumnSizes)[i] = k;
    }
    *returnSize = count;

    count = 0;
    BTcombine(1, n, k, Path, &len, ans, &count);
    return ans;
}
//int** CombAns;
//int  CurComb;
//int* CombPath;
//int  CurPath;
//void CombBackTrack(int n, int k, int start)
//{
//    if (CurPath == k) {
//        CombAns[CurComb] = (int*)malloc(sizeof(int) * k);
//        memcpy(CombAns[CurComb++], CombPath, sizeof(int) * k);
//        return;
//    }
//    for (int i = start; i <= n - (k - CurPath) + 1; i++) {
//        CombPath[CurPath++] = i;
//        CombBackTrack(n, k, i + 1);
//        CurPath--;
//    }
//}
//int** combine(int n, int k, int* returnSize, int** returnColumnSizes)
//{
//    int i, j;
//    int nums = 1;
//    for (i = n, j = 1; j <= k; i--, j++) {
//        nums *= i;
//        nums /= j;
//    }
//
//    *returnSize = nums;
//    CombAns = (int**)malloc(sizeof(int*) * nums);
//    *returnColumnSizes = (int*)malloc(sizeof(int) * nums);
//    CombPath = (int*)malloc(sizeof(int) * k);
//    for (i = 0; i < nums; i++) {
//        (*returnColumnSizes)[i] = k;
//    }
//    CurComb = 0;
//    CurPath = 0;
//    CombBackTrack(n, k, 1);
//
//    free(CombPath);
//
//    return CombAns;
//}

// 78. Subsets
int subpath[10] = { 0 };
int subpathsize = 0;
void subsetbacktrack(int* nums, int numsSize, int start, int** ans, int** colsize, int* count)
{
    ans[*count] = (int*)malloc(sizeof(int*) * subpathsize);
    (*colsize)[*count] = subpathsize;
    memcpy(ans[*count], &subpath[0], sizeof(int) * subpathsize);
    (*count)++;
    if (start >= numsSize)
        return;

    for (int i = start; i < numsSize; i++) {

        subpath[subpathsize++] = nums[i];
        subsetbacktrack(nums, numsSize, i + 1, ans, colsize, count);
        subpathsize--;
    }
}
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    int count = (int)pow(2, numsSize);
    *returnSize = count;
    int** ans = (int**)malloc(sizeof(int*) * count);
    (*returnColumnSizes) = (int*)malloc(sizeof(int) * count);
    subpathsize = 0;
    count = 0;
    subsetbacktrack(nums, numsSize, 0, ans, returnColumnSizes, &count);

    return ans;
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

// 90. Subsets II
int subpath90[10] = { 0 };
int sublen = 0;
void backtrack(int* nums, int begin, int numsSize, int* count, int** colSize, int** ans, bool* used)
{
    (*colSize)[*count] = sublen;
    ans[*count] = (int*)malloc(sizeof(int) * sublen);
    memcpy(ans[*count], subpath90, sublen * sizeof(int));
    (*count)++;
    for (int i = begin; i < numsSize; i++)
    {
        if (i > 0 && nums[i - 1] == nums[i] && used[i - 1] == false)
        {
            continue;
        }
        subpath90[sublen++] = nums[i];
        used[i] = true;
        backtrack(nums, i + 1, numsSize, count, colSize, ans, used);
        used[i] = false;
        sublen--;
    }
}
int cmp47fun(const void* a, const void* b) {
    return (*(int*)a) - (*(int*)b);
}
int** subsetsWithDup(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int count = (int)pow(2, numsSize);
    bool* used = (bool*)calloc(numsSize, sizeof(bool));
    (*returnColumnSizes) = (int*)malloc(sizeof(int) * count);
    int** ans = (int**)malloc(count * sizeof(int*));
    *returnSize = 0;
    sublen = 0;

    qsort(nums, numsSize, sizeof(int), cmp47fun);

    backtrack(nums, 0, numsSize, returnSize, returnColumnSizes, ans, used);

    free(used);
    return ans;
}

// 91. Decode Ways
int numDecodings(char* s)
{
    int len = (int)strlen(s);
    int* dp = (int*)calloc(len + 1, sizeof(int));
    dp[len] = 1;
    for (int i = len - 1; i >= 0; i--) {
        if (s[i] == '0')
            dp[i] = 0;
        else {
            dp[i] = dp[i + 1];
            if (i < len - 1 && (s[i] == '1' || s[i] == '2' && s[i + 1] < '7'))
                dp[i] += dp[i + 2];
        }
    }
    int ans = len > 0 ? dp[0] : 0;
    free(dp);
    return ans;
}

// 92. Reverse Linked List II
/*
Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]
*/
ListNode* reverseBetween(ListNode* head, int left, int right)
{
    ListNode* dummy = (ListNode*)calloc(1, sizeof(ListNode));
    dummy->next = head;
    ListNode* cur= head, * pre= dummy, * temp = NULL;
    ListNode* first = NULL;
    int index = 1;
    while (cur)
    {
        if (index == left) {
            first = pre;
            pre = cur;
            cur = cur->next;
        }
        else if (index > left && index <= right) {
            temp = cur->next;
            cur->next = first->next;
            first->next = cur;
            cur = pre->next = temp;
        }
        else if (index > right)
        {
            break;
        }
        else
        {
            pre = cur;
            cur = cur->next;
        }
        index++;
    }
    return dummy->next;
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

// 100. Same Tree
bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
    if (!p && !q)
        return true;
    if ((!p && q) || (p && !q))
        return false;
    if (p->val != q->val)
        return false;
    if (!isSameTree(p->left, q->left))
        return false;
    if (!isSameTree(p->right, q->right))
        return false;
    return true;
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

/*
* Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]
*/
// 106. Construct Binary Tree from Inorder and Postorder Traversal
struct TreeNode* buildTree106(int* inorder, int inorderSize, int* postorder, int postorderSize)
{
    if (postorderSize <= 0)
        return NULL;

    struct TreeNode* root = (struct TreeNode*)calloc(sizeof(struct TreeNode), 1);
    int left, right, i;
    root->val = postorder[postorderSize-1];
    if (postorderSize == 1)
        return root;

    for (i = 0; i < inorderSize; i++) {
        if (inorder[i] == root->val)
        {
            left = i;
            right = inorderSize - i - 1;
            break;
        }
    }

    root->left = buildTree(&inorder[0], left, &postorder[0], left);
    root->right = buildTree(&inorder[i + 1], right, &postorder[i], right);
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

// 110. Balanced Binary Tree
int getHeight(struct TreeNode* root) {
    if (!root)
        return 0;
    int left = getHeight(root->left);
    if (left == -1)
        return -1;
    int right = getHeight(root->right);
    if (right == -1)
        return -1;
    if (fabs(left - right) > 1)
        return -1;
    return (int)fmax(left, right) + 1;
}
bool isBalanced(struct TreeNode* root) {
    if (getHeight(root) < 0)
        return false;
    return true;
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
    //bool bFind = false;
    //presum(root, targetSum, &bFind);
    //return bFind;

    if (!root)
        return false;
    if (!root->left && !root->right)
    {
        if (root->val == targetSum)
            return true;
        else
            return false;
    }
    if (root->left)

        if (root->left && hasPathSum(root->left, targetSum - root->val))
            return true;
    if (root->right && hasPathSum(root->right, targetSum - root->val))
        return true;
    return false;
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
// [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> res;
    vector<int> row;
    for (int i = 0; i < numRows; i++) {
        row.clear();
        row.resize(i+1);
        row[0] = 1;
        row[i] = 1;
        for (int j = 1; j < i; j++) {
            row[j] = res[i - 1][j - 1] + res[i - 1][j];
        }
        res.push_back(row);
    }

    return res;
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
vector<int> getRow(int rowIndex)
{
    vector<int> res(rowIndex+1, 1);
    int temp = 1;
    for (int i = 0; i <= rowIndex; i++) {
        res[i] = temp;
        temp = (temp * (rowIndex - i) / (i + 1));
    }
    return res;
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


// 130. Surrounded Regions
int regions[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
void regiondfs(char** board, bool** visited, int m, int n, int curx, int cury)
{
    visited[curx][cury] = true;
    for (int i = 0; i < 4; i++)
    {
        int nrow = curx + regions[i][0];
        int ncol = cury + regions[i][1];
        if (nrow >= 0 && ncol >= 0 && nrow < m && ncol < n && board[nrow][ncol] != 'X' && !visited[nrow][ncol])
            regiondfs(board, visited, m, n, nrow, ncol);
    }
}
void solve(char** board, int boardSize, int* boardColSize)
{
    int i, j;
    int m = boardSize;
    int n = boardColSize[0];
    bool** visited = (bool**)malloc(sizeof(bool*) * m);
    for (i = 0; i < m; i++)
        visited[i] = (bool*)calloc(n, sizeof(bool));

    //l & r
    for (i = 0; i < m; i++) {
        if (board[i][0] != 'X' && !visited[i][0]) {
            regiondfs(board, visited, m, n, i, 0);
        }
        if (board[i][n - 1] != 'X' && !visited[i][n - 1]) {
            regiondfs(board, visited, m, n, i, n - 1);
        }
    }
    //u & d
    for (j = 0; j < n; j++) {
        if (board[0][j] != 'X' && !visited[0][j]) {
            regiondfs(board, visited, m, n, 0, j);
        }
        if (board[m - 1][j] != 'X' && !visited[m - 1][j]) {
            regiondfs(board, visited, m, n, m - 1, j);
        }
    }

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (board[i][j] != 'X' && !visited[i][j])
                board[i][j] = 'X';
        }
    }
    for (i = 0; i < m; i++) {
        free(visited[i]);
    }
    free(visited);
}

// 131. Palindrome Partitioning
char** path;
int pathTop;
char*** ans;
int ansTop = 0;
int* ansSize;

//将path中的字符串全部复制到ans中
void copy() {
    //创建一个临时tempPath保存path中的字符串
    char** tempPath = (char**)malloc(sizeof(char*) * pathTop);
    int i;
    for (i = 0; i < pathTop; i++) {
        tempPath[i] = path[i];
    }
    //保存tempPath
    ans[ansTop] = tempPath;
    //将当前path的长度（pathTop）保存在ansSize中
    ansSize[ansTop++] = pathTop;
}

//判断字符串是否为回文字符串
bool isPalindrome(char* str, int startIndex, int endIndex) {
    //双指针法：当endIndex（右指针）的值比startIndex（左指针）大时进行遍历
    while (endIndex >= startIndex) {
        //若左指针和右指针指向元素不一样，返回False
        if (str[endIndex--] != str[startIndex++])
            return 0;
    }
    return 1;
}

//切割从startIndex到endIndex子字符串
char* cutString(char* str, int startIndex, int endIndex) {
    //开辟字符串的空间
    char* tempString = (char*)malloc(sizeof(char) * (endIndex - startIndex + 2));
    int i;
    int index = 0;
    //复制子字符串
    for (i = startIndex; i <= endIndex; i++)
        tempString[index++] = str[i];
    //用'\0'作为字符串结尾
    tempString[index] = '\0';
    return tempString;
}

void backTracking(char* str, int strLen, int startIndex) {
    if (startIndex >= strLen) {
        //将path拷贝到ans中
        copy();
        return;
    }

    int i;
    for (i = startIndex; i < strLen; i++) {
        //若从subString到i的子串是回文字符串，将其放入path中
        if (isPalindrome(str, startIndex, i)) {
            path[pathTop++] = cutString(str, startIndex, i);
        }
        //若从startIndex到i的子串不为回文字符串，跳过这一层 
        else {
            continue;
        }
        //递归判断下一层
        backTracking(str, strLen, i + 1);
        //回溯，将path中最后一位元素弹出
        pathTop--;
    }
}

char*** partition(char* s, int* returnSize, int** returnColumnSizes) {
    int strLen = (int)strlen(s);
    //因为path中的字符串最多为strLen个（即单个字符的回文字符串），所以开辟strLen个char*空间
    path = (char**)malloc(sizeof(char*) * strLen);
    //存放path中的数组结果
    ans = (char***)malloc(sizeof(char**) * 40000);
    //存放ans数组中每一个char**数组的长度
    ansSize = (int*)malloc(sizeof(int) * 40000);
    ansTop = pathTop = 0;

    //回溯函数
    backTracking(s, strLen, 0);

    //将ansTop设置为ans数组的长度
    *returnSize = ansTop;
    //设置ans数组中每一个数组的长度
    *returnColumnSizes = (int*)malloc(sizeof(int) * ansTop);
    int i;
    for (i = 0; i < ansTop; ++i) {
        (*returnColumnSizes)[i] = ansSize[i];
    }
    return ans;
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
        int index = (i + 1) % gasSize;
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

// 135. Candy
int candy(vector<int>& ratings)
{
    int i;
    int sum = 0;
    int count = (int)ratings.size();
    vector<int> vec(count, 1);

    for (i = 1; i < count; i++)
    {
        if (ratings[i] > ratings[i - 1])
            vec[i] = vec[i - 1] + 1;
    }

    for (i = count - 2; i >= 0; i--)
    {
        if (ratings[i] > ratings[i + 1])
            vec[i] = max(vec[i], vec[i + 1] + 1);
    }

    for (i = 0; i < count; i++)
        sum += vec[i];
    return sum;
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

// 137. Single Number II
int singlecmp(const void* a, const void* b)
{
    long pa = *(int*)a;
    long pb = *(int*)b;
    if (pa - pb < 0)
        return -1;
    return 1;
}
int singleNumberII(int* nums, int numsSize) {
    int ones = 0, twos = 0;
    for (int i = 0; i < numsSize; i++) {
        ones = (ones ^ nums[i]) & ~twos;
        twos = (twos ^ nums[i]) & ~ones;
    }
    return ones;

    int index = 0;
    if (numsSize == 1)
        return nums[0];
    qsort(nums, numsSize, sizeof(int), singlecmp);

    while (index < numsSize - 1) {
        if (nums[index] == nums[index + 1])
            index += 3;
        else
            break;
    }
    return nums[index];
}

// 138. Copy List with Random Pointer
RNode* copyRandomList(RNode* head)
{
    if (!head)
        return head;
    RNode* newhead = new RNode;
    RNode* newcur = newhead;
    RNode* cur = head;
    unordered_map<RNode*, RNode*> umap;

    while (cur) {
        RNode* temp = new RNode;
        temp->val = cur->val;

        umap.insert({ cur, temp });

        newcur->next = temp;
        newcur = newcur->next;
        cur = cur->next;
    }
    cur = head;
    newcur = newhead->next;

    while (cur) {
        RNode* random = cur->random;
        RNode* newNode = umap[random];
        newcur->random = newNode;

        newcur = newcur->next;
        cur = cur->next;
    }

    return newhead->next;
}


// 139. Word Break
bool wordBreak(string s, vector<string>& wordDict)
{
    if (wordDict.size() == 0) return false;

    vector<bool> dp(s.size() + 1, false);
    dp[0] = true;

    for (int i = 1; i <= s.size(); i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (dp[j])
            {
                string word = s.substr(j, i - j);
                if (find(wordDict.begin(), wordDict.end(), word) != wordDict.end())
                    //if(wordDict.find(word)!= wordDict.end())
                {
                    dp[i] = true;
                    break; //next i
                }
            }
        }
    }

    return dp[s.size()];
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
    struct ListNode* fast, * slow;
    fast = slow = head;
    while (fast!= NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
        {
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

// 148. Sort List
struct ListNode* mergeListNode(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode* dummy = (struct ListNode*)calloc(1, sizeof(struct ListNode));
    struct ListNode* cur = dummy;
    while (l1 && l2) {
        if (l1->val <= l2->val) {
            cur->next = l1;
            l1 = l1->next;
        }
        else {
            cur->next = l2;
            l2 = l2->next;
        }
        cur = cur->next;
    }
    if (l1)
        cur->next = l1;
    if (l2)
        cur->next = l2;
    cur = dummy->next;
    free(dummy);
    return cur;
}
struct ListNode* sortList(struct ListNode* head)
{
    // one point
    if (!head || !head->next)
        return head;

    ListNode* temp = NULL;
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast && fast->next) {
        temp = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    temp->next = NULL;
    temp = sortList(head);
    fast = sortList(slow);
    return mergeListNode(temp, fast);
}

// 149. Max Points on a Line
int maxPoints(int** points, int pointsSize, int* pointsColSize)
{
    int ans = 0;
    if (pointsSize <= 2)
        return pointsSize;

    for (int i = 0; i < pointsSize; i++)
        for (int j = i + 1; j < pointsSize; j++) {
            int x1 = points[i][0], x2 = points[j][0];
            int y1 = points[i][1], y2 = points[j][1];
            int total = 2;
            for (int k = 0; k < pointsSize && k != i && k != j; k++) {
                int x = points[k][0], y = points[k][1];
                if ((y2 - y1) * (x - x1) == (x2 - x1) * (y - y1))
                    total++;
            }
            ans = ans < total ? total : ans;
        }
    return ans;
}

// 150. Evaluate Reverse Polish Notation
int evalRPN(char** tokens, int tokensSize) {
    long result = 0;
    long* stack = (long*)malloc(tokensSize * sizeof(long));
    int top = -1;
    for (int i = 0; i < tokensSize; i++)
    {
        if ((strlen(tokens[i]) == 1) && (tokens[i][0] == '+' || tokens[i][0] == '-' || tokens[i][0] == '*' || tokens[i][0] == '/'))
        {
            long num1, num2;
            num2 = stack[top--];
            num1 = stack[top--];
            switch (tokens[i][0]) {
            case '+':
                stack[++top] = num1 + num2;
                break;
            case '-':
                stack[++top] = num1 - num2;
                break;
            case '*':
                stack[++top] = num1 * num2;
                break;
            case '/':
                stack[++top] = num1 / num2;
                break;
            }
        }
        else
        {
            stack[++top] = atoi(tokens[i]);
        }
    }

    result = stack[top];
    free(stack);
    return result;
}

// 151. Reverse Words in a String
void removespace(char* s)
{
    int slow = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] != ' ') {
            if (slow != 0) s[slow++] = ' ';
            while (i < strlen(s) && s[i] != ' ')
                s[slow++] = s[i++];
        }
    }
    s[slow] = '\0';
}
void reverse(char* s, int len)
{
    for (int i = 0; i < len / 2; i++) {
        s[i] ^= s[len - 1 - i];
        s[len - 1 - i] ^= s[i];
        s[i] ^= s[len - 1 - i];
    }
}
char* reverseWords(char* s) {
    removespace(s);
    if (strlen(s) == 0)
        return NULL;

    int len = (int)strlen(s), left = 0;
    reverse(s, len);
    for (int i = 0; i <= len; i++) {
        if (i == len || s[i] == ' ') {
            reverse(&s[left], i - left);
            left = i + 1;
        }
    }

    return s;
}
#if 0
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
#endif

// 152. Maximum Product Subarray
int maxProduct(int* nums, int numsSize)
{
    int curmax = nums[0];
    int curmin = nums[0];
    int curpro = nums[0];
    for (int i = 1; i < numsSize; i++) {
        int temp = curmax;
        curmax = (int)(fmax(fmax(curmin * nums[i], curmax * nums[i]), nums[i]));
        curmin = (int)(fmin(fmin(curmin * nums[i], temp * nums[i]), nums[i]));
        curpro = (int)(fmax(curmax, curpro));
        //printf("%d: %d %d %d\r\n", i, curmax,curmin,curpro);
    }
    return curpro;
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
    int val[MAXNUM];
    int min[MAXNUM];
    int top;
    int curmin;
} MinStack;
MinStack* minStackCreate() {
    MinStack* obj = (MinStack*)malloc(sizeof(MinStack));
    obj->top = -1;
    obj->curmin = INT_MAX;
    return obj;
}
void minStackPush(MinStack* obj, int val) {
    obj->val[++obj->top] = val;
    obj->curmin = obj->curmin > val ? val : obj->curmin;
    obj->min[obj->top] = obj->curmin;
}
void minStackPop(MinStack* obj) {
    if (obj->val[obj->top] == obj->curmin) {
        if (obj->top == 0)
            obj->curmin = INT_MAX;
        else
            obj->curmin = obj->min[obj->top - 1];
    }
    obj->top--;
}
int minStackTop(MinStack* obj) {
    return obj->val[obj->top];
}
int minStackGetMin(MinStack* obj) {
    return obj->curmin;
}
void minStackFree(MinStack* obj) {
    free(obj);
}
//typedef struct {
//    int minstack[MAXNUM];
//    int top;
//    int minval;
//} MinStack;
//MinStack* minStackCreate() {
//    MinStack* obj = (MinStack*)calloc(sizeof(MinStack), 1);
//    obj->top = -1;
//    obj->minval = INT_MAX;
//    return obj;
//}
//void minStackPush(MinStack* obj, int val) {
//    if (obj->top < MAXNUM) {
//        obj->minstack[++(obj->top)] = val;
//        if (obj->minval > val)
//            obj->minval = val;
//    }
//}
//void minStackPop(MinStack* obj) {
//    if (obj->top < 0)
//        return;
//    if (obj->minval == obj->minstack[obj->top])
//    {
//        obj->minval = INT_MAX;
//        for (int i = 0; i < obj->top; i++) {
//            if (obj->minval > obj->minstack[i])
//                obj->minval = obj->minstack[i];
//        }
//    }
//    obj->top--;
//}
//int minStackTop(MinStack* obj) {
//    if (obj->top < 0 || obj->top >= MAXNUM)
//        return -1;
//    return obj->minstack[obj->top];
//}
//int minStackGetMin(MinStack* obj) {
//    return obj->minval;
//}
//void minStackFree(MinStack* obj) {
//    obj->top = -1;
//    obj->minval = INT_MAX;
//}

// 160. Intersection of Two Linked Lists
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB)
{
    int lenA = 0, lenB = 0, gap = 0;
    struct ListNode* curA, *curB;
    curA = headA;
    while (curA)
    {
        lenA++;
        curA = curA->next;
    }
    curB = headB;
    while (curB)
    {
        lenB++;
        curB = curB->next;
    }

    if (lenA > lenB)
    {
        gap = lenA - lenB;
        curA = headA;
        curB = headB;
    }
    else
    {
        gap = lenB - lenA;
        curA = headB;
        curB = headA;
    }
    while (gap)
    {
        gap--;
        curA = curA->next;
    }
    while (curA && curB)
    {
        if (curA == curB)
            return curA;
        curA = curA->next;
        curB = curB->next;
    }
    return NULL;
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

// 199. Binary Tree Right Side View
int* rightSideView(struct TreeNode* root, int* returnSize)
{
    *returnSize = 0;
    if (!root)
        return NULL;
    struct TreeNode* treeque[100] = { 0 };
    struct TreeNode* temp = NULL;
    int head = 0, tail = 0, count = 0;
    int* ans = (int*)malloc(100 * sizeof(int));
    treeque[tail++] = root;
    while (tail > head) {
        int len = tail - head;
        for (int i = 0; i < len; i++) {
            temp = treeque[head++];
            if (temp->left)
                treeque[tail++] = temp->left;
            if (temp->right)
                treeque[tail++] = temp->right;
        }
        ans[count++] = temp->val;
    }
    (*returnSize) = count;
    return ans;
}
vector<int> rightSideView(TreeNode* root)
{
    vector<int> res;
    queue<TreeNode*> qu;
    if (root)
        qu.push(root);
    while (!qu.empty()) {
        int size = (int)qu.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode* node = qu.front();
            qu.pop();
            if (node->left)
                qu.push(node->left);
            if (node->right)
                qu.push(node->right);
            if (i == (size - 1))
                res.push_back(node->val);
        }
    }
    return res;
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

// 201. Bitwise AND of Numbers Range
int rangeBitwiseAnd(int left, int right)
{
    int count = 0;

    while (left != right) {
        left >>= 1;
        right >>= 1;
        count++;
    }
    return left << count;
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

// 208. Implement Trie(Prefix Tree)
typedef struct TrieNode {
    bool isComplete;
    struct TrieNode* children[26];
}TIRENODE;
typedef struct {
    TIRENODE* root;
} Trie;
Trie* trieCreate() {
    Trie* obj = (Trie*)malloc(sizeof(Trie));
    obj->root = (TIRENODE*)calloc(1, sizeof(TIRENODE));
    return obj;
}
void trieInsert(Trie* obj, char* word) {
    TIRENODE* node = obj->root;
    for (size_t i = 0; i < strlen(word); i++) {
        int index = word[i] - 'a';
        if (!node->children[index])
            node->children[index] = (TIRENODE*)calloc(1, sizeof(TIRENODE));
        node = node->children[index];
    }
    node->isComplete = true;
}
bool trieSearch(Trie* obj, char* word) {
    TIRENODE* node = obj->root;
    for (size_t i = 0; i < strlen(word); i++) {
        int index = word[i] - 'a';
        if (!node->children[index])
            return false;
        node = node->children[index];
    }
    return node->isComplete;
}
bool trieStartsWith(Trie* obj, char* prefix) {
    TIRENODE* node = obj->root;
    for (size_t i = 0; i < strlen(prefix); i++) {
        int index = prefix[i] - 'a';
        if (!node->children[index])
            return false;
        node = node->children[index];
    }
    return true;
}
void trieFree(Trie* obj) {
    free(obj);
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

// 210. Course Schedule II
int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize)
{
    return NULL;
    /*int i, j;
    int V = numCourses;
    int** adj = (int**)malloc(V * sizeof(int*));
    int* topo = (int*)calloc(V, sizeof(int));
    int* indegree = (int*)calloc(V, sizeof(int));

    for (i = 0; i < V; i++)
        adj[i] = (int*)calloc(V, sizeof(int));
    for (i = 0; i < prerequisitesSize; i++)
        adj[prerequisites[i][1]][prerequisites[i][0]] = 1;
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++) {
            if(adj[i][j])
        }*/

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

// 213. House Robber II
int rob1(int* nums, int count)
{
    if (count == 1)
        return nums[0];
    int* dp = (int*)calloc(count, sizeof(int));
    dp[0] = nums[0];
    dp[1] = (int)fmax(nums[0],nums[1]);
    for (int i = 2; i < count; i++)
        dp[i] = (int)fmax(dp[i - 2] + nums[i], dp[i - 1]);
    int result = dp[count - 1];
    free(dp);
    return result;
}
int rob2(int* nums, int numsSize) {
    if (numsSize == 1)
        return nums[0];
    int result1 = rob1(&nums[0], numsSize - 1);
    int result2 = rob1(&nums[1], numsSize - 1);
    return (int)fmax(result1, result2);
}

int robRange(vector<int>& nums, int start, int end) {
    if (end == start) return nums[start];
    vector<int> dp(nums.size());
    dp[start] = nums[start];
    dp[start + 1] = max(nums[start], nums[start + 1]);
    for (int i = start + 2; i <= end; i++) {
        dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
    }
    return dp[end];
}
int robCCC(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    if (nums.size() == 1) return nums[0];
    int result1 = robRange(nums, 0, (int)nums.size() - 2); // 情况二
    int result2 = robRange(nums, 1, (int)nums.size() - 1); // 情况三
    return max(result1, result2);
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

// 216. Combination Sum III
int cbSumPath[9] = { 0 };
int cbSumLen = 0;
bool btcbSum3(int begin, int sum, int k, int n, int** ans, int *returnSize, int **returnColumnSizes)
{
    bool bfind = false;
    if (k == 0)
    {
        if (sum == n) {
            //cbSumPath[cbSumLen] = n;
            ans[*returnSize] = (int*)malloc(sizeof(int) * cbSumLen);
            (*returnColumnSizes)[*returnSize] = cbSumLen;
            memcpy(ans[*returnSize], &cbSumPath[0], sizeof(int) * cbSumLen);
            (*returnSize)++;
            for (int i = 0; i < cbSumLen; i++)
                printf("%d ", cbSumPath[i]);
            printf("\r\n");
            return true;
        }
        if (sum > n)
            return false;
        return true;
    }

    for (int i = begin; i <= 9; i++) {
        if (n - sum < i)
            continue;
        cbSumPath[cbSumLen++] = i;
        sum += i;
        bfind = btcbSum3(i + 1, sum, k - 1, n, ans, returnSize, returnColumnSizes);
        sum -= i;
        cbSumLen--;
        if(!bfind)
            break;
    }
    return true;
}
int** combinationSum3(int k, int n, int* returnSize, int** returnColumnSizes)
{
    int sum = 0;
    int** ans = (int**)malloc(sizeof(int*) * 100);
    (*returnColumnSizes) = (int*)malloc(sizeof(int) * 100);
    *returnSize = 0;

    if (n > 45 || k > n)
        return ans;

    cbSumLen = 0;
    btcbSum3(1, sum, k, n, ans, returnSize, returnColumnSizes);

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

// 227. Basic Calculator II
void calcuvalue(int* numstack, int *topnum, char* operstack, int *topoper, bool one)
{
    while ((*topoper) > 0)
    {
        int num2 = numstack[--(*topnum)];
        int num1 = numstack[--(*topnum)];
        char ch = operstack[--(*topoper)];

        int res = 0;
        switch (ch)
        {
        case '+':
            res = num1 + num2;
            break;
        case '-':
            res =  num1 - num2;
            break;
        case '*':
            res =  num1 * num2;
            break;
        case '/':
            res =  num1 / num2;
            break;
        }
        numstack[(*topnum)++] = res;
        if (one)
            return;
    }
    return;
}
int calculate(char* s)
{
    int len = (int)strlen(s);
    int* numstack = (int*)calloc((len+1)/2, sizeof(int));
    char* operstack = (char*)calloc((len+1)/2, sizeof(char));
    int topnum = 0, topoper = 0;
    int ans;
    int num;
    char digits[12] = { 0 };
    int pos = 0;
    
    for (int i = 0; i < len; i++) {
        if (s[i] >= '0' && s[i] <= '9')
        {
            digits[pos++] = s[i];
            continue;
        }
        else if (pos > 0) {
            digits[pos] = '\0';
            num = atoi(digits);
            numstack[topnum++] = atoi(digits);
            pos = 0;
        }
        switch (s[i]) {
        case '+':
        case '-':
            calcuvalue(numstack, &topnum, operstack, &topoper, false);
            operstack[topoper++] = s[i];
            break;
        case '*':
        case '/':
            if (topoper > 0 && (operstack[topoper-1] == '*' || operstack[topoper-1] == '/'))
            {
                calcuvalue(numstack, &topnum, operstack, &topoper, true);
            }
            operstack[topoper++] = s[i];
            break;
        case ' ':
            break;
        default:
            break;
        }
    }
    if (pos > 0) {
        digits[pos] = '\0';
        num = atoi(digits);
        numstack[topnum++] = atoi(digits);
    }
    calcuvalue(numstack, &topnum, operstack, &topoper, false);
    ans = numstack[0];

    free(numstack);
    free(operstack);
    return ans;
}

// 229. Majority Element II
int majorityCmp(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}
int* majorityElement(int* nums, int numsSize, int* returnSize)
{
    int maxcount = (int)floor(numsSize / 3.0);
    int freq = 1;
    *returnSize = 0;
    int* res = (int*)malloc(numsSize * sizeof(int));

    qsort(nums, numsSize, sizeof(int), majorityCmp);
    int prior = nums[0];
    for (int i = 1; i <= numsSize; i++) {
        if (i < numsSize && nums[i] == prior) {
            freq++;
        }
        else
        {
            if (freq > maxcount) {
                res[(*returnSize)++] = prior;
            }
            if (i < numsSize) {
                prior = nums[i];
                freq = 1;
            }
        }
    }

    return res;
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

// 234. Palindrome Linked List
bool isPalindrome(struct ListNode* head)
{
    int count = 0;
    int* nodeval = (int*)malloc(100000*sizeof(int));
    while (head)
    {
        nodeval[count++] = head->val;
        head = head->next;
    }
    for (int i = 0; i < count / 2; i++)
    {
        if (nodeval[i] != nodeval[count - 1 - i])
        {
            free(nodeval);
            return false;
        }
    }
    free(nodeval);
    return true;
}

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

// 239. Sliding Window Maximum
#define INVALIDVAL -10001
int front239 = 0;
int queuelen = 0;
void queuepush(int* queue, int val)
{
    while (queuelen > 0 && val > queue[front239+queuelen-1])
        queuelen--;
    queue[front239 + queuelen++] = val;
}
void queuepop(int* queue, int val)
{
    if (queuelen >= 0 && val == queue[front239])
    {
        front239++;
        queuelen--;
    }
}
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    int i = 0, j = 0;

    *returnSize = numsSize - k + 1;
    if (k == 1)
        return nums;
    int* queue = (int*)malloc(sizeof(int) * numsSize);
    front239 = 0;
    queuelen = 0;
    int* result = (int*)calloc(*returnSize, sizeof(int));
    for (i = 0; i < k; i++) {
        queuepush(queue, nums[i]);
    }

    result[j++] = queue[front239];
    for (i = k; i < numsSize; i++) {
        queuepop(queue, nums[i - k]);
        queuepush(queue, nums[i]);
        result[j++] = queue[front239];
    }
    free(queue);
    return result;
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

// 257. Binary Tree Paths
int  BTpath[100] = { 0 };
int  BTpathlen = 0;
void printPath(char** path)
{
    char buffer[5] = { 0 };
    char res[500] = { 0 };
    char* pCur = &res[0];
    size_t len = 0, i;
    for (i = 0; i < BTpathlen - 1; i++) {
        //itoa(BTpath[i], buffer, DECIMAL);
        snprintf(buffer, 5, "%d", BTpath[i]);
        len = strlen(buffer);
        memcpy(pCur, buffer, len);
        pCur += len;
        memcpy(pCur, "->", 2);
        pCur += 2;
    }
    snprintf(buffer, 5, "%d", BTpath[i]);
    len = strlen(buffer);
    memcpy(pCur, buffer, len);
    pCur += len;
    len = strlen(res);
    *path = (char*)calloc(len+1, sizeof(char));
    memcpy(*path, res, len);
}
void travelBTPath(struct TreeNode* root, char** result, int* count)
{
    if (!root)
        return;
    if (!root->left && !root->right) { //leaf
        BTpath[BTpathlen++] = root->val;
        printPath(&result[(*count)++]);
        return;
    }

    BTpath[BTpathlen++] = root->val;
    if (root->left) {
        travelBTPath(root->left, result, count);
        BTpathlen--;
    }
    if (root->right) {
        travelBTPath(root->right, result, count);
        BTpathlen--;
    }
}
char** binaryTreePaths(struct TreeNode* root, int* returnSize)
{
    *returnSize = 0;
    char** result = (char**)malloc(64 * sizeof(char*));
    memset(BTpath, 0, sizeof(int) * 100);
    BTpathlen = 0;

    travelBTPath(root, result, returnSize);
    return result;
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

// 268. Missing Number
int missingNumber(int* nums, int numsSize)
{
    long long sum = 0;
    sum = (numsSize + 1) * numsSize / 2;
    for (int i = 0; i < numsSize; i++)
        sum -= nums[i];
    return (int)sum;
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

// 287. Find the Duplicate Number
int findDuplicate(vector<int>& nums)
{
    sort(nums.begin(), nums.end());

    for (size_t i = 1; i < nums.size(); i++) {
        if (nums[i] == nums[i - 1])
            return nums[i];
    }
    return 0;
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

// 300. Longest Increasing Subsequence
int dpLIS(int* nums, int count, int** dp, int i, int prev)
{
    if (i >= count)
        return 0;
    if (dp[i][prev + 1] != -1)
        return dp[i][prev + 1];
    int take = 0;
    int dontTake = dpLIS(nums, count, dp, i + 1, prev);
    if (prev == -1 || nums[i] > nums[prev])
        take = 1 + dpLIS(nums, count, dp, i + 1, i);
    return dp[i][prev + 1] =(int)fmax(take, dontTake);
}
int lengthOfLIS(int* nums, int numsSize)
{
    int i = 0;
    int** dp = (int**)malloc(numsSize * sizeof(int*));
    for (i = 0; i < numsSize; i++) {
        dp[i] = (int*)calloc((numsSize + 1), sizeof(int));
        for (int j = 0; j <= numsSize; j++)
            dp[i][j] = -1;
    }
    return dpLIS(nums, numsSize, dp, 0, -1);
}

// 316. Remove Duplicate Letters
char* removeDuplicateLetters(char* s)
{
    char stack[26] = { 0 };
    int seen[26];
    int lastpos[26];
    int top = -1;
    int index, i;
    memset(seen, -1, 26*sizeof(int));
    memset(lastpos, -1, 26*sizeof(int));

    for (i = 0; i < strlen(s); i++) {
        lastpos[s[i] - 'a'] = i;
    }

    for (i = 0; i < strlen(s); i++) {
        index = s[i] - 'a';
        if (seen[index] == -1) {
            while (top != -1 && s[i] < stack[top] && i < lastpos[stack[top] - 'a']){
                seen[stack[top--]-'a'] = -1;
            }   
            seen[index] = i;
            stack[++top] = s[i];
        }
    }
    char* res = (char*)calloc(top + 2, sizeof(char));
    memcpy(res, stack, top + 1);
    return res;
}

// 322. Coin Change
int coinChange(int* coins, int coinsSize, int amount) 
{
    int* dp = (int*)calloc(amount + 1, sizeof(int));
    qsort(coins, coinsSize, sizeof(int), cmpfun);

    for (int i = 1; i <= amount; i++) {
        dp[i] = INT_MAX;
        for (int j = 0; j < coinsSize; j++) {
            if (i - coins[j] < 0)
                break;
            if (dp[i - coins[j]] != INT_MAX)
                dp[i] = dp[i] < (1 + dp[i - coins[j]]) ? dp[i] : (1 + dp[i - coins[j]]);
        }
        printf("%d:%d\r\n", i, dp[i]);
    }
    return dp[amount] == INT_MAX ? -1 : dp[amount];
}
int coinChange(vector<int>& coins, int amount)
{
    // creating the base dp array, with first value set to 0
    int* dp = (int*)malloc(++amount * sizeof(int));
    dp[0] = 0;
    // more convenient to have the coins sorted
    sort(begin(coins), end(coins));
    // populating our dp array
    for (int i = 1; i < amount; i++) {
        // setting dp[0] base value to 1, 0 for all the rest
        dp[i] = INT_MAX;
        for (int c : coins) {
            if (i - c < 0) break;
            // if it was a previously not reached cell, we do not add use it
            if (dp[i - c] != INT_MAX) dp[i] = min(dp[i], 1 + dp[i - c]);
        }
    }
    return dp[--amount] == INT_MAX ? -1 : dp[amount];
}

// 328. Odd Even Linked List
struct ListNode* oddEvenList(struct ListNode* head)
{
    int count = 1;
    if (!head)
        return NULL;
    struct ListNode* dummy = (struct ListNode*)calloc(1, sizeof(struct ListNode));
    struct ListNode* prior = head;
    struct ListNode* evenhead = dummy;
    while (head->next) {
        if ((count++ % 2)) {
            evenhead->next = head->next;
            head->next = evenhead->next->next;
            evenhead = evenhead->next;
            evenhead->next = NULL;
        }
        else {
            //prior = head;
            head = head->next;
        }
    }
    head->next = dummy->next;
    free(dummy);
    return prior;
}

// Input: tickets = [["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]
// Output: ["JFK", "MUC", "LHR", "SFO", "SJC"]
// 332. Reconstruct Itinerary
bool ticketdfs(string from, int max, map<string, int>& mapLoc, vector<vector<int>>& matrix, vector<string>& res)
{
    map<string, int>::iterator it;
    int row = mapLoc[from];
    bool finish = false;
    for (it = mapLoc.begin(); it != mapLoc.end(); it++) {
        if (matrix[row][it->second] != 0)
        {
            finish = true;
            res.push_back(it->first);
            matrix[row][it->second] = 0;
            if (!ticketdfs(it->first, max, mapLoc, matrix, res))
            {
                finish = false;
                matrix[row][it->second] = 1;
                res.pop_back();
            }
        }
    }
    return finish;
}
vector<string> findItinerary(vector<vector<string>>& tickets)
{
    size_t i, j;
    int index = 0;
    map<string,int> mapLoc;
    map<string, int>::iterator it;
    vector<string> res;
    vector<vector<int>> matrix(300, vector<int>(300, 0));
    for (i = 0; i < tickets.size(); i++) {
        for (j = 0; j < 2; j++) {
            if (mapLoc.count(tickets[i][j]) <= 0)
                mapLoc[tickets[i][j]] = 0;
        }
    }
    for (it = mapLoc.begin(); it != mapLoc.end(); it++)
        it->second = index++;

    for (i = 0; i < tickets.size(); i++) {
        matrix[mapLoc[tickets[i][0]]][mapLoc[tickets[i][1]]] = 1;
    }

    res.push_back("JFK");
    ticketdfs("JFK", index, mapLoc, matrix, res);
    return res;
}

// 334. Increasing Triplet Subsequence
bool increasingTriplet(int* nums, int numsSize)
{
    int left = INT_MAX, mid = INT_MAX;
    if (numsSize < 3)
        return false;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > mid)
            return true;
        if (nums[i] < left)
            left = nums[i];
        if (nums[i] > left && nums[i] < mid)
            mid = nums[i];
    }
    return false;
#if 0
    bool* judge = (bool*)calloc(numsSize, sizeof(bool));
    int i = 0;
    int temp = nums[0];
    if (numsSize < 3)
        return false;
    for (i = 1; i < numsSize; i++) {
        if (nums[i] > nums[i - 1] || nums[i] > temp){
            judge[i] = true;
        }
        temp = nums[i] > temp ? temp : nums[i];
    }
    temp = nums[numsSize - 1];
    for (i = numsSize - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1] || nums[i] < temp)
        {
            if (judge[i])
                return true;
        }
        temp = nums[i] < temp ? temp : nums[i];
    }
#endif
    return false;
}

// 338. Counting Bits
int countBit(int n)
{
    int res = 0;
    while (n) {
        if (n & 1)
            res++;
        n >>= 1;
    }
    return res;
}
int* countBits(int n, int* returnSize)
{
    *returnSize = n + 1;
    int* res = (int*)malloc((n + 1) * sizeof(int));
    res[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 0)
            res[i] = res[i / 2];
        else
            res[i] = res[i / 2] + 1;
    }
    return res;
}

// 343. Integer Break
int integerBreak(int n)
{
    int* dp = (int*)calloc(n + 1, sizeof(int));
    dp[2] = 1;
    for (int i = 3; i <= n; i++) {
        for (int j = 1; j <= (i + 1) / 2; j++) {
            dp[i] = (int)fmax(dp[i], fmax((i - j) * j, dp[i - j] * j));
        }
    }
    int ans = dp[n];
    free(dp);
    return ans;
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
string reverseVowels(string s)
{
    int left = 0, right = (int)s.size() - 1;
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
struct tempMap {
    int value;
    int freq;
};
int mapcmp(const void* a, const void* b)
{
    struct tempMap* comp1 = (struct tempMap*)a;
    struct tempMap* comp2 = (struct tempMap*)b;
    return comp2->freq - comp1->freq;
}
int* topKFrequent(int* nums, int numsSize, int k, int* returnSize)
{
    *returnSize = k;
    struct tempMap* myMap = (struct tempMap*)calloc(20002, sizeof(struct tempMap));
    int* result = (int*)calloc(k, sizeof(int));
    int i = 0;
    for (i = 0; i < numsSize; i++) {
        myMap[nums[i] + 10000].value = nums[i] + 10000;
        myMap[nums[i] + 10000].freq++;
    }
    qsort(myMap, 20002, sizeof(struct tempMap), mapcmp);

    for (i = 0; i < k; i++)
        result[i] = myMap[i].value - 10000;
    free(myMap);
    return result;
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

// 384. Shuffle an Array
typedef struct {
    int* orignnums;
    int count;
} Solution;
Solution* solutionCreate(int* nums, int numsSize) {
    Solution* obj = (Solution*)calloc(1, sizeof(Solution));
    obj->orignnums = (int*)malloc(numsSize * sizeof(int));
    obj->count = numsSize;
    memcpy(obj->orignnums, nums, numsSize * sizeof(int));
    return obj;
}
int* solutionReset(Solution* obj, int* retSize) {
    *retSize = obj->count;
    return obj->orignnums;
}
int* solutionShuffle(Solution* obj, int* retSize) {
    *retSize = obj->count;
    int* ans = (int*)malloc(obj->count * sizeof(int));
    memcpy(ans, obj->orignnums, obj->count * sizeof(int));
    for (int i = obj->count - 1; i >= 0; i--) {
        int r = rand() % (i + 1);
        if (r == i)
            continue;
        ans[r] ^= ans[i];
        ans[i] ^= ans[r];
        ans[r] ^= ans[i];
    }

    return ans;
}
void solutionFree(Solution* obj) {
    free(obj->orignnums);
    obj->count = 0;
    free(obj);
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

// 389. Find the Difference
char findTheDifference(char* s, char* t)
{
    size_t len = strlen(s), i = 0;
    int sfreq[26] = { 0 }, tfreq[26] = { 0 };

    for (i = 0; i < len; i++){
        sfreq[s[i] - 'a']++;
        tfreq[t[i] - 'a']++;
    }
    tfreq[t[len] - 'a']++;
    
    for (i = 0; i < 26; i++) {
        if (sfreq[i] < tfreq[i])
            return (char)(i + 'a');
    }
    return '\0';
}

// 392. Is Subsequence
bool isSubsequence(char* s, char* t)
{
#if 0
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
#else
    size_t i, j;
    size_t slen = strlen(s);
    size_t tlen = strlen(t);
    if (tlen < slen)
        return false;
    if (slen == 0)
        return true;
    j = 0;
    for (i = 0; i < tlen; i++) {
        if (t[i] == s[j]) {
            j++;
            if (s[j] == '\0')
                return true;
        }
    }
    return false;
#endif
}
bool isSubsequence(string s, string t)
{
    int i = 0, j = 0;
    int slen = (int)s.length(), tlen = (int)t.length();
    if (slen == 0)
        return true;
    if (slen > tlen)
        return false;
    for (i = 0; i < tlen; i++) {
        if (s[j] == t[i]) {
            j++;
            if (s[j] == '\0')
                return true;
        }
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
string decodeString(string s)
{
    stack<char> st;
    for (size_t i = 0; i < s.size(); i++) {
        if (s[i] != ']')
        {
            st.push(s[i]);
            continue;
        }
        string curstr = "";
        while (st.top() != '[') {
            curstr = st.top() + curstr;
            st.pop();
        }
        st.pop(); // '['
        
        string numstr = "";
        while (!st.empty() && isdigit(st.top())) {
            numstr = st.top() + numstr;
            st.pop();
        }
        int num = stoi(numstr);
        while (num--) {
            for (int p = 0; p < curstr.size(); p++) {
                st.push(curstr[p]);
            }
        }
    }
    string res = "";
    while (!st.empty()) {
        res = st.top() + res;
        st.pop();
    }
    return res;
}

// 401. Binary Watch
int calBitCount(int n) {
    int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}
char** readBinaryWatch(int turnedOn, int* returnSize) {
    int i, j;
    char buffer[6] = { 0 };
    *returnSize = 0;
    char** result = (char**)malloc(720 * sizeof(char*));
    for (i = 0; i < 12; i++)
        for (j = 0; j < 60; j++) {
            if (calBitCount(i) + calBitCount(j) != turnedOn)
                continue;
            snprintf(buffer, 6, "%d:%02d", i, j);
            result[*returnSize] = (char*)calloc(strlen(buffer) + 1, sizeof(char));
            memcpy(result[(*returnSize)++], buffer, strlen(buffer));
        }

    return result;
}

// 404. Sum of Left Leaves
int sumOfLeftLeaves(struct TreeNode* root)
{
    int leftval, rightval;
    if (!root)
        return 0;
    if (!root->left && !root->right)
        return 0;
    leftval = sumOfLeftLeaves(root->left);
    if (root->left && !root->left->left && !root->left->right)
        leftval = root->left->val;
    rightval = sumOfLeftLeaves(root->right);
    return leftval + rightval;
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

// 413. Arithmetic Slices
bool maxSlice(int* nums, int numsSize, int* l, int* r)
{
    int dis = nums[*l] - nums[*l - 1];
    if (dis != nums[*l + 1] - nums[*l])
        return false;

    while (*l > 0 && nums[*l] - nums[*l - 1] == dis)
        (*l)--;
    while (*r < numsSize - 1 && nums[*r + 1] - nums[*r] == dis)
        (*r)++;
    return true;
}
int numberOfArithmeticSlices(int* nums, int numsSize) {
    int ans = 0;
    int len = 0;
    int l, r;
    if (numsSize < 3)
        return 0;
    for (int i = 1; i < numsSize - 1; i++) {
        l = r = i;
        if (maxSlice(nums, numsSize, &l, &r))
        {
            len = r - l + 1 - 2;
            ans += (len + 1) * len / 2;
            i = r;
        }
    }
    return ans;
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


// 416. Partition Equal Subset Sum
bool canPartition(int* nums, int numsSize)
{
    if (numsSize < 2)
        return false;
    int sum = 0;
    int i, j;
    for (i = 0; i < numsSize; i++)
    {
        sum += nums[i];
    }
    if (sum % 2 == 1)
        return false;
    sum /= 2;

    bool** dp = (bool**)malloc((numsSize + 1) * sizeof(bool*));
    for (i = 0; i <= numsSize; i++) {
        dp[i] = (bool*)calloc(sum + 1, sizeof(bool));
        if (i != 0)
            dp[i][0] = true;
    }
    for (i = 1; i <= numsSize; i++) {
        for (j = 1; j <= sum; j++)
        {
            if (nums[i - 1] <= j)
                dp[i][j] = dp[i - 1][j - nums[i - 1]] || dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
            printf("%d ", dp[i][j]);
        }
        printf("\r\n");
    }
    bool ans = dp[numsSize][sum];
    for (i = 0; i <= numsSize; i++)
        free(dp[i]);
    free(dp);
    return ans;
}

// 417. Pacific Atlantic Water Flow
int fourneight[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
bool FlowOcean(int** heights, int row, int col, int x, int y, bool* visited, bool* pacific, bool* atlantic)
{
    visited[x*col+y] = true;
    if (x == 0 || y == 0)
        *pacific = true;
    if (x == row - 1 || y == col - 1)
        *atlantic = true;
    if (*pacific && *atlantic)
        return true;

    for (int i = 0; i < 4; i++) {
        int nx = x + fourneight[i][0];
        int ny = y + fourneight[i][1];
        if (nx < 0 || nx >= row || ny < 0 || ny >= col)
            continue;
        if (visited[nx*col+ny])
            continue;
        if (heights[nx][ny] <= heights[x][y])
        {
            if (FlowOcean(heights, row, col, nx, ny, visited, pacific, atlantic))
                return true;
        }
    }

    return false;
}
int** pacificAtlantic(int** heights, int heightsSize, int* heightsColSize, int* returnSize, int** returnColumnSizes)
{
    int row = heightsSize, col = heightsColSize[0];
    bool* visited = (bool*)malloc(row * col*sizeof(bool));
    int count = 0;
    (*returnColumnSizes) = (int*)malloc(row * col*sizeof(int));
    int** ans = (int**)malloc(row * col*sizeof(int*));
    int i, j;
    for(i=0;i<row;i++)
        for (j = 0; j < col; j++) 
        {
            //i = 4, j = 0;
            bool pacific = false, atlantic = false;
            memset(visited, false, row * col * sizeof(bool));
            if (FlowOcean(heights, row, col, i, j, visited, &pacific, &atlantic))
            {
                (*returnColumnSizes)[count] = 2;
                ans[count] = (int*)malloc(2 * sizeof(int));
                ans[count][0] = i;
                ans[count][1] = j;
                count++;
                printf("%d, %d;", i, j);
            }
        }
    free(visited);
    *returnSize = count;
    return ans;
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

// 437. Path Sum III
void solvePathSum(struct TreeNode* root, long long current, int* pathNum)
{
    if (!root)
        return;
    if (root->val == current)
        (*pathNum)++;
    solvePathSum(root->left, current - root->val, pathNum);
    solvePathSum(root->right, current - root->val, pathNum);
}
void pathSumDET(struct TreeNode* root, long long targetSum, int* pathNum)
{
    if (!root)
        return;
    solvePathSum(root, targetSum, pathNum);

    pathSumDET(root->left, targetSum, pathNum);
    pathSumDET(root->right, targetSum, pathNum);
}
int pathSumIII(struct TreeNode* root, int targetSum)
{
    int pathNum = 0;
    pathSumDET(root, targetSum, &pathNum);
    return pathNum;
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

// 443. String Compression
int compress(char* chars, int charsSize)
{
    int slow = 0,fast = 0;
    char cur = chars[0];
    int freq = 1;
    char strFreq[5] = { 0 };
    
    for(int fast = 1; fast <= charsSize; fast++) {
        if (fast < charsSize && chars[fast] == cur) {
            freq++;
            continue;
        }

        chars[slow++] = cur;

        if (freq > 1)
        {
            //_itoa(freq, strFreq, 10);
            sprintf(strFreq, "%d", freq);
            for (int j = 0; j < strlen(strFreq); j++)
                chars[slow++] = strFreq[j];
        }
        freq = 1;
        if(fast < charsSize)
            cur = chars[fast];
    }
    return slow;
}

// 450. Delete Node in a BST
struct TreeNode* deleteNode(struct TreeNode* root, int key)
{
    struct TreeNode* prenode;
    if (!root)
        return NULL;
    if (root->val == key) {
        if (!root->left && !root->right)
            return NULL;
        if (!root->left) {
            prenode = root->right;
        }
        else if (!root->right)
        {
            prenode = root->left;
        }
        else
        {
            prenode = root->right;
            while (prenode->left) {
                prenode = prenode->left;
            }
            prenode->left = root->left;
            prenode = root->right;
        }
        free(root);
        return prenode;
    }
    else if (root->val > key)
        root->left = deleteNode(root->left, key);
    else
        root->right = deleteNode(root->right, key);
    return root;
}

// 452. Minimum Number of Arrows to Burst Balloons
int arrowcmp(const void* a, const void* b)
{
    int* t1 = *(int**)a;
    int* t2 = *(int**)b;
    if (t1[0] == t2[0])
        return t1[1] > t2[1] ? 1 : (t1[1] == t2[1] ? 0 : -1);
    else
        return t1[0] > t2[0] ? 1 : -1;
}
int findMinArrowShots(int** points, int pointsSize, int* pointsColSize)
{
    qsort(points, pointsSize, sizeof(int *), arrowcmp);

    int lastpoint = points[0][1];
    int res = 1;
    for (int i = 0; i < pointsSize; i++) {
        if (points[i][0] > lastpoint) {
            res++;
            lastpoint = points[i][1];
        }
        else
            lastpoint = lastpoint > points[i][1] ? points[i][1] : lastpoint;
    }
    return res;
}

// 459. Repeated Substring Pattern
bool repeatedSubstringPattern(char* s)
{
    int len = (int)strlen(s);
    int i = 1;
    int x = 0;

    while (i <= len / 2) {
        x = 0;
        if (len % i == 0) {
            while (x < len) {
                if (s[x % i] != s[x])
                    break;
                x++;
            }
            if (x == len)
                return true;
        }
        i++;
    }
    return false;
}

// 477. Total Hamming Distance
int totalHammingDistance(int* nums, int numsSize) {
    int sum = 0;
    uint32_t comp = 1;
    for (int pos = 0; pos < 32; pos++) {
        int ones = 0, zeros = 0;
        for (int i = 0; i < numsSize; i++)
            if (nums[i] & comp)
                zeros++;
            else
                ones++;
        comp <<= 1;
        sum += zeros * ones;
    }
    return sum;
}

// 485. Max Consecutive Ones
int findMaxConsecutiveOnes(int* nums, int numsSize)
{
    int i = 0, j = 0;
    int ans = 0;
    while (j < numsSize) {
        if (nums[j] == 0) {
            ans = ans < (j - i) ? (j - i) : ans;
            i = j + 1;
        }
        j++;
    }
    ans = ans < (j - i) ? (j - i) : ans;
    return ans;
}

// 501. Find Mode in Binary Search Tree
struct TreeNode* Pre501 = NULL;
int max501 = 0;
int len501 = 0;
void traverse501(struct TreeNode* root, int* array, int* count)
{
    if (!root)
        return;
    traverse501(root->left, array, count);
    array[(*count)++] = root->val;
    traverse501(root->right, array, count);
}
void find501(struct TreeNode* root, int* result, int* count)
{
    if (!root)
        return;
    find501(root->left, result, count);
    if (Pre501 == NULL || Pre501->val != root->val) {
        *count = 1;
    }
    else if(Pre501->val == root->val) {
        (*count)++;
    }
    Pre501 = root;

    if (*count == max501) {
        result[len501++] = root->val;
    }
    else if (*count > max501) {
        max501 = *count;
        len501 = 0;
        result[len501++] = root->val;
    }

    //array[(*count)++] = root->val;

    find501(root->right, result, count);
}
int* findMode(struct TreeNode* root, int* returnSize)
{
    //int* array = (int*)malloc(10000 * sizeof(int));
    int* result = (int*)malloc(10000 * sizeof(int));
    int count = 0;
    Pre501 = NULL;
    max501 = 0;
    len501 = 0;
    find501(root, result, &count);
    *returnSize = len501;
#if 0
    int slow = 0, i = 0, maxfreq = 0;
    *returnSize = 0;
    for (int i = 0; i <= count; i++) {
        if (i == count || array[i] != array[slow]) {
            int freq = i - slow + 1;
            if (freq == maxfreq)
                result[(*returnSize)++] = array[slow];
            else if (freq > maxfreq) {
                maxfreq = freq;
                *returnSize = 0;
                result[(*returnSize)++] = array[slow];
            }
            freq = 1;
            slow = i;
        }
    }
#endif
    return result;
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

// 516. Longest Palindromic Subsequence
int longestPalindromeSubseq(char* s)
{
    int len = (int)strlen(s);
    int i, j;
    int ans;
    int** dp = (int**)malloc(len * sizeof(int*));
    for (i = 0; i < len; i++) {
        dp[i] = (int*)calloc(len, sizeof(int));
        dp[i][i] = 1;
    }
    for (i = len - 1; i >= 0; i--) {
        for (j = i + 1; j < len; j++) {
            if (s[i] == s[j])
                dp[i][j] = dp[i + 1][j - 1] + 2;
            else
                dp[i][j] = (int)fmax(dp[i + 1][j], dp[i][j - 1]);
        }
    }
    ans = dp[0][len - 1];
    for (i = 0; i < len; i++)
        free(dp[i]);
    free(dp);
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

// 530. Minimum Absolute Difference in BST
void traverse(struct TreeNode* root, int* array, int* count)
{
    if (!root)
        return;
    traverse(root->left, array, count);
    array[(*count)++] = root->val;
    traverse(root->right, array, count);

}
int getMinimumDifference(struct TreeNode* root) {
    int* array = (int*)malloc(10000 * sizeof(int));
    int count = 0, mindiff = INT_MAX;
    traverse(root, array, &count);
    for (int i = 1; i < count; i++) {
        mindiff = mindiff <= (array[i] - array[i - 1]) ? mindiff : (array[i] - array[i - 1]);
    }
    return mindiff;
}

// 538. Convert BST to Greater Tree
void reverseinorder(struct TreeNode* root, int* sum)
{
    if (!root)
        return;
    reverseinorder(root->right, sum);
    (*sum) += root->val;
    root->val = *sum;
    reverseinorder(root->left, sum);
}
struct TreeNode* convertBST(struct TreeNode* root)
{
    int sum = 0;
    reverseinorder(root, &sum);

    return root;
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

// 543. Diameter of Binary Tree
int GetHeight(struct TreeNode* root)
{
    if (!root)
        return 0;
    return (int)(fmax(GetHeight(root->left), GetHeight(root->right)) + 1);
}
int diameterOfBinaryTree(struct TreeNode* root) {
    if (!root)
        return 0;
    int lh = GetHeight(root->left);
    int rh = GetHeight(root->right);
    int left = diameterOfBinaryTree(root->left);
    int right = diameterOfBinaryTree(root->right);
    int diameter = left > right ? left : right;
    diameter = (lh + rh) > diameter ? (lh + rh) : diameter;
    return diameter;
}

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

// 583. Delete Operation for Two Strings
int minDelDistance(char* word1, char* word2)
{
    int i, j;
    int ans;
    int m = (int)strlen(word1), n = (int)strlen(word2);
    int** dp = (int**)malloc((m + 1) * sizeof(int*));
    for (i = 0; i < m + 1; i++)
        dp[i] = (int*)calloc(n + 1, sizeof(int));
    for (i = 0; i <= m; i++) {
        for (j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                continue;
            else {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = (int)fmax(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
    }
    ans = n + m - 2 * dp[m][n];

    for (i = 0; i < m + 1; i++)
        free(dp[i]);
    free(dp);
    return ans;
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

// 605. Can Place Flowers
bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n)
{
    int nullbed = 0;
    if (n == 0)
        return true;
    if (flowerbedSize == 1)
    {
        if (flowerbed[0] == 1)
            return false;
        return true;
    }
    for (int i = 0; i < flowerbedSize; i++) {
        if (flowerbed[i] == 1) {
            nullbed = 0;
            continue;
        }
        nullbed++;
        if (i == 1 && nullbed == 2) {
            n--; nullbed = 1;
        }
        else if (nullbed >= 3)
        {
            n--; nullbed = 1;
        }
        if (n == 0)
            return true;
    }
    if (nullbed == 2 && n == 1)
        return true;
    return n > 0 ? false : true;
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

// 621. Task Scheduler
int taskcmp(const void* a, const void* b) {
    return(*(int*)b) - (*(int*)a);
}
int leastInterval(char* tasks, int tasksSize, int n) {
    if (n == 0)
        return tasksSize;

    int i;
    int base[26] = { 0 };
    int info[26] = { 0 };
    for (i = 0; i < tasksSize; i++) {
        info[tasks[i] - 'A']++;
    }
    int interval = 0;
    int k = n + 1;
    while (1) {
        qsort(&info[0], 26, sizeof(int), taskcmp);
        for (i = 0; i < k && i < 26; i++)
        {
            if (info[i] == 0) {
                break;
            }
            info[i]--;
            interval++;
        }
        if (0 == memcmp(info, base, sizeof(int) * 26))
            return interval;
        if (i < k)
            interval += (k - i);
    }
    return interval;
}

// 643. Maximum Average Subarray I
double findMaxAverage(int* nums, int numsSize, int k)
{
    int i, slow = 0;
    double maxave = 0, sum = 0;
    for (i = 0; i < k; i++)
        maxave += nums[i];
    sum = maxave;
    for (i = k; i < numsSize; i++) {
        sum -= nums[slow++];
        sum += nums[i];
        maxave = maxave < sum ? sum : maxave;
    }
    return maxave / k;
}

// 649. Dota2 Senate
char* predictPartyVictory(char* senate)
{
    int i, len = (int)strlen(senate);
    int* QueueR = (int*)malloc(2 * len * sizeof(int));
    int* QueueD = (int*)malloc(2 * len * sizeof(int));
    int  headR = 0, tailR = 0, headD = 0, tailD = 0;

    for (i = 0; i < len; i++)
        senate[i] == 'R' ? (QueueR[headR++] = i) : (QueueD[headD++] = i);

    while (headR > tailR && headD > tailD) {
        int r_index = QueueR[tailR++], d_index = QueueD[tailD++];
        r_index < d_index ? (QueueR[headR++] = r_index + len) : (QueueD[headD++] = d_index + len);
    }
    return ((headR - tailR) > (headD - tailD)) ? (char*)"Radiant" : (char*)"Dire";
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

// 654. Maximum Binary Tree
struct TreeNode* constructMaximumBinaryTree(int* nums, int numsSize)
{
    if(numsSize == 0)
        return NULL;
    struct TreeNode* node = (struct TreeNode*)calloc(1, sizeof(struct TreeNode));

    int max = nums[0], pos = 0;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > max) {
            max = nums[i];
            pos = i;
        }
    }
    node->val = max;
    node->left = constructMaximumBinaryTree(nums, pos);
    node->right = constructMaximumBinaryTree(&nums[pos + 1], numsSize - 1 - pos);
    return node;
}

// 662. Maximum Width of Binary Tree
int widthOfBinaryTree(struct TreeNode* root)
{
    if (!root)
        return 0;
    int width = 1;
    struct TreeNode** treeque = (struct TreeNode**)malloc(3000 * sizeof(struct TreeNode*));
    struct TreeNode* node;
    int head = 0, tail = 0;
    root->val = 0;
    treeque[tail++] = root;
    while (tail > head) {
        int count = tail - head;
        int val = 0;
        int seq = 0;
        int left = INT_MAX, right = INT_MIN;
        for (int i = 0; i < count; i++) {
            node = treeque[head++];
            if (node->left) {
                node->left->val = 2 * node->val;
                val = node->left->val;
                left = left < val ? left : val;
                right = right > val ? right : val;
                treeque[tail++] = node->left;
            }
            if (node->right) {
                node->right->val = 2 * node->val + 1;
                val = node->right->val;
                left = left < val ? left : val;
                right = right > val ? right : val;
                treeque[tail++] = node->right;
            }
        }
        if (left != INT_MAX && right != INT_MIN) {
            width = width < (right - left + 1) ? (right - left + 1) : width;
        }
    }
    free(treeque);
    return width;
}

// 669. Trim a Binary Search Tree
struct TreeNode* trimBST(struct TreeNode* root, int low, int high)
{
    if (!root)
        return root;

    if (root->val < low)
    {
        root->right = trimBST(root->right, low, high);
        return root->right;
    }
    else if (root->val > high)
    {
        root->left = trimBST(root->left, low, high);
        return root->left;
    }
    root->left = trimBST(root->left, low, high);
    root->right = trimBST(root->right, low, high);
    return root;
}

// 673. Number of Longest Increasing Subsequence
int findNumberOfLIS(int* nums, int numsSize)
{
    int i, j;
    int maxi = 1, ans = 0;
    int* dp = (int*)malloc(numsSize * sizeof(int));
    int* cnt = (int*)malloc(numsSize * sizeof(int));
    for (i = 0; i < numsSize; i++) {
        dp[i] = cnt[i] = 1;
    }
    for (i = 0; i < numsSize; i++) {
        for (j = 0; j < i; j++) {
            if (nums[i] > nums[j] && dp[i] < dp[j] + 1) {
                dp[i] = 1 + dp[j];
                cnt[i] = cnt[j];
            }
            else if (nums[i] > nums[j] && dp[i] == dp[j] + 1) {
                cnt[i] += cnt[j];
            }
        }
        maxi = (int)fmax(maxi, dp[i]);
    }
    for (i = 0; i < numsSize; i++) {
        if (dp[i] == maxi)
            ans += cnt[i];
    }
    free(dp);
    free(cnt);
    return ans;
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

    while (root)
    {
        if (root->val == val)
            return root;
        else if (root->val > val)
            root = root->left;
        else
            root = root->right;
    }
    return NULL;
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
class MyHashMap {
public:
    int arr[1000001];
    MyHashMap() {
        fill(arr, arr + 1000000, -1); // initalizing with -1.
    }
    void put(int key, int val) {
        arr[key] = val;
    }
    int get(int key) {
        return arr[key];
    }
    void remove(int key) {
        arr[key] = -1;
    }
};

// 707. Design Linked List
// MyLinkedList

// 713. Subarray Product Less Than K
int numSubarrayProductLessThanK(int* nums, int numsSize, int k)
{
    int count = 0;
    if (k <= 1) return count;

    int i1 = 0;
    int prod = 1;

    for (int i2 = 0; i2 < numsSize; ++i2) {
        prod *= nums[i2];

        while (prod >= k) {
            prod /= nums[i1];
            ++i1;
        }

        count += i2 - i1 + 1;
    }

    return count;
}

// 722. Remove Comments
bool isLineComment(char* s, int col) {
    if (s[col] == '/' && col + 1 != strlen(s) && s[col + 1] == '/')
        return true;
    return false;
}
bool isMultiCommentStart(char* s, int col) {
    if (s[col] == '/' && col + 1 != strlen(s) && s[col + 1] == '*')
        return true;
    return false;
}
bool isMultiCommentEnd(char* s, int col) {
    if (s[col] == '*' && col + 1 != strlen(s) && s[col + 1] == '/')
        return true;
    return false;
}
char** removeComments(char** source, int sourceSize, int* returnSize)
{
    char** res = (char**)malloc(sourceSize * sizeof(char*));
    *returnSize = 0;
    for (int line = 0; line < sourceSize;) {
        char curLine[81] = { 0 };
        int  curcol = 0;
        for (int col = 0; col < strlen(source[line]);) {
            if (isLineComment(source[line], col))
                break;
            else if (isMultiCommentStart(source[line], col)) {
                col += 2;
                while (1) {
                    if (col >= strlen(source[line])) {
                        line++;
                        col = 0;
                    }
                    if (isMultiCommentEnd(source[line], col)) {
                        col += 2;
                        break;
                    }
                    else {
                        col++;
                    }
                }
            }
            else {
                curLine[curcol++] = source[line][col++];
            }
        }
        if (curcol > 0) {
            res[*returnSize] = (char*)calloc(curcol + 1, sizeof(char));
            memcpy(res[*returnSize], curLine, curcol);
            (*returnSize)++;
        }
        line++;
    }

    return res;
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

// 725. Split Linked List in Parts
vector<ListNode*> splitListToParts(ListNode* head, int k)
{
    vector<ListNode*> res(k);
    float total = 0;
    int i, split;
    for (i = 0; i < k; i++)
        res[i] = NULL;

    ListNode* cur = head, * tail;
    while (cur) {
        total++;
        cur = cur->next;
    }
    split = (int)ceil(total / k);
    int index = 0;
    cur = head;

    while (cur) {
        res[index] = cur;
        tail = cur;
        total -= split;
        while (cur && split) {
            tail = cur;
            cur = cur->next;
            split--;
        }
        tail->next = NULL;
        index++; k--;
        if (k > 0) {
            split = (int)ceil(total / k * 1.0);
        }
    }

    return res;
}

// 726. Number of Atoms
string countOfAtoms(string formula)
{
    map<string, int> atoms;
    string ans;
    int cnt = 0, mult = 1;
    stack<int> st;
    string name;

    for (int i = (int)(formula.size() - 1); i >= 0; i--) {
        if (islower(formula[i])) {
            int len = 2;
            i--;
            while (i >= 0 && islower(formula[i])) {
                i--;
                len++;
            }
            name = formula.substr(i, len);
            atoms[name] += max(cnt, 1) * mult;
            cnt = 0;
        }
        else if (isupper(formula[i])) {
            name = formula.substr(i, 1);
            atoms[name] += max(cnt, 1) * mult;
            cnt = 0;
        }
        else if (isdigit(formula[i])) {
            cnt = formula[i] - '0';
            int p = 10;
            while (i > 1 && isdigit(formula[i - 1])) {
                cnt += p * (formula[--i] - '0');
                p *= 10;
            }
        }
        else if (formula[i] == ')') {
            st.push(mult);
            mult *= max(cnt, 1);
            cnt = 0;
        }
        else {      // '('
            mult = st.top();
            st.pop();
        }
    }

    for (auto atom : atoms) {
        ans += atom.first;
        if (atom.second > 1)
            ans += to_string(atom.second);
    }
    return ans;
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

// 735. Asteroid Collision
int* asteroidCollision(int* asteroids, int asteroidsSize, int* returnSize)
{
    int* ans = (int*)malloc(asteroidsSize * sizeof(int));
    int top = 0;
    for (int i = 0; i < asteroidsSize; i++) {
        if (top == 0)
        {
            ans[top++] = asteroids[i];
            continue;
        }
        if ((asteroids[i] * ans[top - 1] > 0) ||
            (ans[top - 1] < 0 && asteroids[i]> 0)) {
            ans[top++] = asteroids[i];
            continue;
        }
        if (fabs(ans[top - 1]) == fabs(asteroids[i])) {
            top--;
        }
        else if (fabs(ans[top - 1]) < fabs(asteroids[i]))
        {
            top--;
            i--;
        }
    }
    *returnSize = top;
    return ans;
}
vector<int> asteroidCollision(vector<int>& asteroids)
{
    vector<int> res;
    int last = 0;
    for (size_t i = 0; i < asteroids.size(); i++) {
        if (res.size() == 0)
        {
            res.push_back(asteroids[i]);
            continue;
        }
        last = res.back();
        if (last * asteroids[i] > 0 ||
            last < 0 && asteroids[i] > 0)
            res.push_back(asteroids[i]);
        else if (fabs(last) < fabs(asteroids[i])) {
            res.pop_back();
            i--;
        }
        else if (fabs(last) == fabs(asteroids[i])) {
            res.pop_back();
        }
    }
    return res;
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
int minCostClimbingStairs(vector<int>& cost)
{
    int dp0 = 0, dp1 = 0;
    for (int i = 2; i <= cost.size(); i++)
    {
        int dpi = (int)min(dp0 + cost[i - 2], dp1 + cost[i - 1]);
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

// 785. Is Graph Bipartite ?
bool isBipartite(int** graph, int graphSize, int* graphColSize)
{
    int n = graphSize;
    int* colors = (int*)calloc(n, sizeof(int));
    int* q = (int*)calloc(n, sizeof(int));
    int head =0, tail = 0;

    for (int i = 0; i < n; i++) {
        if (colors[i]) continue;

        colors[i] = 1;
        q[tail++] = i;

        while (tail > head) {
            int temp = q[head++];

            for (int j = 0; j < graphColSize[temp]; j++) {
                int neighbor = graph[temp][j];
                // Color neighbor with opposite color
                if (!colors[neighbor]) {
                    colors[neighbor] = -1*colors[temp];
                    q[tail++] = neighbor;
                }

                // If the neighbor has the same color - can't bipartite.
                else if (colors[neighbor] == colors[temp])
                    return false;
            }
            //q.pop();
        }
    }
    return true;

}

// 792. Number of Matching Subsequences
//bool isSubsequence(char* s, char* t);
int numMatchingSubseq(char* s, char** words, int wordsSize)
{
    int res = 0;
    int slen = (int)strlen(s);
    int* seqno = (int*)calloc(wordsSize, sizeof(int));
    for (int i = 0; i < wordsSize; i++) {
        if (strlen(words[i]) > slen)
            continue;
        int j = 0;
        for (j = 0; j < i; j++) {
            if (strcmp(words[i], words[j]) == 0)
            {
                res += seqno[j];
                break;
            }
        }
        if (j == i) {
            seqno[i] = isSubsequence(words[i], s);
            res += seqno[i];
        }
    }
#if 0
    for (int i = 0; i < slen; i++) {
        for (int j = 0; j < wordsSize; j++) {
            if (seqno[j] < 0)
                continue;
            if (strlen(words[j]) > slen)
                seqno[j] = -1;
            if (s[i] == words[j][seqno[j]]) {
                seqno[j]++;
                if (words[j][seqno[j]] == '\0') {
                    res++;
                    seqno[j] = -1;
                }
            }
        }
    }
#endif
    return res;
}

// 797. All Paths From Source to Targetint
int path797s[50] = { 0 };
int pathlen = 0;
void dps(int** graph, int cur, int n, int* e, int* count, int** colCount, int** ans)
{
    if (cur == n - 1) {
        (*colCount)[*count] = pathlen;
        ans[*count] = (int*)malloc(sizeof(int) * pathlen);
        memcpy(ans[*count], path797s, pathlen * sizeof(int));
        (*count)++;
        return;
    }

    for (int i = 0; i < e[cur]; i++) {
        path797s[pathlen++] = graph[cur][i];
        dps(graph, graph[cur][i], n, e, count, colCount, ans);
        pathlen--;
    }
}
int** allPathsSourceTarget(int** graph, int graphSize, int* graphColSize, int* returnSize, int** returnColumnSizes)
{
    *returnSize = 0;
    pathlen = 0;
    int** ans = (int**)malloc(sizeof(int*) * 10000);
    *returnColumnSizes = (int*)malloc(sizeof(int) * 10000);

    path797s[pathlen++] = 0;
    dps(graph, 0, graphSize, graphColSize, returnSize, returnColumnSizes, ans);

    return ans;
}

// 872. Leaf - Similar Trees
void leafdfs(struct TreeNode* root, int* leaves, int* count)
{
    if (!root)
        return;
    if (!root->left && !root->right)
    {
        leaves[(*count)++] = root->val;
        return;
    }
    leafdfs(root->left, leaves, count);
    leafdfs(root->right, leaves, count);

}
bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2)
{
    bool ans = false;
    int* leaves1 = (int*)malloc(200 * sizeof(int));
    int* leaves2 = (int*)malloc(200 * sizeof(int));
    int count1 = 0, count2 = 0;
    leafdfs(root1, leaves1, &count1);
    leafdfs(root2, leaves2, &count2);
    if (count1 == count2) {
        if (0 == memcmp(leaves1, leaves2, count1 * sizeof(int)))
            ans = true;
    }

    free(leaves1);
    free(leaves2);
    return ans;
}

// 799. Champagne Tower
double chtower[101][101];
double dpChampagne(double poured, int row, int glass)
{
    double left, right;
    if (row<0 || glass > row || glass < 0)
        return 0;
    if (row == 0 && glass == 0)
        return poured;

    if (chtower[row][glass] > -1)
        return chtower[row][glass];
    left = (dpChampagne(poured, row - 1, glass - 1) - 1) / 2;
    left = left < 0 ? 0 : left;
    right = (dpChampagne(poured, row - 1, glass) - 1) / 2;
    right = right < 0 ? 0 : right;
    
    return chtower[row][glass] = left + right;
}
double champagneTower(int poured, int query_row, int query_glass)
{
    memset(chtower, -1, sizeof(chtower));

    double res = dpChampagne(poured, query_row, query_glass);
    
    return res = res > 1 ? 1 : res;
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

// 905. Sort Array By Parity
int* sortArrayByParity(int* nums, int numsSize, int* returnSize)
{
    int left = 0, right = numsSize - 1;
    *returnSize = numsSize;
#if 0
    int* res = (int*)calloc(numsSize, sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] % 2 == 0)
            res[left++] = nums[i];
        else
            res[right--] = nums[i];
    }
    return res;
#else
    while (left < right) {
        while (nums[left] % 2 == 0 && left < right)
            left++;
        while (nums[right] % 2 == 1 && left < right)
            right--;
        if (left >= right)
            break;
        //swap(nums[left], nums[right]);
        nums[left] = nums[left] ^ nums[right];
        nums[right] = nums[left] ^ nums[right];
        nums[left] = nums[left] ^ nums[right];
        left++, right--;
    }
    return nums;
#endif
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

// 946. Validate Stack Sequences
bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize)
{
    int stack[1000] = { 0 };
    int top = -1;
    int pos = 0;
    
    for (int i = 0; i < pushedSize; i++)
    {
        stack[++top] = pushed[i];
        while (pos < poppedSize && top >= 0 && popped[pos] == stack[top]) {
            pos++;
            top--;
        }
    }

    return (top < 0);
}

// 947. Most Stones Removed with Same Row or Column
void dfsStone(int** stones, int n, bool* visited, int index) {
    visited[index] = 1;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (stones[i][0] == stones[index][0] || stones[i][1] == stones[index][1])
                dfsStone(stones, n, visited, i);
        }
    }
}
int removeStones(int** stones, int stonesSize, int* stonesColSize) {
    int count = 0;
    bool* visited = (bool*)calloc(stonesSize, sizeof(bool));
    for (int i = 0; i < stonesSize; i++) {
        if (!visited[i]) {
            count++;
            dfsStone(stones, stonesSize, visited, i);
        }
    }
    return stonesSize - count;
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

// 1004. Max Consecutive Ones III
int longestOnes(int* nums, int numsSize, int k)
{
    int left = 0, right = 0;
    int maxnum = 0, zeros = 0;

    while (right < numsSize) {
        if (nums[right] == 0)
            zeros++;
        while (zeros > k) {
            if (nums[left] == 0)
                zeros--;
            left++;
        }

        maxnum = maxnum > (right - left + 1) ? maxnum : (right - left + 1);
        right++;
    }
    return maxnum;
}

// 1027. Longest Arithmetic Subsequence
int longestArithSeqLength(int* nums, int numsSize)
{
    int i, j, ans = 0,diff;
    int** dp = (int**)malloc((numsSize+1) * sizeof(int*));
    for (i = 0; i < numsSize; i++)
    {
        dp[i] = (int*)calloc(1001, sizeof(int));
    }
    for (i = 1; i < numsSize; i++) {
        for (j = 0; j < i; j++)
        {
            diff = nums[i] - nums[j];
            dp[i][diff + 500] = dp[i][diff + 500] > (dp[j][diff + 500] + 1) ? dp[i][diff + 500] : (dp[j][diff + 500] + 1);
            ans = dp[i][diff + 500] > ans ? dp[i][diff + 500] : ans;
        }
    }
    for (i = 0; i < numsSize; i++)
    {
        free(dp[i]);
    }
    free(dp);

    return ans + 1;
}

// 1035. Uncrossed Lines
int maxUncrossedLines(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    int i, j;
    int maxnum = nums1Size > nums2Size ? nums1Size : nums2Size;
    int** dp = (int**)malloc((maxnum + 1) * sizeof(int*));
    for (i = 0; i <= maxnum; i++) {
        dp[i] = (int*)malloc((maxnum + 1) * sizeof(int));
        memset(dp[i], -1, (maxnum + 1) * sizeof(int));
        dp[0][i] = 0;
        dp[i][0] = 0;
    }
    for (i = 1; i <= nums1Size; i++)
        for (j = 1; j <= nums2Size; j++) {
            if (nums1[i - 1] == nums2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = dp[i - 1][j] > dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1];
        }
    return dp[nums1Size][nums2Size];
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
    //int i;
    //int idx = -1;
    //int len = (int)strlen(s);

    //char* res = (char*)malloc(len);
    //
    //for (i = 0; i < len; i++)
    //{
    //    if (idx >= 0 && res[idx] == s[i])
    //        idx--;
    //    else {
    //        res[++idx] = s[i];
    //    }
    //}
    //res[++idx] = '\0';

    //return res;
    int len = (int)strlen(s);
    char* result = (char*)calloc(len + 1, sizeof(char));
    int top = -1;
    for (int i = 0; i < len; i++) {
        if (top >= 0 && s[i] == result[top])
            top--;
        else
            result[++top] = s[i];
    }

    result[++top] = '\0';
    return result;
}

// 1048. Longest String Chain
static bool cmpstrlen(const string& strA, const string& strB)
{
    return strA.length() < strB.length();
}
int longestStrChain(vector<string>& words)
{
    unordered_map<string, int> ump;
    int ans = 0;
    sort(words.begin(), words.end(), cmpstrlen);

    for (string w : words) {
        int longest = 0;
        for (int i = 0; i < w.length(); i++) {
            string sub = w;
            sub.erase(i, 1);
            longest = max(longest, ump[sub] + 1);
        }
        ump[w] = longest;
        ans = max(ans, longest);
    }
    return ans;
}

// 1071. Greatest Common Divisor of Strings
char* gcdOfStrings(char* str1, char* str2)
{
    size_t i;
    size_t len1 = strlen(str1), len2 = strlen(str2);
    char* sum1 = (char*)calloc(1, len1 + len2 + 1);
    char* sum2 = (char*)calloc(1, len1 + len2 + 1);
    memcpy(sum1, str1, len1);
    memcpy(sum2, str2, len2);
    memcpy(&sum1[len1], str2, len2);
    memcpy(&sum2[len2], str1, len1);
    if (memcmp(sum1, sum2, len1 + len2) != 0)
    {
        free(sum1);
        free(sum2); 
        return NULL;
    }

    while (len1 != len2)
    {
        if (len1 > len2)
            len1 -= len2;
        if (len1 < len2)
            len2 -= len1;
    }
    size_t minlen = len1;
    char* str = (char*)calloc(1, minlen + 1);
    for (i = 0; i < minlen; i++)
        memcpy(str, str1, minlen);

    for (i = 0; i < strlen(str1) / minlen; i++)
        memcpy(&sum1[i * minlen], str, minlen);
    for (i = 0; i < strlen(str2) / minlen; i++)
        memcpy(&sum2[i * minlen], str, minlen);
    if ((memcmp(str1, sum1, strlen(str1)) != 0) ||
        (memcmp(str2, sum2, strlen(str2)) != 0))
    {
        free(sum1);
        free(sum2);
        free(str);
        return NULL;
    }
    free(sum1);
    free(sum2);
    return str;
}
string gcdOfStrings(string str1, string str2)
{
    string res;

    if ((str1 + str2) != (str2 + str1))
        return "";
    int gcdlen = gcd((int)str1.size(), (int)str2.size());

    return str1.substr(0, gcdlen);
}

// 1091. Shortest Path in Binary Matrix
struct coord {
    int x;
    int y;
};
int shortestPathBinaryMatrix(int** grid, int gridSize, int* gridColSize) {
    int i, j;
    int len = 0;
    int n = gridSize;
    if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
        return -1;
    if (n == 1)
        return 1;

    int** visited = (int**)malloc(n * sizeof(int*));
    for (i = 0; i < n; i++) {
        visited[i] = (int*)calloc(n, sizeof(int));
    }

    struct coord* pathqueue = (struct coord*)calloc(n * n, sizeof(struct coord));
    int tail = 0;
    int head = 0;
    pathqueue[tail].x = 0;
    pathqueue[tail++].y = 0;

    visited[0][0] = 1;
    while (tail > head) {
        int count = tail - head;
        for (int k = 0; k < count; k++)
        {
            struct coord temp = pathqueue[head++];
            for (i = 1; i >= -1; i--)
                for (j = 1; j >= -1; j--) {
                    if (i == 0 && j == 0)
                        continue;
                    int x = temp.x + i;
                    int y = temp.y + j;
                    if (x >= 0 && x < n && y >= 0 && y < n && visited[x][y] == 0 && grid[x][y] == 0)
                    {
                        if (x == n - 1 && y == n - 1)
                            return (len + 2);
                        visited[x][y] = 1;
                        pathqueue[tail].x = x;
                        pathqueue[tail++].y = y;
                    }
                }
        }
        len++;
    }
    if (visited[n - 1][n - 1] == 0)
        return -1;
    return len;
}

// 1095. Find in Mountain Array
int findInMountainArray(int target, MountainArray& mountainArr)
{
    int len = mountainArr.length();
    int left = 0, right = len - 1;
    int mid;
    while (left < right) {
        mid = left + (right - left) / 2;
        if (mountainArr.get(mid) < mountainArr.get(mid + 1))
            left = mid + 1;
        else
            right = mid;
    }
    int peak = left;
    left = 0, right = peak;
    int midval;
    while (left <= right) {
        mid = left + (right - left) / 2;
        midval = mountainArr.get(mid);
        if (midval == target)
        {
            return  mid;
        }
        else if (midval < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    left = peak, right = len - 1;
    while (left <= right) {
        mid = left + (right - left) / 2;
        midval = mountainArr.get(mid);
        if (midval == target) {
            return mid;
        }
        else if (midval < target)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
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

// 1161. Maximum Level Sum of a Binary Tree
int maxLevelSum(struct TreeNode* root)
{
    int res = 1;
    int level = 1;
    int maxSum = INT_MIN;
    int front = 0, tail = 0;
    struct TreeNode* qu[10000] = { 0 };
    if (root)
        qu[front++] = root;

    while (front - tail > 0) {
        int sum = 0;
        int size = front - tail;
        struct TreeNode* node;
        for (int i = 0; i < size; i++) {
            node = qu[tail++];
            sum += node->val;
            if (node->left)
                qu[front++] = node->left;
            if (node->right)
                qu[front++] = node->right;
        }
        if (sum > maxSum) {
            maxSum = sum;
            res = level;
        }
        level++;
    }
    return res;
}

// 1207. Unique Number of Occurrences
int OccurCmp(const void* a, const void* b)
{
    return (*(int*)a) - (*(int*)b);
}
bool uniqueOccurrences(int* arr, int arrSize)
{
    int* arrFreq = (int*)malloc((arrSize + 1) * sizeof(int));
    memset(arrFreq, 0x11, sizeof(int) * (arrSize + 1));
    qsort(arr, arrSize, sizeof(int), OccurCmp);

    int cur = arr[0];
    int freq = 1;
    for (int i = 1; i <= arrSize; i++) {
        if (i < arrSize && cur == arr[i]) {
            freq++;
            continue;
        }
        if (arrFreq[freq] < 1000)
            return false;
        arrFreq[freq] = cur;
        if (i < arrSize) {
            cur = arr[i];
            freq = 1;
        }
    }
    return true;
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

// 1337. The K Weakest Rows in a Matrix
vector<int> kWeakestRows(vector<vector<int>>& mat, int k)
{
    set<pair<int, int>>s;

    for (int i = 0; i < (int)mat.size(); i++) {
        int count = (int)mat[i].size();
        for (int j = 0; j < (int)mat[i].size(); j++) {
            if (mat[i][j] == 0)
            {
                count = j;
                break;
            }
        }
        s.insert({ count, i });
    }
    vector<int> res;
    for (auto x = s.begin(); k > 0; k--, x++) {
        res.push_back(x->second);
    }
    return res;
}

// 1361. Validate Binary Tree Nodes
bool bfs1361(int n, int begin, int* left, int* right, int* visited) 
{
    if (begin >= n)
        return false;
    if (visited[begin] > 1)
        return false;

    visited[begin]++;
    if (left[begin] != -1)
    {
        visited[begin]++;
        if (!bfs1361(n, left[begin], left, right, visited))
            return false;
    }
    if (right[begin] != -1)
    {
        visited[begin]++;
        if (!bfs1361(n, right[begin], left, right, visited))
            return false;
    }
    return true;
}
bool validateBinaryTreeNodes(int n, int* leftChild, int leftChildSize, int* rightChild, int rightChildSize)
{
    int i;
    int root = -1;
    int* visited = (int*)calloc(n, sizeof(int));
    memset(visited, 0, sizeof(int) * n);
    for (i = 0; i < n; i++) {
        if (leftChild[i] != -1) {
            if (visited[leftChild[i]] == -1)
                return false;
            visited[leftChild[i]] = -1;
        }
        if (rightChild[i] != -1) {
            if (visited[rightChild[i]] == -1)
                return false;
            visited[rightChild[i]] = -1;
        }
    }
    for (i = 0; i < n; i++) {
        if (visited[i] == 0) {
            if (root >= 0)
                return false;
            root = i;
            visited[i] = -1;
        }
    }
    if (root == -1)
        return false;
    if (!bfs1361(n, root, leftChild, rightChild, visited))
        return false;
    for (int i = 0; i < n; i++)
        if (visited[i] < 0 || visited[i] > 2)
            return false;
    return true;
}

// 1431. Kids With the Greatest Number of Candies
bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize)
{
    bool* result = (bool*)calloc(candiesSize, sizeof(bool));
    *returnSize = candiesSize;
    int max = candies[0];
    int i;
    for (i = 1; i < candiesSize; i++) {
        max = max < candies[i] ? candies[i] : max;
    }
    for (i = 0; i < candiesSize; i++) {
        if (candies[i] + extraCandies >= max)
            result[i] = true;
    }

    return result;
}
vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies)
{
    int len = (int)candies.size();
    vector<bool> res(len);
    int max = candies[0];
    int i;
    for (i = 1; i < len; i++)
        max = candies[i] > max ? candies[i] : max;
    for (i = 0; i < len; i++)
        if (candies[i] + extraCandies >= max)
            res[i] = true;
    return res;
}

// 1456. Maximum Number of Vowels in a Substring of Given Length
bool IsVowelChar(char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return true;
    return false;
}
int maxVowels(char* s, int k) {
    int count = 0;
    int i, slow = 0;
    for (i = 0; i < k; i++) {
        if (IsVowelChar(s[i]))
            count++;
    }
    int maxNum = count;
    for (; i < strlen(s); i++) {
        if (IsVowelChar(s[slow++]))
            count--;
        if (IsVowelChar(s[i]))
            count++;
        maxNum = maxNum < count ? count : maxNum;
    }
    return maxNum;
}

// 1470. Shuffle the Array
int* shuffle(int* nums, int numsSize, int n, int* returnSize)
{
    int* ans = (int*)malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;
    for (int i = 0; i < n; i++)
    {
        ans[2 * i] = nums[i];
        ans[2 * i + 1] = nums[n + i];
    }
    return ans;
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

// 1491.Average Salary Excluding the Minimumand Maximum Salary
double average(int* salary, int salarySize)
{
    int min = INT_MAX, max = INT_MIN;
    double sum = 0;
    for (int i = 0; i < salarySize; i++) {
        sum += salary[i];
        max = salary[i] > max ? salary[i] : max;
        min = salary[i] < min ? salary[i] : min;
    }
    sum -= max;
    sum -= min;
    return sum / (salarySize - 2);
}

// 1493. Longest Subarray of 1's After Deleting One Element
int longestSubarray(int* nums, int numsSize)
{
    return 0;
}

// 1512. Number of Good Pairs
int numIdenticalPairs(int* nums, int numsSize)
{
    int freq[101] = { 0 };
    int i, res = 0;
    for (i = 0; i < numsSize; i++) {
        freq[nums[i]]++;
    }
    for (i = 1; i <= 100; i++) {
        if (freq[i] > 1)
            res += (freq[i] * (freq[i] - 1)) / 2;
    }
    return res;
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

// 1572. Matrix Diagonal Sum
int diagonalSum(int** mat, int matSize, int* matColSize)
{
    int sum = 0;
    for (int i = 0; i < matSize; i++)
    {
        sum += mat[i][i];
        sum += mat[i][matSize - i - 1];
    }
    if (matSize % 2 == 1)
        sum -= mat[matSize / 2][matSize / 2];
    return sum;
}

// 1647. Minimum Deletions to Make Character Frequencies Unique
int minDeletions(string s)
{
    int i;
    int freq[26] = { 0 };
    for (i = 0; i < s.size(); i++) {
        freq[s[i] - 'a']++;
    }
    sort(freq, freq + 26);
    int res = 0;
    int k;
    for (i = 24; i >= 0; i--) {
        if (freq[i] <= 0)
            break;
        if (freq[i] >= freq[i + 1]) {
            k = freq[i] - freq[i + 1] + 1;
            k = min(freq[i], k);
            res += k;
            freq[i] -= k;
        }
    }
    return res;
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

// 1706. Where Will the Ball Fall
int CheckPath(int** grid, int rows, int cols, int row, int col)
{
    if (row == rows)
        return col;
    if ((col == 0 && grid[row][col] == -1) ||
        (col == cols - 1 && grid[row][col] == 1))
        return -1;
    if (col > 0 && grid[row][col - 1] == 1 && grid[row][col] == -1)
        return -1;
    if (col < cols - 1 && grid[row][col] == 1 && grid[row][col + 1] == -1)
        return -1;
    if (grid[row][col] == 1)
        return CheckPath(grid, rows, cols, row + 1, col + 1);
    else
        return CheckPath(grid, rows, cols, row + 1, col - 1);
}
int* findBall(int** grid, int gridSize, int* gridColSize, int* returnSize)
{
    int col;
    int rows = gridSize, cols = gridColSize[0];
    int* ans = (int*)calloc(cols, sizeof(int));
    *returnSize = cols;
    for (col = 0; col < cols; col++) {
        ans[col] = CheckPath(grid, rows, cols, 0, col);
    }
    return ans;
}

// 1721. Swapping Nodes in a Linked List
struct ListNode* swapNodes(struct ListNode* head, int k)
{
    struct ListNode* first, * last, * cur;
    int temp = 0;
    cur = head;
    for (int i = 0; i < k - 1; i++)
    {
        cur = cur->next;
    }
    first = cur;
    last = head;
    while (cur->next) {
        last = last->next;
        cur = cur->next;
    }
    //printf("%d, %d\r\n", first->val, last->val);
    temp = first->val;
    first->val = last->val;
    last->val = temp;

    return head;
}

// 1732. Find the Highest Altitude
int largestAltitude(int* gain, int gainSize)
{
    int altitude = 0;
    int ans = 0;
    for (int i = 0; i < gainSize; i++)
    {
        altitude += gain[i];
        ans = altitude > ans ? altitude : ans;
    }
    return ans;
}

// 1768. Merge Strings Alternately
char* mergeAlternately(char* word1, char* word2)
{
    int len1 = (int)strlen(word1), len2 = (int)strlen(word2);
    int len = len1 + len2;
    int pos = 0;
    char* result = (char*)calloc(len + 1, sizeof(char));
    for (int i = 0; i < (int)fmin(len1, len2); i++) {
        result[pos++] = word1[i];
        result[pos++] = word2[i];
    }
    if (len1 > len2) {
        memcpy(&result[pos], &word1[len2], len1 - len2);
    }
    else if (len2 > len1) {
        memcpy(&result[pos], &word2[len1], len2 - len1);
    }
    return result;
}

// 1799. Maximize Score After N Operations
int gcd(int a, int b)
{
    if (a < b) {
        a ^= b;
        b ^= a;
        a ^= b;
    }
    int c = a % b;
    while (c) {
        a = b;
        b = c;
        c = a % b;
    }
    return b;
}
int dpScore(int* nums, int m, int op, int mask, int* dp)
{
    int n = m / 2;
    if (op > n)
        return 0;
    if (dp[mask] != 0)
        return dp[mask];
    for (int i = 0; i < m; i++) {
        if (mask & (1 << i)) continue;
        for (int j = i + 1; j < m; j++) {
            if (mask & (1 << j)) continue;
            int newmask = (1 << i) | (1 << j) | mask;
            int score = op * gcd(nums[i], nums[j]) + dpScore(nums, m, op + 1, newmask, dp);
            dp[mask] = dp[mask] > score ? dp[mask] : score;
        }
    }
    return dp[mask];
}
int maxScore(int* nums, int numsSize) {
    int* dp = (int*)calloc(1 << 14, sizeof(int));
    int ans;
    ans = dpScore(nums, numsSize, 1, 0, dp);
    free(dp);
    return ans;
}

// 1822. Sign of the Product of an Array
int arraySign(int* nums, int numsSize)
{
    int count = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 0)
            return 0;
        if (nums[i] < 0)
            count++;
    }
    return count % 2 ? -1 : 1;
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

// 2001. Number of Pairs of Interchangeable Rectangles
long long interchangeableRectangles(vector<vector<int>>& rectangles)
{
    map<double, int> freq;
    map<double, int>::iterator it;
    double ratio;
    long long res = 0;
    for (int i = 0; i < rectangles.size(); i++) {
        ratio = rectangles[i][0] * 1.0 / rectangles[i][1];
        it = freq.find(ratio);
        if (it != freq.end()) {
            res += it->second;
            it->second++;
        }
        else
            freq.insert({ ratio, 1 });
    }
    return res;
}

// 2009. Minimum Number of Operations to Make Array Continuous
int minopercmp(const void* a, const void* b)
{
    return (*(int*)a) - (*(int*)a);
}
int minOperations(int* nums, int numsSize)
{
    int res = numsSize - 1;

    qsort(nums, numsSize, sizeof(int), minopercmp);
    return res;
}
int minOperations(std::vector<int>& nums) {
    int n = (int)nums.size();
    std::sort(nums.begin(), nums.end());
    std::vector<int> uniqueNums(nums.begin(), std::unique(nums.begin(), nums.end()));
    int ans = std::numeric_limits<int>::max();

    for (int i = 0; i < uniqueNums.size(); ++i) {
        int s = uniqueNums[i];
        int e = s + n - 1;
        auto it = std::upper_bound(uniqueNums.begin(), uniqueNums.end(), e);

        int idx = (int)std::distance(uniqueNums.begin(), it);
        ans = std::min(ans, n - (idx - i));
    }
    return ans;
}

// 2038. Remove Colored Pieces if Both Neighbors are the Same Color
bool winnerOfGame(char* colors)
{
    int len = (int)strlen(colors);
    int countA = 0, countB = 0;

    for (int i = 0; i < len; i++) {
        char x = colors[i];
        int count = 0;
        while (i < len && colors[i] == x) {
            i++;
            count++;
        }
        count = (count - 2) > 0 ? (count - 2) : 0;
        if (x == 'A')
            countA += count;
        else if (x == 'B')
            countB += count;
        i--;
    }

    return (countA > countB);
}

// 2095. Delete the Middle Node of a Linked List
struct ListNode* deleteMiddle(struct ListNode* head)
{
    struct ListNode* dummy = (struct ListNode*)calloc(1, sizeof(struct ListNode));
    struct ListNode* slow = dummy;
    dummy->next = head;
    while (head && head->next) {
        head = head->next->next;
        slow = slow->next;
    }
    if (slow->next != NULL)
    {
        head = slow->next;
        slow->next = slow->next->next;
        free(head);
    }
    slow = dummy->next;
    free(dummy);
    return slow;
}

// 2130. Maximum Twin Sum of a Linked List
struct ListNode*  x;
void stacktraverse(struct ListNode* half, int* ans)
{
    int sum = 0;
    if (!half)
        return;
    stacktraverse(half->next, ans);
    sum = half->val + x->val;
    (*ans) = (*ans) > sum ? (*ans) : sum;
    x = x->next;
}
int pairSum(struct ListNode* head) {
    struct ListNode* fast = head, * slow = head;
    x = head;
    int ans = 0;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    stacktraverse(slow, &ans);
    return ans;
}
//int pairSum(struct ListNode* head)
//{
//    int* nodeval = (int*)calloc(100000, sizeof(int));
//    int count = 0;
//    int maxsum = 0;
//    while (head)
//    {
//        nodeval[count++] = head->val;
//        head = head->next;
//    }
//    for (int i = 0; i < count / 2; i++) {
//        int sum = nodeval[i] + nodeval[count - 1 - i];
//        maxsum = maxsum < sum ? sum : maxsum;
//    }
//    free(nodeval);
//    return maxsum;
//}

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

// 2215. Find the Difference of Two Arrays
int diffcmp(const void* a, const void* b) {
    return (*(int*)a) - (*(int*)b);
}
int** findDifference(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize, int** returnColumnSizes)
{
    qsort(nums1, nums1Size, sizeof(int), diffcmp);
    qsort(nums2, nums2Size, sizeof(int), diffcmp);
    int** ans = (int**)malloc(2 * sizeof(int*));
    (*returnColumnSizes) = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    ans[0] = (int*)malloc(nums1Size * sizeof(int));
    ans[1] = (int*)malloc(nums2Size * sizeof(int));
    int i = 0, j = 0;
    int c1 = 0, c2 = 0;
    while (i < nums1Size && j < nums2Size) {
        while (i < nums1Size - 1 && nums1[i] == nums1[i + 1])
            i++;
        while (j < nums2Size - 1 && nums2[j] == nums2[j + 1])
            j++;
        if (nums1[i] == nums2[j]) {
            i++, j++;
        }
        else if (nums1[i] < nums2[j]) {
            ans[0][c1++] = nums1[i++];
        }
        else {
            ans[1][c2++] = nums2[j++];
        }
    }
    while (i < nums1Size) {
        while (i < nums1Size - 1 && nums1[i] == nums1[i + 1])
            i++;
        ans[0][c1++] = nums1[i++];
    }
    while (j < nums2Size) {
        while (j < nums2Size - 1 && nums2[j] == nums2[j + 1])
            j++;
        ans[1][c2++] = nums2[j++];
    }
    (*returnColumnSizes)[0] = c1;
    (*returnColumnSizes)[1] = c2;
    return ans;
}
vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2)
{
    map<int, int> map1, map2;
    int len1 = (int)nums1.size(), len2 = (int)nums2.size();
    int i = 0, j = 0;
    vector<vector<int>> res;
    vector<int> diff1, diff2;
    
    while (i < len1) {
        map1[nums1[i]]++;
    }
    while (i < len2) {
        map2[nums2[i]]++;
    }
    for (auto m : map1) {
        if (map2.find(m.first) == map2.end()) {
            diff1.push_back(m.first);
        }
    }
    for (auto m : map2) {
        if (map1.find(m.first) == map1.end()) {
            diff2.push_back(m.first);
        }
    }
    res.push_back(diff1);
    res.push_back(diff2);
    return res;
#if 0
    vector<vector<int>> res;
    vector<int> diff1, diff2;
    int len1 = (int)nums1.size(), len2 = (int)nums2.size();
    int i = 0, j = 0;
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    
    while (i < len1 && j < len2) {
        while (i < len1 - 1 && nums1[i] == nums1[i + 1])
            i++;
        while (j < len2 - 1 && nums2[j] == nums2[j + 1])
            j++;
        if (nums1[i] == nums2[j]) {
            i++, j++;
        }
        else if (nums1[i] > nums2[j]) {
            diff1.push_back(nums2[j]);
            j++;
        }
        else if (nums1[i] < nums2[j]) {
            diff2.push_back(nums1[i]);
            i++;
        }
    }
    while (i < len1) {
        while (i < len1 - 1 && nums1[i] == nums1[i + 1])
            i++;
        diff2.push_back(nums1[i]);
        i++;
    }
    while (j < len2) {
        while (j < len2 - 1 && nums2[j] == nums2[j + 1])
            j++;
        diff1.push_back(nums2[j]);
        j++;
    }
    res.push_back(diff2);
    res.push_back(diff1);
    return res;
#endif
}

// 2251. Number of Flowers in Full Bloom
int flowercmp(const void* a, const void* b)
{
    return (*(int*)a) - (*(int*)b);
}
int* fullBloomFlowers(int** flowers, int flowersSize, int* flowersColSize, int* people, int peopleSize, int* returnSize)
{
    int* ans = (int*)malloc(peopleSize * sizeof(int));

    int* flower_starts = (int*)malloc(flowersSize * 2 * sizeof(int));
    int* flower_ends = flower_starts + flowersSize;

    for (int i = 0; i < flowersSize; i++) {
        flower_starts[i] = flowers[i][0];
        flower_ends[i] = flowers[i][1] + 1;
    }

    int* people_with_id = (int*)malloc(peopleSize * 2 * sizeof(int));

    for (int i = 0; i < peopleSize; i++) {
        people_with_id[i * 2] = people[i];
        people_with_id[i * 2 + 1] = i;
    }

    // Sort the arrays
    qsort(flower_starts, flowersSize, sizeof(int), flowercmp);
    qsort(flower_ends, flowersSize, sizeof(int), flowercmp);
    qsort(people_with_id, peopleSize, 2 * sizeof(int), flowercmp);

    int next_flower_start = 0;
    int next_flower_end = 0;
    int num_flowers = 0;

    for (int i = 0; i < peopleSize; i++) {
        int target_time = people_with_id[i * 2];
        int person_id = people_with_id[i * 2 + 1];

        while (next_flower_start < flowersSize && flower_starts[next_flower_start] <= target_time) {
            num_flowers++;
            next_flower_start++;
        }

        while (next_flower_end < flowersSize && flower_ends[next_flower_end] <= target_time) {
            num_flowers--;
            next_flower_end++;
        }

        ans[person_id] = num_flowers;
    }

    free(flower_starts);
    free(people_with_id);

    *returnSize = peopleSize;
    return ans;
}

// 2352. Equal Row and Column Pairs
int equalPairs(int** grid, int gridSize, int* gridColSize)
{
    int i = 0, j = 0;
    int ans = 0;
    int** transpose = (int**)malloc(gridSize * sizeof(int*));
    for (i = 0; i < gridSize; i++) {
        transpose[i] = (int*)malloc(gridSize * sizeof(int));
        for (j = 0; j < gridSize; j++)
            transpose[i][j] = grid[j][i];
    }
    for (i = 0; i < gridSize; i++) {
        for (j = 0; j < gridSize; j++)
            if (memcmp(grid[i], transpose[j], sizeof(int) * gridSize) == 0)
                ans++;
    }

    for (i = 0; i < gridSize; i++)
        free(transpose[i]);
    free(transpose);
    return ans;
}

// 2390. Removing Stars From a String
char* removeStars(char* s)
{
    int len = (int)strlen(s);
    char* res = (char*)calloc(len+1, sizeof(char));
    int top = 0;
    for (int i = 0; i < len; i++)
    {
        if (s[i] != '*')
            res[top++] = s[i];
        else if(top > 0)
            top--;
    }
    res[top] = '\0';
    return res;
}

// 2466. Count Ways To Build Good Strings
int mod = (int)(1e9 + 7);
int goodstring(int target, int zero, int one, int* dp) {
    if (target == 0)
        return 1;
    if (target < 0)
        return 0;
    if (dp[target] != -1)
        return dp[target];
    long long sum;
    sum = goodstring(target - one, zero, one, dp) + goodstring(target - zero, zero, one, dp);
    return dp[target] = sum % mod;
}
int countGoodStrings(int low, int high, int zero, int one) {
    int ans = 0;
    int* dp = (int*)malloc((high + 1) * sizeof(int));
    memset(dp, -1, (high + 1) * sizeof(int));
    for (int i = low; i <= high; i++) {
        ans = (ans + goodstring(i, zero, one, dp)) % mod;
    }
    free(dp);
    return ans;
}

// 2483. Minimum Penalty for a Shop
int bestClosingTime(string customers)
{
    int len = (int)customers.size();
    vector<int> penalty(len + 1);
    int i;
    for (i = len - 1; i >= 0; i--) {
        penalty[i] = penalty[i + 1];
        if (customers[i] == 'Y')
            penalty[i]++;
    }
    int min = penalty[0];
    int j = 0;
    int NN = 0;
    for (i = 1; i <= len; i++) {
        penalty[i] += NN;
        if (customers[i - 1] == 'N') {
            NN++;
            penalty[i]++;
        }
        if (penalty[i] < min) {
            min = penalty[i];
            j = i;
        }
    }
    return j;
}
// 2542. Maximum Subsequence Score
// overtime
/*
Input: nums1 = [1,3,3,2], nums2 = [2,1,3,4], k = 3
Output: 12
Explanation:
The four possible subsequence scores are:
- We choose the indices 0, 1, and 2 with score = (1+3+3) * min(2,1,3) = 7.
- We choose the indices 0, 1, and 3 with score = (1+3+2) * min(2,1,4) = 6.
- We choose the indices 0, 2, and 3 with score = (1+3+2) * min(2,3,4) = 12.
- We choose the indices 1, 2, and 3 with score = (3+3+2) * min(1,3,4) = 8.
Therefore, we return the max score, which is 12.
*/
int ScoreSum[100000] = { 0 };
int ScoreMin[100000] = { 0 };
int ScoreLen = 0;
void backtrackScore(int* num1, int* num2, int n, int k, int start, bool* visited, long long* ans)
{
    long long sum = 0;
    int minval = INT_MAX;
    int i;
    if (ScoreLen == k)
    {
        for (i = 0; i < k; i++) {
            sum += ScoreSum[i];
            minval = minval > ScoreMin[i] ? ScoreMin[i] : minval;
            //printf("%d,%d; ", ScoreSum[i], ScoreMin[i]);
        }
        sum *= minval;
        *ans = *ans < sum ? sum : *ans;
        //printf("s:%d, ans %d\r\n ", sum, *ans);
        return;
    }

    for (i = start; i < n; i++)
    {
        if (visited[i])
            continue;

        visited[i] = true;
        ScoreSum[ScoreLen] = num1[i];
        ScoreMin[ScoreLen++] = num2[i];
        backtrackScore(num1, num2, n, k, i, visited, ans);
        ScoreLen--;
        visited[i] = false;
    }
}
long long maxScore(int* nums1, int nums1Size, int* nums2, int nums2Size, int k)
{
    long long ans = 0;
    bool* visited = (bool*)calloc(nums1Size, sizeof(bool));

    ScoreLen = 0;
    backtrackScore(nums1, nums2, nums1Size, k, 0, visited, &ans);

    return ans;
}

// 2742. Painting the Walls
int paintdp(int* cost, int costSize, int* time, int timeSize, int cindex, int tindex, int** dp)
{
    if (tindex <= 0)
        return 0;
    if (cindex >= costSize)
        return (int)1e9;
    if (dp[cindex][tindex] != -1)
        return dp[cindex][tindex];

    int nottake = paintdp(cost, costSize, time, timeSize, cindex + 1, tindex, dp);
    int take = cost[cindex] + paintdp(cost, costSize, time, timeSize, cindex + 1, tindex - time[cindex] - 1, dp);
    return dp[cindex][tindex] = nottake > take ? take : nottake;
}
int paintWalls(int* cost, int costSize, int* time, int timeSize)
{
    int res;
    //int dp[501][501] = { -1 };
    int** dp = (int**)malloc((costSize + 1) * sizeof(int*));
    for (int i = 0; i <= costSize; i++)
    {
        dp[i] = (int*)malloc((timeSize + 1) * sizeof(int));
        memset(dp[i], -1, (timeSize+1) * sizeof(int));
    }
    res = paintdp(cost, costSize, time, timeSize, 0, timeSize, &(&dp[0])[0]);
    for (int i = 0; i <= costSize; i++)
        free(dp[i]);
    free(dp);
    return res;
}

// 剑指 Offer 05. 替换空格
// 输入：s = "We are happy."
// 输出："We%20are%20happy."
char* replacespace(char* s)
{
    int i = 0, len = (int)strlen(s);
    int spacenum = 0;
    for (i = 0; i < len; i++) {
        if (s[i] == ' ')
            spacenum++;
    }
    if (spacenum == 0)
        return s;
    char* result = (char*)malloc(sizeof(char) * (len + 2 * spacenum));
    int j = len + 2 * spacenum - 1;
    for (i = len - 1; i >= 0; i--) {
        if (s[i] == ' ') {
            result[j--] = '0';
            result[j--] = '2';
            result[j--] = '%';
        }
        else
            result[j--] = s[i];
    }
    return result;
}

// 剑指 Offer 58 - II.左旋转字符串
// 输入: s = "abcdefg", k = 2
// 输出: "cdefgab"
string reverseLeftWords(string s, int n)
{
    reverseString(&*s.begin(), n);
    reverseString(&*s.begin() + n, (int)s.length() - n);
    reverseString(&*s.begin(), (int)s.length());
    return s;
}


char* reverseLeftWords(char* s, int n)
{
    int len = (int)strlen(s);
    reverseString(s, len);
    reverseString(&s[0], len - n);
    reverseString(&s[len-n], n);
    return s;
}


// 9999 字符串长度 3 < n < 10000000 寻找的单词长度为3
// ABCDEFABCDEBC
// 
// 这只是一道很简单的字符串问题，从给定的一个字符串中寻找一个单词出现的个数，
// 当然这个单词在字符串中是可以被拆开的，但出现字母的顺序必须要正确。
// 举个栗子，在 “mdlldltxdy” 这个字符串中，mdl就出现了四次。（下标123，124，126，156），
// 我们只需要把这个次数4输出就可以了。结果可能过大，对mod 1e9+7即可。
// （这里的单词可能会出现一些奇奇怪怪的东西，像
// mdlldltxdy
// mdl
// 4

//mmmdddllltql
//mdl

//输出样例#2：
//36
const int N = 10000;
//int mod = (int)(1e9 + 7);
int FindSubFrequence(char* s, char* word)
{
    int len, i, ans = 0;
    len = (int)strlen(s);

    //for (i = 0; i < len - 2; i++)
    //{
    //    for (int m = i + 1; m < len - 1; m++)
    //        for (int n = m + 1; n < len; n++)
    //            if (s[i] == word[0] && s[m] == word[1] && s[n] == word[2])
    //                ans++;
    //}
    //return ans;

    int* cnt = (int*)calloc(len, sizeof(int));
    for (i = 0; i < len; i++)
    {
        if (i != 0)
            cnt[i] = cnt[i - 1];
        if (s[i] == word[0])
            cnt[i]++;
    }
    int right = 0;
    // mmmdddllltql
    for (i = len - 1; i > 0; i--)
    {
        if (s[i] == word[2])
            right++;
        if (s[i] == word[1])
            ans += right * cnt[i];
        //ans %= mod;
    }
    free(cnt);
    return ans;
}