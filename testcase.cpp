#include "testcase.h"

#define CallCase(num) TestCase_##num()

void TestCase(unsigned int caseno)
{
    cout << "Run TestCase: " << caseno << "." << endl;
    switch (caseno)
    {
    case 26:
        CallCase(26);
        break;
    case 27:
        CallCase(27);
        break;
    case 34:
        CallCase(34);
        break;
    case 35:
        CallCase(35);
        break;
    case 69:
        CallCase(69);
        break;
    case 209:
        CallCase(209);
        break;
    case 283:
        CallCase(283);
        break;
    case 367:
        CallCase(367);
        break;
    case 704:
        CallCase(704);
        break;
    case 844:
        CallCase(844);
        break;
    case 977:
        CallCase(977);
        break;
    default:
        cout << "Problem " << caseno << " to be continue..." << endl;
    }
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
    free(output);

    nums = { -7,-3,2,3,11 };
    expect = { 4,9,9,49,121 };
    COUTARRAY(expect.data(), expect.size());
    output = sortedSquares(nums.data(), (int)nums.size(), &retsize);
    COUTARRAY(output, retsize);
    free(output);
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
    free(output);

    nums = { 5,7,7,8,8,10 };
    target = 6;
    expect = { -1, -1 };
    output = searchRange(nums.data(), (int)nums.size(), target, &retsize);
    COMPARRAY(expect.data(), (int)expect.size(), output, retsize);
    free(output);

    nums = {  };
    target = 0;
    expect = { -1, -1 };
    output = searchRange(nums.data(), (int)nums.size(), target, &retsize);
    COMPARRAY(expect.data(), (int)expect.size(), output, retsize);
    free(output);
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



