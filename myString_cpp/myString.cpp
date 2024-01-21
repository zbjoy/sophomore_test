#include "myString.h"

MyString::MyString()
{
    this->size = 0;
    this->capacity = 1;
    this->data = new char[capacity];
    memset(data, 0, capacity);
}
MyString::MyString(const MyString& ms)
{
    this->capacity = ms.capacity;
    this->size = ms.size;
    this->data = new char[capacity];
    //memset(data, 0, capacity);
    memcpy(data, ms.data, capacity);
}
MyString::MyString(const char* str)
{
    this->capacity = strlen(str) + 1;
    this->size = strlen(str);
    this->data = new char[capacity];
    //memset(data, 0, capacity);
    memcpy(data, str, capacity);
}
MyString& MyString::operator=(const MyString& ms)
{
    if(&ms == this)
    {
        return *this;
    }

    if(data != NULL)
    {
        //char* newSpace = new char[ms.capacity];
        //memcpy(newSpace, ms.data, ms.capacity);
        delete[] data;
        data = NULL;
        //data = newSpace;
    }

    this->capacity = ms.capacity;
    this->size = ms.size;

    this->data = new char[capacity];
    //memset(data, 0, capacity);
    memcpy(data, ms.data, capacity);

    return *this;
}
MyString& MyString::operator=(const char* str)
{
    if(data != NULL)
    {
        delete[] data;
        data = NULL;
    }

    capacity = strlen(str) + 1;
    size = strlen(str);

    data = new char[capacity];
    memcpy(data, str, capacity);

    return *this;
}
MyString::~MyString()
{
    if(data != NULL)
    {
        delete[] data;
        data = NULL;
        capacity = 0;
        size = 0;
    }
}

MyString& MyString::operator+=(const MyString& ms)
{
    if(capacity <= size + ms.size)
    {
        char* newSpace = new char[size + ms.size + 1];
        this->capacity = size + ms.size + 1;
        memset(newSpace, 0, size + ms.size + 1);
        strcat(newSpace, data);
        //strcat(newSpace, ms.data);
        delete[] data;
        data = newSpace;
    }

    this->size = size + ms.size;
    strcat(data, ms.data);

    return *this;
}
MyString& MyString::operator+=(const char* str)
{
    if(str == NULL)
    {
        return *this;
    }

    if(capacity <= size + strlen(str))
    {
        char* newSpace = new char[size + strlen(str) + 1];
        memset(newSpace, 0, size + strlen(str) + 1);
        strcat(newSpace, data);
        this->capacity = size + strlen(str) + 1;
    }

    strcat(data, str);
    this->size = size + strlen(str);

    return *this;
}
MyString MyString::operator+(const MyString& ms)
{
    if(ms.data == NULL)
    {
        return *this;
    }

    MyString temp;

    temp.capacity = ms.size + size + 1;
    temp.size = ms.size + size;
    delete[] temp.data;
    temp.data = new char[temp.capacity];
    memset(temp.data, 0, temp.capacity);
    strcat(temp.data, data);
    strcat(temp.data, ms.data);

    return temp;
}
MyString MyString::operator+(const char* str)
{
    if(str == NULL)
    {
        return *this;
    }

    MyString temp;
    temp.capacity = size + strlen(str) + 1;
    temp.size = size + strlen(str);
    delete[] temp.data;
    temp.data = new char[temp.capacity];
    memset(temp.data, 0, temp.capacity);
    strcat(temp.data, data);
    strcat(temp.data, str);
    
    return temp;
}

char& MyString::operator[](int index)
{
    if(index > size || index < 0)
    {
        static char err = 0;
        err = 0;
        return err;
    }

    if(index == size)
    {
        if(size + 1 < capacity)
        {
            ++size;   
        }
        else
        {
            static char err = 0;
            err = 0;
            return err;
        }
    }
    return data[index];
}

ostream& operator<<(ostream& out, MyString& ms)
{
    out << ms.data;
    return out;
}
istream& operator>>(istream& in, MyString& ms)
{
    char str[1024];
    in >> str;
    ms.capacity = strlen(str) + 1;
    ms.size = strlen(str);
    if(ms.data != NULL)
    {
        delete[] ms.data;
        ms.data = NULL;
    }
    
    ms.data = new char[ms.capacity];
    memcpy(ms.data, str, ms.capacity);
    return in;
}