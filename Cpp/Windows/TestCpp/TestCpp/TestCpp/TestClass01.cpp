#include "TestClass01.h"
#include <fstream>
#include <iostream>
#include <chrono>
#include <thread>
#include <sstream>
#include <iomanip>

using namespace std::chrono_literals;

// exception example
#include <typeinfo>       // operator typeid
#include <exception>      // std::exception
class Polymorphic { virtual void member() {} };

std::string escapes[1024];
bool initEscapes = false;

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

void TestClass01::test_read_blocked_file()
{
    const char txtFile[] = "SampleText.txt";
    char buff[10000];
    FILE * fp1;
    FILE * fp2;
    FILE * fp3;
    memset(buff, '\0', sizeof(buff));

    // write some text in the file
    fp1 = fopen(txtFile, "w+");
    fprintf(fp1, "This is the first sample text\n");
    fclose(fp1);

    std::this_thread::sleep_for(2000ms);
    
    fp3 = fopen(txtFile, "a");
    fprintf(fp1, "This is the SECOND sample text\n");

    fp2 = fopen(txtFile, "r");
    while (fscanf(fp2, "%s", buff) != EOF)
    {
        printf("%s ", buff);
    }
    printf("\n");

    //fclose(fp1);
    fclose(fp2);
    fclose(fp3);

    printf("###################################################\n");
    printf("# END TEST\n");
    printf("###################################################\n");
    // write 

}

void TestClass01::test_exception()
{
    try
    {
        Polymorphic* pb = 0;
        typeid(*pb);  // throws a bad_typeid exception
    }
    catch (std::exception& e)
    {
        char err_str[2048];
        int err_int = 0;
        memset(err_str, '\0', 2048);
        strcpy(err_str, e.what());
        printf(">>%s<<", err_str);
    }

}


void TestClass01::test_scape_string()
{
    printf("=================================================\n");
    std::string str1 = "C:\\Users\\anderson_paschoalon\\Workspace";
    printf("raw - %s\n", str1.c_str());
    printf("scape_json - %s\n", TestClass01::json_escape(str1).c_str());

    printf("=================================================\n");
    str1 = "aaaaaaaaaaaaaaaaaaaaaa\n\n\nsssssss\r\f";
    printf("raw - %s\n", str1.c_str());
    printf("scape_json - %s\n", TestClass01::json_escape(str1).c_str());

    printf("=================================================\n");
    str1 = "Certificate/";
    printf("raw - %s\n", str1.c_str());
    printf("scape_json - %s\n", TestClass01::json_escape(str1).c_str());

    printf("=================================================\n");
    str1 = "Certificate\\";
    printf("raw - %s\n", str1.c_str());
    printf("scape_json - %s\n", TestClass01::json_escape(str1).c_str());

    printf("=================================================\n");
    str1 = "C:\\\\Users\\\\anderson_paschoalon\\\\Workspace";
    printf("raw - %s\n", str1.c_str());
    printf("scape_json - %s\n", TestClass01::json_escape(str1).c_str());



}

std::string TestClass01::json_escape(const std::string& s)
{
    std::ostringstream o;
    for (auto c = s.cbegin(); c != s.cend(); c++) {
        switch (*c) {
        case '"': o << "\\\""; break;
        case '\\': o << "\\\\"; break;
        case '\b': o << "\\b"; break;
        case '\f': o << "\\f"; break;
        case '\n': o << "\\n"; break;
        case '\r': o << "\\r"; break;
        case '\t': o << "\\t"; break;
        default:
            if ('\x00' <= *c && *c <= '\x1f') {
                o << "\\u"
                    << std::hex << std::setw(4) << std::setfill('0') << static_cast<int>(*c);
            }
            else {
                o << *c;
            }
        }
    }
    return o.str();

}


void TestClass01::initJsonEscape()
{
    // Escape all lower control characters (some get overridden with smaller sequences below)
    for (int ch = 0x00; ch < 0x20; ++ch) {
        char tmpbuf[20];
        snprintf(tmpbuf, sizeof(tmpbuf), "\\u%04x", ch);
        escapes[ch] = std::string(tmpbuf);
    }

    escapes[(int)'"'] = "\\\"";
    escapes[(int)'\\'] = "\\\\";
    escapes[(int)'\b'] = "\\b";
    escapes[(int)'\f'] = "\\f";
    escapes[(int)'\n'] = "\\n";
    escapes[(int)'\r'] = "\\r";
    escapes[(int)'\t'] = "\\t";
    escapes[(int)'\x7f'] = "\\u007f"; // U+007F DELETE

    initEscapes = true;
}


