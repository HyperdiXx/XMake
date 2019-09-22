#include "string.h"

#include <iostream>

void String::reserveMemory(size_t n)
{
    if (capacity == 0 || n > capacity)
    {
        

    }

}

String::String(char symbol)
{
    allocateStr(1);
}

String::String(const char * str)
{
    int len = strlen(str);
    allocateString(str, len);
}

void String::allocateStr(size_t n)
{
    capacity = n;
    if (capacity < 8) 
        capacity = 8;
    
    if (data)
    {
        char *str = (char*)malloc(sizeof(capacity + 1));
        memcpy(str, data, length);
        memset(str, 0, capacity + 1);
        free(data);
        data = str;
    }
    else
    {
        data = (char*)malloc(capacity + 1);
        memset(data, 0, capacity + 1);
        length = 0;
    }
}

void String::allocateString(const char * d, size_t n)
{
    capacity = n;
    if (capacity < 8)
        capacity = 8;

    char *alloc = (char*)malloc(sizeof(capacity + 1));
    memset(alloc, 0, capacity + 1);
    strcpy(alloc, d);

    data = (char*)malloc(sizeof(1));
    free(data);
    data = alloc;
    length = n;
}

void String::resize(size_t n)
{
    if (n > length)
    {
        allocateStr(n);
        capacity += n;
    }
    else if(n < length)
    {
        memset(data + n, 0, length - n);
        length = n;
    }


}

void String::clear() noexcept
{
    if(length > 0)
    {
        memset(data, 0, length);
        length = 0;
    }
}

bool String::isFind(char symbol)
{
    for (size_t i = 0; i < length; i++)
        if (data[i] == symbol)
            return true;
    return false;
}

char String::find(char symbol)
{
    for (size_t i = 0; i < length; i++)
        if (data[i] == symbol)
            return i;
    return 0;
}

void String::freedata()
{
    if (data)
    {
        free(data);
        data = nullptr;
    }

    capacity = 0;
    length = 0;
}
