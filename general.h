#pragma once

#include <iostream>
#include <vector>

using namespace std;

#define COMPVALUE(exp, out)     {                                               \
    if((exp) == (out)) cout << "TestCase PASS!" << endl;                        \
    else cout << "Test Fail!! Expect is " << exp << ", out is " << out << endl;   \
}
