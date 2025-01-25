#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <numeric>

using namespace std;


typedef void(*funcTest)();
typedef struct {
    int caseno;
    funcTest funcName;
}FUNCNAME;


struct node {
    int value;
    struct node* next;
};
struct TNode {
    int value;
    struct TNode* left;
    struct TNode* right;
};
typedef struct ListNode {
    int val;
    struct ListNode* next;
}ListNode;

// * * Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
 

struct NNode {
    int val;
    int numChildren;
    struct NNode** children;
};

struct Node {
    int val;
    struct Node* left;
    struct Node* right;
    struct Node* next;
};

struct RNode {
    int val;
    struct RNode* next;
    struct RNode* random;
};
struct GNode {
    int val;
    vector<GNode*> neighbors;
    GNode() { val = 0, neighbors = vector<GNode*>(); }
    GNode(int _val) { val = _val, neighbors = vector<GNode*>(); }
};

ListNode* CreateListNode(vector<int> nums);

TreeNode* CreateBinaryTree(vector<int> nums, int invalidval=-1);

void swap(int* val1, int* val2);
void quicksort(int* nums, int left, int right);

int** matrix2addr(vector<vector<int>> matrix);
int gcd(int a, int b);


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