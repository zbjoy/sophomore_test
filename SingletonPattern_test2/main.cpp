#include <iostream>

using namespace std;

class Maker
{
public:
    static Maker* getMaker()
    {
        return maker;
    }

    void func()
    {
        cout << "mySingletonpattern" << endl;
    }

private:
    Maker(){};
    Maker(const Maker&){};

private:
    static Maker* maker;
};

Maker* Maker::maker = new Maker;

void test()
{
    Maker* maker = Maker::getMaker();
    maker->func();
}

int main()
{
    test();
    return 0;
}