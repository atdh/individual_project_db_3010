#include <iostream>
#include <string>
#include <sstream>
using namespace std;
/*
int main()
{
    int *p;
    int var = 7;
    int foo = 21;
    //std::cout << &p;
    p = &var;
    std::cout << p;

    int &ref = var;
    std::cout << ref;
}*/
class Foo
{
public:
    Foo(int bar) : bar_(bar) {}
    int CalculateMysteries()
    {
        return baz_;
    }
    static int TotalBars()
    {
        baz_ = 3;
        //std::cout << 3;
        return baz_;
    }

private:
    int bar_;
    static int baz_;
};
/*
int main()
{
    //Foo object(3);
    //object.CalculateMysteries();
    //Foo a = Foo::TotalBars();
    Foo a(3);
    Foo *b = &a;
    **b.TotalBars();

    return 0;
}*/

int main()
{
    int x = 5;
    int y = 5;

    if (y > x)
    {
        cout << "We're messing with numbers!" << endl;
        x += 1;
    }
    else if (x > y)
    {
        cout << "We're messing with numbers!" << endl;
        y += 1;
    }
    else if (x == y)
    {
        cout << "We're messing with numbers!" << endl;
        x = x + y;
    }
    return 0;
}
