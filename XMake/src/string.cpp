#include "string.h"

#include <iostream>

void String::reserveMemory(size_t n)
{
    if (capacity == 0 || n > capacity)
    {
        capacity = n;
        if (capacity < 8)
            capacity += 8;
    }

}

String::String(char symbol)
{
    allocateStr(1);
}

String::String(const char * str)
{
    if (!data)
    {
        data = (char*)_aligned_malloc(1, sizeof(void*));
        __assume(data);
    }
    length = stringLength(str);
        
    allocateString(str);
}

String::String(const String & str)
{
    if (!data)
    {
        data = (char*)_aligned_malloc(1, sizeof(void*));
        __assume(data);
    }

    length = stringLength(str.toStr());

    allocateString(str.toStr());
}

/* Unused */
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

void String::allocateString(const char * d)
{
    capacity = length;
    if (capacity < 8)
        capacity = 8;

    char* str = (char*)_aligned_malloc(sizeof(capacity + 1), sizeof(void*));
    memset(str, 0, capacity + 1);
    memcpy(str, data, length);
    stringCopy(d, str);
    _aligned_free(data);
    data = str;
}


void String::strAlloc()
{
    data = (char*)malloc(sizeof(capacity + 1));
    //memset(data, 0, capacity + 1);
    length = 0;
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

inline size_t String::stringLength(const char * string)
{
    const char* str = string;

    while (*str != '\0')
    {
        str++;
    }

    return  (size_t)(str - string);
}

void String::stringCopy(const char * str1, char * str2)
{
    while(*str1 != 0)
    {
        const char character = *str1;
        *str2 = character;
        ++str2;
        ++str1;
    }
}

String& String::append(char symbol)
{
    if (length > 0)
    {
        size_t newLen = length + 1;
        if (newLen > capacity)
            capacity += 1;

        //memcpy(data + length, symbol, newLen);
    }

    return *this;
}

String& String::append(const char * str)
{
    if (length > 0)
    {
        size_t newLen = stringLength(str) + length;

        if (newLen > capacity)
            capacity += stringLength(str);

        memcpy(data + length, str, newLen);

        length = newLen;
    }    
    
    return *this;
}

String & String::append(const String & str)
{
    return append(str.toStr());
}

bool String::isFind(char symbol)
{
    for (size_t i = 0; i < length; i++)
        if (data[i] == symbol)
            return true;
    return false;
}

size_t String::find(char symbol)
{
    for (size_t i = 0; i < length; i++)
        if (data[i] == symbol)
            return i;
    return 0;
}

char String::find(size_t index)
{
    if (index >= 0 || index < length)
    {
        for (size_t i = 0; i < length; i++)
            if (i == index)
                return data[i];
    }

    return 'E';
}

size_t String::getLength() const
{
    return length;
}

size_t String::getCapacity() const
{
    return capacity;
}

void String::freeMem()
{ 
    if (data)
    {
        _aligned_free(data);
        data = nullptr;
    }

    capacity = 0;
    length = 0;
}
