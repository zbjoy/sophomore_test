#pragma once

#include <iostream>
#include <string.h>

using namespace std;

class MyString
{

    friend ostream& operator<<(ostream& out, MyString& ms);
    friend istream& operator>>(istream& in, MyString& ms);
public:
    MyString();
    MyString(const MyString& ms);
    MyString(const char* str);
    MyString& operator=(const MyString& ms);
    MyString& operator=(const char* str);
    ~MyString();

    MyString& operator+=(const MyString& ms);
    MyString& operator+=(const char* str);
    MyString operator+(const MyString& ms);
    MyString operator+(const char* str);

    char& operator[](int index);
private:
    char* data;
    int size;
    int capacity;
};