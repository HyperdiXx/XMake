#include "parser.h"

#ifdef _WIN64

bool compare(const char* src, const char *val)
{
    if (strcmp(src, val) == 0)
        return true;
    else
        return false;
}

std::string readFile(const char* filename)
{
    FILE* fileToRead = fopen(filename, "r");

    if (fileToRead != nullptr)
    {
        fseek(fileToRead, 0, SEEK_END);
        unsigned long length = ftell(fileToRead);
        fseek(fileToRead, 0, SEEK_SET);
        char *le = new char[length + 1];
        memset(le, 0, length + 1);
        fread(le, sizeof(char), length + 1, fileToRead);
        fclose(fileToRead);

        std::string res(le);
        delete[] le;
        return res;
    }

    return std::string("Error. Failed to open file!");
}

std::string parseToken(char* in)
{
    char *token = strtok(&in[0], ":");
    
    if (compare(token, "sln"))
    {
        printf("test!\n");
    }

    while (!compare(token, "end."))
    {
        
        if (compare(token, "project"))
        {
            std::cout << "its project\n";
        }
        token++;
    }

    while (token != "end.")
    {
        int res = strcmp(token, "sln");
        if (res == 0)
        {
            int a = 5;
            token = strtok(&in[0], ":");
        }
        else if(token == "project")
        {
            std::cout << "its project\n";
        }
        else if (token == "name")
        {
            std::cout << "its name\n";
        }

        std::cout << "Current token is: " << token << "\n";

    }

    std::string res(token);

    return res;
}

#endif 

