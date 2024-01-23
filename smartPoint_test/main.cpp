#include <iostream>

using namespace std;

class Animal
{
public:
    Animal(){}
    Animal(string name)
    {
        this->name = name;
    }

    void speak()
    {
        cout << "hhh" << endl;
    }

private:
    string name;
};

class SmartPoint
{
public:
    SmartPoint(Animal* an)
    {
        this->an = an;
    }

    Animal* operator->()
    {
        return an;
    }

    Animal& operator*()
    {
        return *an;
    }

    ~SmartPoint()
    {
        cout << "delete animal*" << endl;
        delete an;
        an = NULL;
    }
private:
    Animal* an;
};

void test()
{
    Animal* dark = new Animal("zhouheiya");
    SmartPoint myDark(dark);
    myDark->speak();
    (*myDark).speak();
}

int main()
{
    test();
    return 0;
}