

#include "parser.h"


void stringTest()
{
    String a("hello");

    String b("world");

    printf("%d", b.find('r'));

    a.freedata();

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

    std::string fileTest = readFile("config.make");

    std::cout << fileTest.c_str(); 

    std::string tokenfirst = parseToken(&fileTest[0]);
    
    std::cout << tokenfirst.c_str() << "\n";

    

   



#endif

    
    //CreateProcess();



    return 0;
}
