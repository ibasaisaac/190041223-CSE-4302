#include<iostream>
using namespace std;

namespace my_namespace
{
    int x;

    int add(int a, int b)
    {
        return a+b;
    }
}
float add(float a, float b)
{
    return a+b;
}
int main()
{
    float x=4.67;

    my_namespace::x=88;

    cout<<x<<endl;
    cout<<my_namespace::x<<endl;

    cout<<add(4.2,1)<<endl;
    cout<<my_namespace::add(1,2)<<endl;
}
