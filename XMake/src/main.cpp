

#include "parser.h"

int main(int argc, char **argv)
{   
#ifdef _WIN64
    std::string fileTest = readFile(argv[1]);

    //std::cout << fileTest.c_str();

    std::string tokenfirst = parseToken(fileTest);

    while (tokenfirst != "end.")
    {

        tokenfirst = parseToken(fileTest);

        if (tokenfirst == "sln:")
        {
            continue;
        }
        else if(tokenfirst == "project:")
        {
            std::cout << "its project\n";
        }
        else if (tokenfirst == "name:")
        {
            std::cout << "its name\n";
        }

        std::cout << "Current token is: " << tokenfirst.c_str() << "\n";

    }

   



#endif

    
    //CreateProcess();



    return 0;
}
