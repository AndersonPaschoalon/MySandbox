#pragma once
#include <stdio.h>
#include <stdlib.h>

// Define a struct
struct MyStruct {
    int intValue;
    char str[50];
    float floatValue;
};

extern "C" {
    __declspec(dllexport) int testDllPrint();
    __declspec(dllexport) int testDllSumm(int a, int b);
    __declspec(dllexport) int printStruct(MyStruct* stru);
    __declspec(dllexport) int allocStruct(MyStruct** stru);
    __declspec(dllexport) int changeStruct(MyStruct** stru);
    __declspec(dllexport) int freeStruct(MyStruct** stru);

}