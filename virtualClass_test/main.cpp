#include <iostream>

using namespace std;

class Animal
{
public:
    Animal()
    {
        a = 100;
    }

    int a;
};

class Sheep: virtual public Animal
{

};

class Clem: virtual public Animal
{

};

class SheepClem : public Sheep, public Clem
{

};


void test()
{
    // Clem cm;
    // cout << ((Animal*)((char*)(&cm) + (*(((int*)(*((long long*)(&cm)))) + 1))))->a << endl;
    Sheep cm;
cout << (((Animal*)((char*)(&cm) + (*(((int*)(*((long long*)(&cm)))) + 1))))->a) << endl;
}

int main()
{
    test();
    return 0;
}