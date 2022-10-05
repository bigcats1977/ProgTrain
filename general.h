#pragma once

#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define COMPVALUE(exp, out)     {                                               \
    cout << "Expect result: " << exp << ", output result: " << out << endl;     \
}

#define COUTSTRING(array)  {                                                    \
    if(array != NULL){                                                          \
        cout << array ;                                                         \
    }                                                                           \
    cout<<endl;                                                                 \
}

#define FREEMEM(addr)       {                                                   \
    if(addr != NULL)        {                                                   \
        free(addr); addr = NULL;                                                \
    }                                                                           \
}

#define COMPSTRING(exp, out) {                                                  \
    cout << "expected result: ";                                                \
    COUTSTRING(exp);                                                            \
    cout << "output result: ";                                                  \
    COUTSTRING(out);                                                            \
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