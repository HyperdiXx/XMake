#include "parser.h"


bool compare(const char* src, const char *val)
{
    if (strcmp(src, val) == 0)
        return true;
    else
        return false;
}

String readFile(const char* filename)
{
    FILE* fileToRead = fopen(filename, "r");

    if (fileToRead != nullptr)
    {
        fseek(fileToRead, 0, SEEK_END);
        unsigned long length = ftell(fileToRead);
        fseek(fileToRead, 0, SEEK_SET);
        char *ar = new char[length + 1];
        memset(ar, 0, length + 1);
        fread(ar, sizeof(char), length + 1, fileToRead);
        fclose(fileToRead);

        std::string res(ar);
        delete[] ar;
        return String(res.c_str());
    }

    return nullptr;
}

static
void eat_whitespaces(String *str)
{
    for (size_t i = 0; i < str->length;)
    {
        if (*str->data != ' ' && *str->data != '\n' && *str->data != '\r' && *str->data != '\t') \
            return;
        str->data++;
        str->length--;
    }
}

String parseToken(String* str)
{
    eat_whitespaces(str);
    
    String res = *str;
    
    for (size_t i = 0; i < str->length;)
    {
        if (*str->data == ' ' || *str->data == '\n' || *str->data == '\r' || *str->data == '\t')
        {
            eat_whitespaces(str);
            return res;
        }
        str->data++;
        str->length--;
        res.length++;
    }

    eat_whitespaces(str);

    return res;
}
