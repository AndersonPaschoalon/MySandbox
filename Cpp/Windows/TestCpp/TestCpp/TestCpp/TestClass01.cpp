#include "TestClass01.h"
#include <fstream>
#include <iostream>

void TestClass01::overwriteFile(const char* content)
{
    std::ofstream myfile;
    myfile.open("cardCount.txt");
    myfile << content;
    myfile.close();
}

void TestClass01::incrementFile()
{
    const char fileName[] = "cardCount.txt";
    std::ofstream fileHandlerW;
    // if do not exist, create
    if (!fileExists(fileName))
    {
        fileHandlerW.open(fileName);
        fileHandlerW << "0" << std::endl;
        fileHandlerW.close();
    }
    // read file
    std::ifstream fileHandlerR(fileName);
    std::string fileContent((std::istreambuf_iterator<char>(fileHandlerR)), std::istreambuf_iterator<char>());
    // increment file content
    int fileVal = atoi(fileContent.c_str());
    if (fileVal > 999999)
    {
        fileVal = 0;
    }
    else
    {
        fileVal++;
    }
    // Update file
    fileHandlerW.open(fileName);
    fileHandlerW << fileVal;
    fileHandlerW.close();
}

bool TestClass01::fileExists(const char* filename)
{
    if (FILE* file = fopen(filename, "r")) 
    {
        fclose(file);
        return true;
    }
    else 
    {
        return false;
    }
}

void TestClass01::test_overwriteFile()
{
    overwriteFile("content01");
    overwriteFile("content02");
    overwriteFile("content03");
}
