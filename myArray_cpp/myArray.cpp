#include "myArray.h"

// template <typename T>
// MyArray<T>::MyArray()
MyArray::MyArray()
{
    capacity = 5;
    size = 0;
    // data = new T[capacity];
    data = new char[capacity];
    // memset(data, 0, sizeof(T) * capacity);
    memset(data, 0, sizeof(char) * capacity);
}

MyArray::MyArray(int tCapacity, char val)
{
    capacity = tCapacity;
    size = capacity;
    data = new char[capacity];
    memset(data, val, sizeof(char)*capacity);
}

// template <typename T>
// MyArray<T>::MyArray(const MyArray& arr)
MyArray::MyArray(const MyArray& arr)
{
    if(&arr == this)
    {
        return;
    }

//////////////////////////////////////////////////////////////
                    // if(data != NULL)
                    // {
                    //     delete[] data;
                    //     data = NULL;
                    // }
////////////////////////////////////////////////////////////////

    capacity = arr.capacity;
    size = arr.size;
    // data = new T[capacity];
    data = new char[capacity];
    // memcpy(data, arr.data, sizeof(T) * capacity);
    memcpy(data, arr.data, sizeof(char) * capacity);
}

// template <typename T>
// MyArray& MyArray<T>::operator=(MyArray& arr)
MyArray& MyArray::operator=(MyArray& arr)
{
    if(&arr == this)
    {
        return *this;
    }

    if(data != NULL)
    {
        delete[] data;
        data = NULL;
    }
    capacity = arr.capacity;
    size = arr.size;
    // data = new T[capacity];
    data = new char[capacity];
    // memcpy(data, arr.data, sizeof(T) * capacity);
    memcpy(data, arr.data, sizeof(char) * capacity);
    return *this;
}

char &MyArray::operator[](int pos)
{
    if(pos > size || pos < 0)
    {
        static char err = '0';
        return err;
    }

    if(pos == size)
    {
        if(capacity <= size)
        {
            capacity *= 2;
            char* newSpace = new char[capacity];
            memcpy(newSpace, data, sizeof(char) * size);
            delete[] data;
            data = newSpace;
        }
        ++size;
    }

    return data[pos];
}

// template <typename T>
// MyArray<T>::~MyArray()
MyArray::~MyArray()
{
    if(data != NULL)
    {
        delete[] data;
        data = NULL;
        capacity = 0;
        size = 0;
    }
}

void MyArray::PushFront(char val)
{
    if(size >= capacity)
    {
        capacity *= 2;
        char* newSpace = new char[capacity];
        memcpy(newSpace, data, sizeof(char) * size);
        delete[] data;
        data = newSpace;
    }
    for(int i = size - 1; i >= 0; --i)
    {
        data[i+1] = data[i];
    }
    data[0] = val;
    size++;
}

void MyArray::PushBack(char val)
{
    if(size >= capacity)
    {
        capacity *= 2;
        char* newSpace = new char[capacity];
        memcpy(newSpace, data, sizeof(char) * size);
        delete[] data;
        data = newSpace;
    }

    data[size++] = val;
}

void MyArray::PopFront()
{
    if(size == 0)
    {
        return;
    }

    for(int i = 0; i < size - 1; ++i)
    {
        data[i] = data[i+1];
    }

    --size;
}

void MyArray::PopBack()
{
    if(size == 0)
    {
        return;
    }
    --size;
}

int MyArray::Size()
{
    return size;
}

int MyArray::Capacity()
{
    return capacity;
}

void MyArray::Insert(char val, int pos)
{
    if(size >= capacity)
    {
        capacity *= 2;
        char* newSpace = new char[capacity];
        memcpy(newSpace, data, sizeof(char) * size);
        delete[] data;
        data = newSpace;
    }

    if(pos > size || pos < 0)
    {
        PushBack(val);
    }

    for(int i = size - 1; i >= pos; --i)
    {
        data[i+1] = data[i];
    }

    data[pos] = val;
    ++size;
}

char &MyArray::Get(int pos)
{
    return data[pos];
}

void MyArray::Set(int pos, char val)
{
    if(pos >= size || pos < 0)
    {
        return;
    }

    data[pos] = val;
}
