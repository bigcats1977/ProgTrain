#include "testcase.h"
#include "MyLinkedList.h"

FUNCNAME g_tFuncName[] = {
    {1,     TestCase_1   },
    {19,    TestCase_19  },
    {20,    TestCase_20  },
    {24,    TestCase_24  },
    {26,    TestCase_26  },
    {27,    TestCase_27  },
    {34,    TestCase_34  },
    {35,    TestCase_35  },
    {69,    TestCase_69  },
    {49,    TestCase_49  },
    {76,    TestCase_76  },
    {202,   TestCase_202 },
    {203,   TestCase_203 },
    {206,   TestCase_206 },
    {209,   TestCase_209 },
    {242,   TestCase_242 },
    {283,   TestCase_283 },
    {349,   TestCase_349 },
    {350,   TestCase_350 },
    {367,   TestCase_367 },
    {383,   TestCase_383 },
    {704,   TestCase_704 },
    {707,   TestCase_707 },
    {844,   TestCase_844 },
    {904,   TestCase_904 },
    {977,   TestCase_977 },
};

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

