#pragma once

#include <iostream>
#include <vector>

using namespace std;

#define COMPVALUE(exp, out)     {                                               \
    if((exp) == (out)) cout << "TestCase PASS!" << endl;                        \
    else cout << "Test Fail!! Expect is " << exp << ", out is " << out << endl; \
}

#define COUTARRAY(array, num)  {                                                \
    for(int kkk=0; kkk<num; kkk++)    {                                         \
        cout << array[kkk] <<" ";                                               \
    }                                                                           \
    cout<<endl;                                                                 \
}

#define COMPARRAY(exp, expnum, out, outnum) {                                   \
    cout << "expected result: ";                                                \
    COUTARRAY(exp, expnum);                                                     \
    cout << "output result: ";                                                  \
    COUTARRAY(out, outnum);                                                     \
}