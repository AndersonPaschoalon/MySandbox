#include "pch.h"
#include "CppDllTest.h"

int testDllPrint()
{
    printf("testDllPrint: printing from C++ code!\n");
    return 0;
}

int testDllSumm(int a, int b)
{
    int c = a + b;
    printf("testDllSumm a:%d + b: %d = c:%d\n", a, b, c);
    return c;
}

int printStruct(MyStruct* stru)
{
    printf("MyStruct\n");
    printf("\tstru->floatValue:%f\n", stru->floatValue);
    printf("\tstru->intValue:%d\n", stru->intValue);
    printf("\tstru->str:%s\n", stru->str);
    return 0;
}

int allocStruct(MyStruct** stru)
{
    // fill struct
    MyStruct* theStruct = (MyStruct*)malloc(sizeof(MyStruct));
    theStruct->floatValue = 3.14;
    theStruct->intValue = 10;
    memset(theStruct->str, '\0', sizeof(theStruct->str));
    strcpy(theStruct->str, "INITIAL STRING");

    // allocate the pointer to the struct in the heap
    // *stru = (MyStruct*)malloc(sizeof(MyStruct*));
    // "save" the allocated struct in the pointer
    (*stru) = theStruct;

    return 0;
}


int changeStruct(MyStruct** stru)
{
    (*stru)->floatValue = (*stru)->floatValue + 1;
    (*stru)->intValue  = (*stru)->intValue + 1;
    if (strcmp((*stru)->str, "INITIAL STRING") == 0)
    {
        memset((*stru)->str, '\0', sizeof((*stru)->str));
        strcpy((*stru)->str, "ANOTHER STRING");
    }
    else
    {
        memset((*stru)->str, '\0', sizeof((*stru)->str));
        strcpy((*stru)->str, "INITIAL STRING");
    }

    return 0;
}

int freeStruct(MyStruct** stru)
{
    free(*stru);
    (*stru) = nullptr;

    return 0;
}
