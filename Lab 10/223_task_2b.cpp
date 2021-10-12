#include<iostream>
using namespace std;

class Distance
{
private:
    float *p;
public:
    Distance(float f=0)
    {
        p=new float(f);
    }
    ~Distance()
    {
        delete p;
    }
    void setdata(float ff)
    {
        *p=ff;
    }
    void print()
    {
        cout<<*p<<endl;
    }
    Distance operator= (const Distance &d) //assignment operator overloading
    {
        *p=*(d.p);
        return Distance(*p);
    }
//    Distance(const Distance &d)
//    {
//        *p=*(d.p);
//    }
};

int main()
{
    Distance d1(2);
    Distance d2;
    //Distance d3=d1;
    d2=d1; //2  assignment operation
    d1.setdata(45);
    d1.print(); //45
    d2.print(); //should be 2 but is 45. This happens where p of both objects point
                //to the same location. So changes made in d1, changes d2 too.
//    Distance d3=d2;
//    d3.print();
}
