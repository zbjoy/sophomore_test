#include <iostream>
#include "myArray.h"

using namespace std;

void test()
{
    // MyArray<char> arr1;
    // MyArray<char> arr2(arr1);
    MyArray arr1;
    MyArray arr2(arr1);
    MyArray arr3;
    arr3 = arr1;
    arr1.PushFront('3');
    arr1.PushBack('h');
    arr2 = arr1;

    for(int i = 0; i < 10; i++)
    {
        arr3[i] = '0' + i;
    }

    for(int i = 0; i < 10; i++)
    {
        if(!(i % 3))
        endl(cout);
        
        cout << arr3[i] << "  ";
    }
}

int main()
{
    test();
    cout << "hello, world";
    endl(cout);
    return 0;
}