#include "parser.h"

#ifdef _WIN64

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

std::string parseToken(std::string in)
{
    char *token = strtok(&in[0], ":");

    while (in != "end.")
    {
        token++;

        token = strtok(&in[0], ":");
    }

    std::string res(token);

    return res;
}

#endif 

