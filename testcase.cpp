#include "testcase.h"

#define CallCase(num) TestCase_##num()

void TestCase(unsigned int caseno)
{
    cout << "Run TestCase: " << caseno << "." << endl;
    switch (caseno)
    {
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
    case 367:
        CallCase(367);
        break;
    case 704:
        CallCase(704);
        break;
    default:
        cout << "Problem " << caseno << " to be continue..." << endl;
    }
}

void TestCase_27()
{
    vector<int> nums;
    int value;
    int expect;

    nums = { 3,2,2,3 };
    value = 3;
    expect = 2;
    COMPVALUE(expect, removeElement(nums.data(), nums.size(), value));

    nums = { 0, 1, 2, 2, 3, 0, 4, 2 };
    value = 2;
    expect = 5;
    COMPVALUE(expect, removeElement(nums.data(), nums.size(), value));
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
    COMPVALUE(expect, searchInsert(nums.data(), nums.size(), target));

    nums = { 1,3,5,6 };
    target = 2;
    expect = 1;
    COMPVALUE(expect, searchInsert(nums.data(), nums.size(), target));

    nums = { 1,3,5,6 };
    target = 7;
    expect = 4;
    COMPVALUE(expect, searchInsert(nums.data(), nums.size(), target));
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
    output = searchRange(nums.data(), nums.size(), target, &retsize);
    COMPARRAY(expect.data(), (int)expect.size(), output, retsize);
    free(output);

    nums = { 5,7,7,8,8,10 };
    target = 6;
    expect = { -1, -1 };
    output = searchRange(nums.data(), nums.size(), target, &retsize);
    COMPARRAY(expect.data(), (int)expect.size(), output, retsize);
    free(output);

    nums = {  };
    target = 0;
    expect = { -1, -1 };
    output = searchRange(nums.data(), nums.size(), target, &retsize);
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
    COMPVALUE(expect, search(nums.data(), nums.size(), target));

    nums = { -1,0,3,5,9,12 };
    target = 2;
    expect = -1;
    COMPVALUE(expect, search(nums.data(), nums.size(), target));
}



