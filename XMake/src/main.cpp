


#include "parser.h"
#include "string.h"

#include <windows.h>

#ifdef _DEBUG
    #define DEBUG
#endif 

enum result_codes
{
    XMAKE_OK = 0,
    XMAKE_BUILD_FAILED = -1,
    XMAKE_ERROR_LOADING_CONFIG_FILE = -2,
    XMAKE_BAD_ARGS = -3,
    XMAKE_ALREADY_RUNNING = -4,
};

struct config
{
    const char* name;
    options opetions;
};

struct options
{

};


void stringTest()
{
    String a("hello");

    size_t length = String::stringLength(a.toStr());

    String b("world");

    String c(b);

    size_t size = b.getLength() + 1;

    char* string = (char*)malloc(size);
    memset(string, 0, size);
    String::stringCopy(b.toStr(), string);

    //b.append("Hello!!!");

    printf("%s\n", string);

    printf("%zd\n", b.find('r'));

    printf("%s\n", b.toStr());

    free(string);

}

String win_readFile(const char* path)
{
    String result;

    HANDLE file_handle = CreateFileA(path, GENERIC_READ, FILE_SHARE_READ, 0, OPEN_EXISTING, 0, 0);
    if (file_handle == INVALID_HANDLE_VALUE) {
        CloseHandle(file_handle);
        return result;
    }

    DWORD file_size = GetFileSize(file_handle, 0);
    result.length = file_size;
    result.data = (char*)VirtualAlloc(0, result.length, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

    DWORD bytes_read;
    if (ReadFile(file_handle, result.data, file_size, &bytes_read, 0) && file_size == bytes_read)
    {
        printf("!!!");
    }

    CloseHandle(file_handle);
    return result;
}

void print_version()
{
    printf("XMake.\nVersion %s", BUILD_VERSION);
}

void print_help()
{
    print_version();
}

void make_debug(config *cnf)
{

}

void make_release(config *cnf)
{

}

void build_config(const char* type)
{
    config cnf = {};
    if (strcmp(type, "debug"))
        make_debug(&cnf);
    else if (strcmp(type, "release"))
        make_release(&cnf);
        
}

void parse_args(int argc, char **argv)
{
    HANDLE consoleH = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO   csbi;
    WORD currentColor;
    GetConsoleScreenBufferInfo(consoleH, &csbi);
    currentColor = csbi.wAttributes;

    if (argc < 2)
    {
        SetConsoleTextAttribute(consoleH, FOREGROUND_RED);
        printf("Error while making. Enter config file name!!!");
        SetConsoleTextAttribute(consoleH, currentColor);
        exit(XMAKE_BUILD_FAILED);
    }


    for (int i = 0; i < argc; i++)
    {
        if (argv[i][0] == '-')
        {
            
        }
    }

}

int main(int argc, char **argv)
{   

#ifndef DEBUG

    parse_args(argc, argv);
    print_version();  

#endif 

#ifdef DEBUG

    stringTest();

    String configFile = win_readFile("config.make");
    //String tokenfirst = parseToken(&configFile);
    
    String name("name");
    String project("project");
    String test("name");
    //String ext("ext");
    //String config("config");
    //String platform("platform");
    
    if (String::stringCompare(&name, &test))
    {
        int a = 143214;
        int b = 43;
    }

    while (configFile.length)
    {
        String word = parseToken(&configFile);

        if (String::stringCompare(&word, &project))
        {
            printf("project");
        }

        if (String::stringCompare(&word, &name))
        {
            printf("name");
        }
    }

#endif

    return XMAKE_OK;
}
