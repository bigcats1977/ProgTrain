#pragma once

#include <iostream>
#include <vector>

using namespace std;

#define COMPVALUE(exp, out)     {                                               \
    cout << "Expect result: " << exp << ", output result: " << out << endl;     \
}

#define COUTARRAY(array, num)  {                                                \
    for(int kkk=0; kkk<(int)num; kkk++)    {                                    \
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