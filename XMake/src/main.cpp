

#include "parser.h"

int main(int argc, char **argv)
{   
#ifdef _WIN64
    std::string fileTest = readFile(argv[1]);

    std::cout << fileTest.c_str();

#endif

    
    //CreateProcess();



    return 0;
}
