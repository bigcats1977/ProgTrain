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
bool isValid(char* s)
{
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

// 49. Group Anagrams
char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes)
{
    if (strsSize == 0)
        return NULL;

    
    return NULL;
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

// 704. Binary Search
int search(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;
    int mid;

    if (NULL == nums || numsSize < 1)
        return -1;

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

// ½£Ö¸ Offer 58 - II.×óÐý×ª×Ö·û´®
string reverseLeftWords(string s, int n)
{
    reverseString(&*s.begin(), n);
    reverseString(&*s.begin() + n, (int)s.length() - n);
    reverseString(&*s.begin(), (int)s.length());

    return s;
}