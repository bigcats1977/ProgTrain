// ProgTrain.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "testcase.h"

int main()
{
    int caseno = 0;
    do {
        printf("please input test case no(0 is exit):");
        scanf_s("%d", &caseno);
        if( caseno != 0)
            TestCase(caseno);
    } while (caseno != 0);
}