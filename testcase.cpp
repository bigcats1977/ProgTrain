#include "testcase.h"
#include "MyLinkedList.h"

FUNCNAME g_tFuncName[] = {
    {1,     TestCase_1   },
    {3,     TestCase_3   },
    {19,    TestCase_19  },
    {20,    TestCase_20  },
    {24,    TestCase_24  },
    {26,    TestCase_26  },
    {27,    TestCase_27  },
    {28,    TestCase_28  },
    {34,    TestCase_34  },
    {35,    TestCase_35  },
    {49,    TestCase_49  },
    {53,    TestCase_53  },
    {69,    TestCase_69  },
    {76,    TestCase_76  },
    {88,    TestCase_88  },
    {102,   TestCase_102 },
    {118,   TestCase_118 },
    {142,   TestCase_142 },
    {151,   TestCase_151 },
    {160,   TestCase_160 },
    {167,   TestCase_167 },
    {189,   TestCase_189 },
    {202,   TestCase_202 },
    {203,   TestCase_203 },
    {205,   TestCase_205 },
    {206,   TestCase_206 },
    {209,   TestCase_209 },
    {217,   TestCase_217 },
    {242,   TestCase_242 },
    {283,   TestCase_283 },
    {344,   TestCase_344 },
    {349,   TestCase_349 },
    {350,   TestCase_350 },
    {367,   TestCase_367 },
    {383,   TestCase_383 },
    {387,   TestCase_387 },
    {392,   TestCase_392 },
    {523,   TestCase_523 },
    {541,   TestCase_541 },
    {557,   TestCase_557 },
    {566,   TestCase_566 },
    {567,   TestCase_567 },
    {704,   TestCase_704 },
    {707,   TestCase_707 },
    {724,   TestCase_724 },
    {766,   TestCase_766 },
    {844,   TestCase_844 },
    {904,   TestCase_904 },
    {977,   TestCase_977 },
    {1047,  TestCase_1047},
    {1239,  TestCase_1239},
    {1480,  TestCase_1480},
    {1662,  TestCase_1662},
    {1832,  TestCase_1832},
    {8058,  TestCase_8058},
};

void TestCase_387()
{
    string s;
    int expect;
    int output;

    s = "aabb";
    expect = -1;
    output = firstUniqChar(&*s.begin());
    COMPVALUE(expect, output);

    s = "loveleetcode";
    expect = 2;
    output = firstUniqChar(&*s.begin());
    COMPVALUE(expect, output);
}

void TestCase_102()
{
    vector<int> input;
    TreeNode* root;
    int nr, nl;
    int* nnl = &nl;

    input = { 3,9,20,-1,-1,15,7 };

    root = CreateBinaryTree(input);
    levelOrder(root,&nr, &nnl);
}

void TestCase_567()
{
    string s1, s2;
    bool expect;
    bool output;

    s1 = "ab";
    s2 = "eidbaooo";
    expect = true;
    output = checkInclusion(&*s1.begin(), &*s2.begin());
    COMPVALUE(expect, output);

    s1 = "ab";
    s2 = "eidboaoo";
    expect = false;
    output = checkInclusion(&*s1.begin(), &*s2.begin());
    COMPVALUE(expect, output);
}

void TestCase_3()
{
    string s;
    int expect;
    int output;

    s = " ";
    expect = 1;
    output = lengthOfLongestSubstring(&*s.begin());
    COMPVALUE(expect, output);


    s = "tmmzuxt";
    expect = 5;
    output = lengthOfLongestSubstring(&*s.begin());
    COMPVALUE(expect, output);

    s = "abcabcbb";
    expect = 3;
    output = lengthOfLongestSubstring(&*s.begin());
    COMPVALUE(expect, output);

    s = "bbbbb";
    expect = 1;
    output = lengthOfLongestSubstring(&*s.begin());
    COMPVALUE(expect, output);

    s = "pwwkew";
    expect = 3;
    output = lengthOfLongestSubstring(&*s.begin());
    COMPVALUE(expect, output);
}

void TestCase_118()
{
    int nr, nl;
    int* nnl = &nl;
    generate(5, &nr, &nnl);
}

void TestCase_566()
{
    int** p;
    int nr, nl;
    int* nnl = &nl;

    int matrix[3][4] = { {1, 2, 3, 4}, {5, 1, 2, 3}, {9, 5, 1, 2 } };
    int col = 4;

    p = (int**)malloc(sizeof(int*) * 3);
    for (int i = 0; i < 3; i++) {
        p[i] = (int*)malloc(sizeof(int) * 4);
        for (int j = 0; j < 4; j++) {
            p[i][j] = matrix[i][j];
        }
    }
    matrixReshape(p, 3, &col, 4,3, &nr, &nnl);


    int bb[2][2] = { {1, 2}, {3,4}};
    col = 2;
    p = (int**)malloc(sizeof(int*) * 2);
    for (int i = 0; i < 2; i++) {
        p[i] = (int*)malloc(sizeof(int) * 2);
        for (int j = 0; j < 2; j++) {
            p[i][j] = bb[i][j];
        }
    }
    matrixReshape(p, 2, &col, 1, 4, &nr, &nnl);
};

void TestCase_557()
{
    string s;
    char* output;
    
    s = "Let's take LeetCode contest";
    COUTARRAY((&*s.begin()), s.length());
    output =  reverseWordsIII(&*s.begin());
    COUTARRAY((&*s.begin()), s.length());
}

void TestCase_88()
{
    vector<int> nums1 = { 1,2,3,0,0,0 };
    vector<int> nums2 = { 2,5,6 };
    merge(nums1.data(), (int)nums1.size(), 3, nums2.data(), (int)nums2.size(), 3);
}

void TestCase_53()
{
    int nums[] = { -2,1,-3,4,-1,2,1,-5,4 };
    int expect = 6;
    int output;
    output = maxSubArray(nums, 9);
    COMPVALUE(expect, output);
}

void TestCase_167()
{
    vector<int> nums;
    int target;
    vector<int> expect;
    int rSize;
    int* output;

    nums = { 2,7,11,15 };
    target = 9;
    expect = { 1,2 };
    output = twoSumII(nums.data(), (int)nums.size(), target, &rSize);
    COMPARRAY(expect.data(), expect.size(), output, rSize);
    FREEMEM(output);

    nums = { 2,3,4 };
    target =6;
    expect = { 1,3 };
    output = twoSumII(nums.data(), (int)nums.size(), target, &rSize);
    COMPARRAY(expect.data(), expect.size(), output, rSize);
    FREEMEM(output);

    nums = { -1,0 };
    target = -1;
    expect = { 1,2 };
    output = twoSumII(nums.data(), (int)nums.size(), target, &rSize);
    COMPARRAY(expect.data(), expect.size(), output, rSize);
    FREEMEM(output);

    nums = { 3,3 };
    target = 6;
    expect = { 1,2 };
    output = twoSumII(nums.data(), (int)nums.size(), target, &rSize);
    COMPARRAY(expect.data(), expect.size(), output, rSize);
    FREEMEM(output);
}

void TestCase_217()
{
    int nums[4] = {1,2,3,1};
    containsDuplicate(nums, 4);
}
void TestCase_766()
{
    int matrix[3][4] = { {1, 2, 3, 4}, {5, 1, 2, 3}, {9, 5, 1, 2 } };
    int** p;
    bool expect = true;
    bool output;
    int col = 4;

    p = (int**)malloc(sizeof(int*) * 3);
    for (int i = 0; i < 3; i++) {
        p[i] = (int*)malloc(sizeof(int) * 4);
        for (int j = 0; j < 4; j++) {
            p[i][j] = matrix[i][j];
        }
    }

    output = isToeplitzMatrix(p, 3, &col);
    COMPVALUE(expect, output);
};

void TestCase_189()
{
    vector<int> nums;

    nums = { 1,2,3,4,5,6,7 };
    COUTARRAY(nums.data(), (int)nums.size());
    rotate(nums.data(), (int)nums.size(), 3);
    COUTARRAY(nums.data(), (int)nums.size());

    nums = { -1, -100, 3, 99 };
    COUTARRAY(nums.data(), (int)nums.size());
    rotate(nums.data(), (int)nums.size(), 2);
    COUTARRAY(nums.data(), (int)nums.size());
}
void TestCase_392()
{
    string s, t;
    bool expect;
    bool output;

    s = "abc";
    t = "ahbgdc";
    expect = true;
    output = isSubsequence(&*s.begin(), &*t.begin());
    COMPVALUE(expect, output);
}

void TestCase_205()
{
    string s, t;
    bool expect;
    bool output;

    s = "egg";
    t = "add";
    expect = true;
    output = isIsomorphic(&*s.begin(), &*t.begin());
    COMPVALUE(expect, output);
}

void TestCase_724()
{
    vector<int> nums;
    int expect;
    int output;

    nums = { 1,7,3,6,5,6 };
    expect = 3;
    output = pivotIndex(nums.data(), (int)nums.size());
    COMPVALUE(expect, output);

    nums = { 1,2,3 };
    expect = -1;
    output = pivotIndex(nums.data(), (int)nums.size());
    COMPVALUE(expect, output);

    nums = { 2,1,-1 };
    expect = 0;
    output = pivotIndex(nums.data(), (int)nums.size());
    COMPVALUE(expect, output);
}
void TestCase_1480()
{
    vector<int> nums;
    vector<int> expect;
    int* output;
    int  retrunsize = 0;

    nums = { 1,2,3,4 };
    expect = { 1,3,6,10 };
    output = runningSum(nums.data(), (int)nums.size(), &retrunsize);
    COMPARRAY(expect.data(), expect.size(), output, retrunsize);
    FREEMEM(output);
}

void TestCase_1047()
{
    string s;
    string expect;
    char* output;

    s = "abbaca";
    expect = "ca";
    output = removeDuplicates(&*s.begin());
    cout << "expect:" << expect << endl;
    cout << "output:" << output << endl;
    FREEMEM(output);

    s = "azxxzy";
    expect = "ay";
    output = removeDuplicates(&*s.begin());
    cout << "expect:" << expect << endl;
    cout << "output:" << output << endl;
    FREEMEM(output);
}
void TestCase_523()
{
    vector<int> nums;
    int k;
    bool expect;

    nums = { 1,0 };
    k = 2;
    expect = false;
    COMPVALUE(expect, checkSubarraySum(nums.data(), (int)nums.size(), k));

    nums = { 5,0,0,0 };
    k = 3;
    expect = true;
    COMPVALUE(expect, checkSubarraySum(nums.data(), (int)nums.size(), k));

    nums = { 23, 2, 4, 6, 6 };
    k = 7;
    expect = true;
    COMPVALUE(expect, checkSubarraySum(nums.data(), (int)nums.size(), k));

    nums = { 23,2,4,6,7 };
    k = 6;
    expect = true;
    COMPVALUE(expect, checkSubarraySum(nums.data(), (int)nums.size(), k));

    nums = { 23,2,6,4,7 };
    k = 6;
    expect = true;
    COMPVALUE(expect, checkSubarraySum(nums.data(), (int)nums.size(), k));

    nums = { 23,2,6,4,7 };
    k = 13;
    expect = false;
    COMPVALUE(expect, checkSubarraySum(nums.data(), (int)nums.size(), k));
}

void TestCase_142()
{
    cout << "detectCycle" << endl;
}

void TestCase_1662()
{
    char word1[2][4] = { "ab", "c" };
    char word2[2][4] = { "a", "bc" };
    arrayStringsAreEqual((char**)word1, 2, (char**)word2, 2);
}

void TestCase_160()
{
    vector<int> nums1, nums2;
    
    ListNode* output = NULL;

    nums1 = { 4,1,8,4,5 };
    nums2 = { 5,6,1,8,4,5 };
    struct ListNode* headA = CreateListNode(nums1);
    struct ListNode* headB = CreateListNode(nums2);
    output = getIntersectionNode(headA, headB);
}

void TestCase_28()
{
    string haystack, needle;
    int expect;

    haystack = "sadbutsad", needle = "sad";
    expect = 0;
    COMPVALUE(expect, strStr(&*haystack.begin(), &*needle.begin()));

    haystack = "leetcode", needle = "leeto";
    expect = -1;
    COMPVALUE(expect, strStr(&*haystack.begin(), &*needle.begin()));
}

void TestCase_1239()
{
    vector<string> arr ;
    int expect;

    arr = { "un","iq","ue" };
    expect = 4;
    COMPVALUE(expect, maxLength((char**)&arr[0][0], (int)arr.size()));

    arr = { "cha","r","act","ers" };
    expect = 6;
    COMPVALUE(expect, maxLength((char**)&arr[0], (int)arr.size()));

    arr = { "abcdefghijklmnopqrstuvwxyz" };
    expect = 26;
    COMPVALUE(expect, maxLength((char**)&arr[0], (int)arr.size()));
}

void TestCase_1832()
{
    string s;
    bool expect;

    s = "thequickbrownfoxjumpsoverthelazydog";
    expect = true;
    COMPVALUE(expect, checkIfPangram(&*s.begin()));

    s = "leetcode";
    expect = false;
    COMPVALUE(expect, checkIfPangram(&*s.begin()));
}

void TestCase_8058()
{
    string s, expect;

    s = "abcdefg";
    expect = "cdefgab";
    cout << "expect:" << expect << endl;
    cout << "output:" << reverseLeftWords(s, 2) << endl;

    s = "lrloseumgh";
    expect = "umghlrlose";
    cout << "expect:" << expect << endl;
    cout << "output:" << reverseLeftWords(s, 6) << endl;
}

void TestCase_151()
{
    string s;
    string expect;
    char* output;

    s = "the sky is blue";
    expect = "blue is sky the";
    output = reverseWords((&*s.begin()));
    COMPARRAY((&*expect.begin()), expect.length(), output, strlen(output));
    FREEMEM(output);

    s = "  hello world  ";
    expect = "world hello";
    output = reverseWords((&*s.begin()));
    COMPARRAY((&*expect.begin()), expect.length(), output, strlen(output));
    FREEMEM(output);

    s = "a good   example";
    expect = "example good a";
    output = reverseWords((&*s.begin()));
    COMPARRAY((&*expect.begin()), expect.length(), output, strlen(output));
    FREEMEM(output);
}

void TestCase_541()
{
    string s;
    string expect;

    s = "abcdefg";
    expect = "bacdfeg";

    reverseStr((&*s.begin()), 2);
    COMPARRAY((&*expect.begin()), expect.length(), (&*s.begin()), s.length());

    s = "abcd";
    expect = "bacd";
    reverseStr((&*s.begin()), 2);
    COMPARRAY((&*expect.begin()), expect.length(), (&*s.begin()), s.length());
}

void TestCase_344()
{
    string s;

    s = "hello";
    COUTARRAY((&*s.begin()), s.length());
    reverseString(&*s.begin(), (int)s.length());
    COUTARRAY((&*s.begin()), s.length());
}

void TestCase_1()
{
    vector<int> nums;
    int target;
    vector<int> expect;
    int rSize;
    int* output;

    nums = { 2,7,11,15 };
    target = 9;
    expect = { 0,1 };
    output = twoSum(nums.data(), (int)nums.size(), target, &rSize);
    COMPARRAY(expect.data(), expect.size(), output, rSize);
    FREEMEM(output);

    nums = { 3,2,4};
    target = 6;
    expect = { 1,2 };
    output = twoSum(nums.data(), (int)nums.size(), target, &rSize);
    COMPARRAY(expect.data(), expect.size(), output, rSize);
    FREEMEM(output);

    nums = { 3,3 };
    target = 6;
    expect = { 0, 1};
    output = twoSum(nums.data(), (int)nums.size(), target, &rSize);
    COMPARRAY(expect.data(), expect.size(), output, rSize);
    FREEMEM(output);
}

void TestCase_202()
{
    bool expect;
    int num;

    num = 19;
    expect = true;
    COMPVALUE(expect, isHappy(num));

    num = 2;
    expect = false;
    COMPVALUE(expect, isHappy(num));
}

void TestCase_350()
{
    vector<int> nums1;
    vector<int> nums2;
    int* output = NULL;
    vector<int> expect;
    int returnsize = 0;

    nums1 = { 1,2,2,1 }, nums2 = { 2,2 };
    expect = { 2,2  };
    output = intersect(nums1.data(), (int)nums1.size(), nums2.data(), (int)nums2.size(), &returnsize);
    COMPARRAY(expect.data(), expect.size(), output, returnsize);
    free(output);

    nums1 = { 4,9,5 }, nums2 = { 9,4,9,8,4 };
    expect = { 9 ,4 };
    output = intersect(nums1.data(), (int)nums1.size(), nums2.data(), (int)nums2.size(), &returnsize);
    COMPARRAY(expect.data(), expect.size(), output, returnsize);
    free(output);
}

void TestCase_349()
{
    vector<int> nums1;
    vector<int> nums2;
    int* output = NULL;
    vector<int> expect;
    int returnsize = 0;

    nums1 = { 1,2,2,1 }, nums2 = { 2,2 };
    expect = { 2 };
    output = intersection(nums1.data(), (int)nums1.size(), nums2.data(), (int)nums2.size(), &returnsize);
    COMPARRAY(expect.data(), expect.size(), output, returnsize);
    free(output);

    nums1 = { 4,9,5 }, nums2 = { 9,4,9,8,4 };
    expect = { 9 ,4 };
    output = intersection(nums1.data(), (int)nums1.size(), nums2.data(), (int)nums2.size(), &returnsize);
    COMPARRAY(expect.data(), expect.size(), output, returnsize);
    free(output);
}

void TestCase_49()
{
    string s, t;
    bool expect;

    s = "a";
    t = "b";
    expect = false;
    COMPVALUE(expect, canConstruct(&*s.begin(), &*t.begin()));

    s = "aa";
    t = "ab";
    expect = false;
    COMPVALUE(expect, canConstruct(&*s.begin(), &*t.begin()));

    s = "aa";
    t = "aab";
    expect = true;
    COMPVALUE(expect, canConstruct(&*s.begin(), &*t.begin()));
}

void TestCase_383()
{
    string s, t;
    bool expect;

    s = "a";
    t = "b";
    expect = false;
    COMPVALUE(expect, canConstruct(&*s.begin(), &*t.begin()));

    s = "aa";
    t = "ab";
    expect = false;
    COMPVALUE(expect, canConstruct(&*s.begin(), &*t.begin()));

    s = "aa";
    t = "aab";
    expect = true;
    COMPVALUE(expect, canConstruct(&*s.begin(), &*t.begin()));
}

void TestCase_242()
{
    string s, t;
    bool expect;

    s = "anagram";
    t = "nagaram";
    expect = true;
    COMPVALUE(expect, isAnagram(&*s.begin(), &*t.begin()));

    s = "rat";
    t = "cat";
    expect = false;
    COMPVALUE(expect, isAnagram(&*s.begin(), &*t.begin()));
}


void TestCase_20()
{
    string s;
    bool expect;

    s = "()";
    expect = true;
    COMPVALUE(expect, isValid(&*s.begin()));

    s = "()[]{}";
    expect = true;
    COMPVALUE(expect, isValid(&*s.begin()));

    s="(]";
    expect = false;
    COMPVALUE(expect, isValid(&*s.begin()));
}

void TestCase_19()
{
    vector<int> nums = { 1,2,3,4,5 };
    ListNode* output = NULL;

    struct ListNode* head = CreateListNode(nums);
    output = removeNthFromEnd(head, 2);

    nums = { 1 };
    head = CreateListNode(nums);
    output = removeNthFromEnd(head, 1);
}

void TestCase_24()
{
    vector<int> nums = { 1,2,3,4 };
    ListNode* output = NULL;

    struct ListNode* head = CreateListNode(nums);
    output = swapPairs(head);

    nums = { 1 };
    head = CreateListNode(nums);
    output = swapPairs(head);
}


void TestCase_206()
{
    vector<int> nums = { 1,2,3,4,5 };
    ListNode* output = NULL;

    struct ListNode* head = CreateListNode(nums);
    output = reverseList(head);
}

void TestCase_707()
{
    int index = 1;
    int val = 0;
    int param;
    MyLinkedList* obj = myLinkedListCreate();

    myLinkedListAddAtHead(obj, 3);
    myLinkedListAddAtHead(obj, 1);

    myLinkedListAddAtTail(obj, 4);

    myLinkedListAddAtIndex(obj, 1, 2);

    param = myLinkedListGet(obj, 1);

    myLinkedListDeleteAtIndex(obj, 1);

    param = myLinkedListGet(obj, 1);

    myLinkedListFree(obj);
}

void TestCase_203()
{
    vector<int> nums = { 1,2,6,3,4,5,6 };
    int target = 6;
    struct ListNode* output = NULL;

    struct ListNode* head = CreateListNode(nums);
    output = removeElements(head, target);
}

void TestCase_76()
{
    char* output;

    char s0[] = "ADOBECODEBANC";
    char t0[] = "ABC";
    char expect0[] = "BANC";
    output = minWindow(s0, t0);
    COMPSTRING(expect0, output);
    //FREEMEM(output);

    char s1[] = "a";
    char t1[] = "a";
    char expect1[] = "a";
    output = minWindow(s1, t1);
    COMPSTRING(expect1, output);
    //FREEMEM(output);


    char s2[] = "a";
    char t2[] = "aa";
    char expect2[] = "";
    output = minWindow(s2, t2);
    COMPSTRING(expect2, output);
    //FREEMEM(output);
}

void TestCase_904()
{
    vector<int> nums;
    int expect;

    nums = { 0, 1, 6, 6, 4, 4, 6 };
    expect = 5;
    COMPVALUE(expect, totalFruit(nums.data(), (int)nums.size()));

    nums = { 1, 0, 1, 4, 1, 4, 1, 2, 3 };
    expect = 5;
    COMPVALUE(expect, totalFruit(nums.data(), (int)nums.size()));

    nums = { 3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4 };
    expect = 5;
    COMPVALUE(expect, totalFruit(nums.data(), (int)nums.size()));

    nums = { 1,2,1 };
    expect = 3;
    COMPVALUE(expect, totalFruit(nums.data(), (int)nums.size()));

    nums = { 0,1,2,2 };
    expect = 3;
    COMPVALUE(expect, totalFruit(nums.data(), (int)nums.size()));

    nums = { 1,2,3,2,2 };
    expect = 4;
    COMPVALUE(expect, totalFruit(nums.data(), (int)nums.size()));
}

void TestCase_209()
{
    vector<int> nums;
    int target;
    int expect;

    nums = { 2,3,1,2,4,3 };
    target = 7;
    expect = 2;
    COMPVALUE(expect, minSubArrayLen(target, nums.data(), (int)nums.size()));

    nums = { 1,4,4 };
    target = 4;
    expect = 1;
    COMPVALUE(expect, minSubArrayLen(target, nums.data(), (int)nums.size()));

    nums = { 1,1,1,1,1,1,1,1 };
    target = 11;
    expect = 0;
    COMPVALUE(expect, minSubArrayLen(target, nums.data(), (int)nums.size()));
}

void TestCase_977()
{
    vector<int> nums;
    vector<int> expect;
    int * output;
    int retsize = 0;

    nums = { -4,-1,0,3,10 };
    expect = { 0,1,9,16,100 };
    COUTARRAY(expect.data(), expect.size());
    output = sortedSquares(nums.data(), (int)nums.size(), &retsize);
    COUTARRAY(output, retsize);
    FREEMEM(output);

    nums = { -7,-3,2,3,11 };
    expect = { 4,9,9,49,121 };
    COUTARRAY(expect.data(), expect.size());
    output = sortedSquares(nums.data(), (int)nums.size(), &retsize);
    COUTARRAY(output, retsize);
    FREEMEM(output);
}

void TestCase_844()
{
    bool expect;
        
    char s0[] = "rheyggodcclgstf";
    char t0[] = "#rheyggodcclgstf";
    expect = true;
    COMPVALUE(expect, backspaceCompare(s0, t0));

    char s1[] = "ab#c";
    char t1[] = "ad#c";
    expect = true;
    COMPVALUE(expect, backspaceCompare(s1, t1));

    char s2[] = "ab##";
    char t2[] = "c#d#";
    expect = true;
    COMPVALUE(expect, backspaceCompare(s2, t2));

    char s3[] = "a#c";
    char t3[] = "b";
    expect = false;
    COMPVALUE(expect, backspaceCompare(s3, t3));
}

void TestCase_283()
{
    vector<int> nums;

    nums = { 0,1,0,3,12 };
    COUTARRAY(nums.data(), nums.size());
    moveZeroes(nums.data(), (int)nums.size());
    COUTARRAY(nums.data(), nums.size());

    nums = { 0 };
    COUTARRAY(nums.data(), nums.size());
    moveZeroes(nums.data(), (int)nums.size());
    COUTARRAY(nums.data(), nums.size());
}

void TestCase_26()
{
    vector<int> nums;
    int expect;

    nums = { 1,1,2 };
    expect = 2;
    COMPVALUE(expect, removeDuplicates(nums.data(), (int)nums.size()));

    nums = { 1 };
    expect = 1;
    COMPVALUE(expect, removeDuplicates(nums.data(), (int)nums.size()));

    nums = { 0,0,1,1,1,2,2,3,3,4 };
    expect = 5;
    COMPVALUE(expect, removeDuplicates(nums.data(), (int)nums.size()));
}

void TestCase_27()
{
    vector<int> nums;
    int value;
    int expect;

    nums = { 3,2,2,3 };
    value = 3;
    expect = 2;
    COMPVALUE(expect, removeElement(nums.data(), (int)nums.size(), value));

    nums = { 0, 1, 2, 2, 3, 0, 4, 2 };
    value = 2;
    expect = 5;
    COMPVALUE(expect, removeElement(nums.data(), (int)nums.size(), value));
}

void TestCase_367()
{
    COMPVALUE(true, isPerfectSquare(1));
    COMPVALUE(true, isPerfectSquare(16));
    COMPVALUE(false, isPerfectSquare(14));
}

void TestCase_69()
{
    COMPVALUE(6, mySqrt(36));
    COMPVALUE(1, mySqrt(1));
    COMPVALUE(1, mySqrt(3));
    COMPVALUE(2, mySqrt(8));
    COMPVALUE(2, mySqrt(4));
}

void TestCase_35()
{
    vector<int> nums;
    int target;
    int expect;

    nums = { 1,3,5,6 };
    target = 5;
    expect = 2;
    COMPVALUE(expect, searchInsert(nums.data(), (int)nums.size(), target));

    nums = { 1,3,5,6 };
    target = 2;
    expect = 1;
    COMPVALUE(expect, searchInsert(nums.data(), (int)nums.size(), target));

    nums = { 1,3,5,6 };
    target = 7;
    expect = 4;
    COMPVALUE(expect, searchInsert(nums.data(), (int)nums.size(), target));
}

void TestCase_34()
{
    vector<int> nums;
    int target;
    vector<int> expect;
    int* output;
    int retsize = 0;

    nums = { 5,7,7,8,8,10 };
    target = 8;
    expect = { 3, 4 };
    output = searchRange(nums.data(), (int)nums.size(), target, &retsize);
    COMPARRAY(expect.data(), (int)expect.size(), output, retsize);
    FREEMEM(output);

    nums = { 5,7,7,8,8,10 };
    target = 6;
    expect = { -1, -1 };
    output = searchRange(nums.data(), (int)nums.size(), target, &retsize);
    COMPARRAY(expect.data(), (int)expect.size(), output, retsize);
    FREEMEM(output);

    nums = {  };
    target = 0;
    expect = { -1, -1 };
    output = searchRange(nums.data(), (int)nums.size(), target, &retsize);
    COMPARRAY(expect.data(), (int)expect.size(), output, retsize);
    FREEMEM(output);
}

void TestCase_704()
{
    vector<int> nums;
    int target;
    int expect;

    nums = { -1, 0, 3, 5, 9, 12 };
    target = 9;
    expect = 4;
    COMPVALUE(expect, search(nums.data(), (int)nums.size(), target));

    nums = { -1,0,3,5,9,12 };
    target = 2;
    expect = -1;
    COMPVALUE(expect, search(nums.data(), (int)nums.size(), target));
}


funcTest getFuncTestPointer(int caseno)
{
    for (int i = 0; i < sizeof(g_tFuncName) / sizeof(FUNCNAME); i++)
    {
        if (g_tFuncName[i].caseno == caseno)
            return g_tFuncName[i].funcName;
    }

    return NULL;
}

//#define CallCase(num) TestCase_##num()

void TestCase(unsigned int caseno)
{
    cout << "Run TestCase: " << caseno << "." << endl;
    funcTest func;
    func = getFuncTestPointer(caseno);
    if (!func) {
        cout << "Problem " << caseno << " to be continue..." << endl;
        return;
    }

    func();
}

