#include<iostream>
using namespace std;

class Shape
{
public:
    virtual string whoAmI() //virtual function
    {
        return ("I am a shape\n");
    }
    virtual float area()=0; //pure virtual function
    virtual ~Shape()
    {
        cout<<"shape's destructor"<<endl;
    }
};

class Circle:public Shape
{
private:
    float r;
public:
    Circle(float rad):r(rad)
    {

    }
    ///whoAmI() function not overridden.
    float area()
    {
        return 3.14*r*r;
    }
    ~Circle()
    {
        cout<<"circle's destructor"<<endl;
    }
};
class Square:public Shape
{
private:
    float a;
public:
    Square(float s):a(s)
    {

    }
    string whoAmI()
    {
        return ("I am a square\n");
    }
    float area() //if area() was not overridden then compiler gives error as
    {           //derived class also becomes abstract class that is it can't
                //create objects.
    return a*a;
    }
    ~Square()
    {
        cout<<"square's destructor"<<endl;
    }
};

int main()
{
    //Shape sh;
    Shape *s[20];
    for(int i=0;i<20;i++)
    {
        s[i]=nullptr;
    }
    float x,radius;
    cout<<"Side of square= ";
    cin>>x;
    cout<<"Radius of circle= ";
    cin>>radius;

    s[0]=new Circle(radius);
    s[1]=new Square(x); //this line will give error if pure virtual function

    for(int i=0;i<20;i++)
    {
        if(s[i])
        {
            cout<<s[i]->whoAmI();
            cout<<"Area= "<<s[i]->area()<<endl;
        }
    }

    delete s[0];
    delete s[1];
}
