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

void TestClass01::test_ScriptCmd()
{
    std::string outVal;
    int retVal = 0;
   
    ScriptCmd scriptps1("runPs1.ps1", "", ScriptCmd::ShellType::POWER_SHELL);
    retVal = scriptps1.exec(outVal);
    printf("==>> %d\n", retVal);
    printf("==>> %s\n", outVal.c_str());
    std::cout << "scriptps1:" << scriptps1.toString() << std::endl;

    std::vector<std::string> listFiles;
    listFiles.clear();
    listFiles.push_back("file1");
    listFiles.push_back("file2");
    listFiles.push_back("file3");
    ScriptCmd scriptbat("runBat.bat");
    scriptbat.setGeneratedFiles(listFiles);
    retVal = scriptbat.execAndSave();
    printf("==>> %d\n", retVal);
    std::cout << "scriptbat.getStdoutFilename():" << scriptbat.getStdoutFilename() << std::endl;
    std::cout << "scriptbat:" << scriptbat.toString() << std::endl;
}
