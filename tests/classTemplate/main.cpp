#include <iostream>


class C
{
    const int cValue{ 4 };

public:
    C()
    {
        std::cout << cValue << std::endl;
    }
    ~C() {}

    void GetValue() { std::cout << cValue << std::endl; }
};


class B
{
    const int bValue{ 3 };

public:
    B()
    {
        std::cout << bValue << std::endl;
    }
    ~B() {}

    void GetValue() { std::cout << bValue << std::endl; }
};


template<typename T>
class A : public T
{
    const int aValue{ 1 };

public:
    A() :
        T()
    {
        std::cout << aValue << std::endl;
        T::GetValue();
    }


};


int main( int argc, char *argv[] )
{
    A<C> *c;
    c = new A<C>();

    return 0;
}
