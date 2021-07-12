#include<iostream>
using namespace std;

class Rectangle
{
private:
    int length,width;
public:
    Rectangle(int l=1, int w=1, int op=0)
    {
        length=l;
        width=w;
    }
    Rectangle():length(1),width(1)
    {

    }
    int getLength()
    {
        return length;
    }
    int getWidth()
    {
        return width;
    }
    void setLength(int l)
    {
        if(l>=1.0 && l<=20.0)
            length=l;
        else
        {
            cout<<"Length range not met"<<endl;
        }
    }
    void setWidth(int w)
    {
        if(w>=1.0 && w<=20.0)
            width=w;
        else
        {
            cout<<"Width range not met"<<endl;
        }
    }
    void area()
    {
        double a;
        a=length*width;
        cout<<"Area: "<<a<<endl;
    }
    void perimeter()
    {
        double p;
        p=2*(length+width);
        cout<<"Perimeter: "<<p<<endl;
    }
};

int main()
{
    Rectangle r1();
    int x,y;
    cout<<"Length: "<<r1.getLength()<<endl;
    cout<<"Width: "<<r1.getWidth()<<endl;
    r1.area();
    r1.perimeter();
    Rectangle r2(x,y);
    cout<<"Length: "<<r2.getLength()<<endl;
    cout<<"Width: "<<r2.getWidth()<<endl;
    r2.setLength(r2.getLength());
    r2.setWidth(r2.getWidth());
    r2.area();
    r2.perimeter();
}
