#pragma once

#ifndef ITERATOR_H
#define ITERATOR_H

template <typename T>
struct Iterator
{
private:
    T* it;
public:

    Iterator(T* data) : it(data) {};

    Iterator& operator++() { it += 1; return *this; };
    Iterator& operator--() { it -= 1; return *this; };
    
    bool operator==(const Iterator& rhs) const { return it == rhs.it; }
    bool operator!=(const Iterator& rhs) const { return it != rhs.it; }
};

#endif // !ITERATOR_H

