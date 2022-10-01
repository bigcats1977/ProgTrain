#include "testcase.h"

void TestCase_704()
{
    vector<int> nums;
    int target;
    int output;

    nums = { -1, 0, 3, 5, 9, 12 };
    target = 9;
    output = 4;
    COMPVALUE(output, search(nums.data(), nums.size(), target));

    nums = { -1,0,3,5,9,12 };
    target = 2;
    output = -1;
    COMPVALUE(output, search(nums.data(), nums.size(), target));
}


#define CallCase(num) TestCase_##num()

void TestCase(unsigned int caseno)
{
    cout << "Run TestCase: " << caseno << "." << endl;
    switch (caseno)
    {
    case 704:
        CallCase(704);
        break;
    default:
        cout << "Problem " << caseno << " to be continue..." << endl;
    }
}

