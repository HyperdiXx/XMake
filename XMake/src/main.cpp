

#include "parser.h"
#include "string.h"

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

    printf("%d\n", b.find('r'));

    printf("%s\n", b.toStr());

    free(string);

}



int main(int argc, char **argv)
{   
#ifndef _DEBUG

    if (argc < 2)
    {
        fprintf(stdout, "Error while making. Enter config file name!!!");
        return 1;
    }

#endif // _RELEASE

 
#ifdef _WIN64

    stringTest();

    String fileTest = readFile("config.make");
    String tokenfirst = parseToken(&fileTest);
    
#endif

    return 0;
}
