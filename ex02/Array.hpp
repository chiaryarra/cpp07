#pragma once

#include <iostream>
#include <exception>

template <typename T>
class Array
{
private:
    T* _array;
    unsigned int _size;
public:
    // Standard constructor
    Array() : _array(NULL), _size(0) {}
    // Constructor with _size
    Array(unsigned int n) : _array(new T[n]()), _size(n) {}
    // Copy constructor
    Array(const Array& copy) : _array(NULL), _size (0)
    {
        *this = copy;
    }
    // Copy assignement operator
    Array& operator=(const Array& copy) 
    {
        if (this != &copy)
        {
            delete[] this->_array;
            this->_size = copy._size;
            this->_array = new T[this->_size];
            for (unsigned int i = 0; i < this->_size; i++)
                this->_array[i] = copy._array[i];
        }
        return (*this);
    }
    // Destructor
    ~Array() 
    {
        delete[] this->_array;
    }
    // Index access operator
    T& operator[](unsigned int index)
    {
        if (index >= this->_size)
            throw std::out_of_range("Index out of range");
        return (this->_array[index]);
    }
    // Const version of index access operator
    const T& operator[](unsigned int index) const
    {
        if (index >= this->_size)
            throw std::out_of_range("Index out of range");
        return (this->_array[index]);
    }
    // Size member function
    unsigned int size() const
    {
        return (this->_size);
    }
};
