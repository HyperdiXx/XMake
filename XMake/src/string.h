#pragma once

#ifndef STRING_H
#define STRING_H

#include <cstdlib>

class String
{
public:
    String() { allocateStr(8); };
    String(char symbol);
    String(const char *str);
    ~String() { freedata(); };

    void allocateStr(size_t n);
    void allocateString(const char* d, size_t n);
    void reserveMemory(size_t n);
    void resize(size_t n);
    void freedata();
    void clear() noexcept;

    bool isFind(char symbol);
    char find(char symbol);




private:
    char* data = nullptr;
    size_t capacity = 0;
    size_t length = 0;
};

#endif // !STRING_H

