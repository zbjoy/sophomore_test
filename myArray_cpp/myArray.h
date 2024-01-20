#include <iostream>
#include <string.h>

using namespace std;

// template <typename T>
class MyArray
{
public:
    MyArray();
    MyArray(int tCapacity, char val = '0');
    MyArray(const MyArray& arr);
    MyArray& operator=(MyArray& arr);
    char& operator[](int pos);
    ~MyArray();

    void PushFront(char val);

    void PushBack(char val);

    void PopFront();

    void PopBack();

    int Size();

    int Capacity();

    void Insert(char val, int pos);

    char& Get(int pos);

    void Set(int pos, char val);
    //void pushFront(T& tempData);

    //void push


private:
    // T* data;
    char* data;
    int size;
    int capacity;
};