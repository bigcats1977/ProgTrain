#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;


typedef void(*funcTest)();
typedef struct {
    int caseno;
    funcTest funcName;
}FUNCNAME;

typedef struct ListNode {
    int val;
    struct ListNode* next;
}ListNode;

ListNode* CreateListNode(vector<int> nums);

void quicksort(int* nums, int low, int high);


#define COMPVALUE(exp, out)     {                                               \
    cout << "Expect result: " << exp << endl;                                   \
    cout << "Output result: " << out << endl;                                   \
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
    cout << "expect result: ";                                                  \
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
    cout << "expect result: ";                                                  \
    COUTARRAY(exp, expnum);                                                     \
    cout << "output result: ";                                                  \
    COUTARRAY(out, outnum);                                                     \
}