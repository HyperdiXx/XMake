#pragma once

#ifndef STRING_H
#define STRING_H

#include <cstdlib>

#include "iterator.h"



class String
{
public:
    using iterator = Iterator<char>;
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
    void append(char symbol);
    String& append(const char *str);
    String& append(const String& str);

    bool isFind(char symbol);
    size_t find(char symbol);
    char find(size_t index);

    iterator begin() noexcept { return iterator(data); };
    iterator end() noexcept { return iterator(&data[length - 1]); };

    String operator+(char c) const;
    String operator+(const char* str) const;
    String operator+(const String& str) const;

    friend String operator+(char lhs, const String& rhs) { return String(lhs) + rhs; }
    friend String operator+(const char* lhs, const String& rhs) { return String(lhs) + rhs; }

    String& operator+=(char c) { return append(1, c); }
    String& operator+=(const char* str) { return append(str); }
    String& operator+=(const String& str) { return append(str); }

    const char* toStr() const noexcept { return data; }
private:
    char* data = nullptr;
    size_t capacity = 0;
    size_t length = 0;
    size_t curpos = 0;

    

};

#endif // !STRING_H

