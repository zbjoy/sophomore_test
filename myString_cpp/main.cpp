#include <iostream>
#include "myString.h"

using namespace std;

void test()
{
    MyString s1;
    MyString s2("hhhhhaaa");
    MyString s3(".....");
    s1 = s2 + s3;
    cout << s1 << endl;
    s2 += s3;
    cout << s2 << endl;
    s3 += "ooo";
    cout << s3 << endl;
}

int main()
{
    test();
    return 0;
}