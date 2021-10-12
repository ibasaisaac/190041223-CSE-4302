#include<iostream>
#include<cmath>
#define PI 3.1416
using namespace std;
class Shape
{
public:
    string whoAmI()
    {
        return string("I am a shape\n");
    }
};

class TwoDimensionalShape: public Shape
{
//private:
//    int op=5;
protected:
    string whoAmI() //overridden function
    {                //calling the whoAmI() function of base class-Shape and adding the returned string
        return Shape::whoAmI() + ("I am a two-dimensional shape\n");
    }
public:
    int op=9;
    void area()
    {
        double ar=0;
        cout<<"Area= "<<ar<<endl;
    }
    void perimeter()
    {
        double p=0;
        cout<<"Perimeter= "<<p<<endl;
    }
};

class ThreeDimensionalShape: public Shape
{
protected:
    string whoAmI() //overrides shape class
    {
        return Shape::whoAmI() + ("I am a three-dimensional shape\n");
    }
public:
    void SurfaceArea()
    {
        double ar=0;
    }
    void volume()
    {
        double v=0;
    }
};

class Triangle: public TwoDimensionalShape
{             ///public of TwoDimensionalShape are public and accessible
             ///protected of TwoDimensionalShape are protected and accessible
             ///private of TwoDimensionalShape are inaccessible
private:
    double a,b,c;
public:
    //op=6; not ok
    Triangle():a(0),b(0),c(0)
    {
        //op=6;
    }
    Triangle(double ta, double tb, double tc):a(ta),b(tb),c(tc)
    {

    }
    string whoAmI() //overridden function
    {               //calling the whoAmI() function of base class and adding the returned string
        return TwoDimensionalShape::whoAmI() + string("I am a triangle\n");
        //op=6; ok here in overridden function
    }
    void area() //overridden function
    {
        double ar,s;
        s=(a+b+c)/2;
        ar= sqrt(s*(s-a)*(s-b)*(s-c));
        cout<<"Area of triangle= "<<ar<<endl;
    }
    void perimeter() //overridden function
    {
        double p=a+b+c;
        cout<<"Perimeter of triangle= "<<p<<endl;
    }
};

class Circle: private TwoDimensionalShape
{               ///public of TwoDimensionalShape treated as private and accessible
               ///protected of TwoDimensionalShape treated as private and accessible
               ///private of TwoDimensionalShape is inaccessible

               ///Accessible members can be used inside the member function of Circle.
               ///But the accessible members of TwoDimensionalShape cannot be accessed outside using
               ///Circle object neither can any derived class of Circle can access them. For this,
               ///those members are overridden in public of Circle(derived) class.

private:
    double radius;
public:
    Circle(): radius(0)
    {

    }
    Circle(double r): radius(r)
    {

    }
    string whoAmI() //overridden function
    {     ///calling the whoAmI()-protected function of base class and adding the returned string
        return TwoDimensionalShape::whoAmI() + string("I am a circle\n");
    }
    void area() //overridden function
    {
        cout<<"Area of circle= "<<(PI*radius*radius)<<endl;
    }
    void perimeter() //overridden function
    {
        cout<<"Circumference of circle= "<<(2*PI*radius)<<endl;
    }
};

class Rectangle: protected TwoDimensionalShape
{                ///public and protected members of TwoDimensionalShape are protected and
                ///accessible in Rectangle class
                ///private of TwoDimensionalShape are inaccessible in Rectangle class.
 private:
     double l,b;
 public:
    Rectangle():l(0),b(0)
    {

    }
    Rectangle(double tl, double tb):l(tl),b(tb)
    {

    }
    string whoAmI() //overridden function
    {     //calling the whoAmI() function of base class and adding the returned string
        return TwoDimensionalShape::whoAmI() + ("I am a rectangle\n");
    }
    void area() //overridden function
    {
        cout<<"Area of rectangle= "<<l*b<<endl;
    }
    void perimeter() //overridden function
    {
        cout<<"Perimeter of rectangle= "<<2*(l+b)<<endl;
    }
};

class Square:public TwoDimensionalShape
{
private:
    double s;
public:
    Square():s(0)
    {

    }
    Square(double side):s(side)
    {

    }
    string whoAmI() //overridden function
    {      //calling the whoAmI() function of base class and adding the returned string
        return TwoDimensionalShape::whoAmI() + ("I am a square\n");
    }
    void area() //overridden function
    {
        cout<<"Area of square= "<<s*s<<endl;
    }
    void perimeter() //overridden function
    {
        cout<<"Perimeter of square= "<<4*s<<endl;
    }
};

class Cube: public ThreeDimensionalShape
{            ///public of ThreeDimensionalShape are public and accessible
             ///protected of ThreeDimensionalShape are protected and accessible
             ///private of ThreeDimensionalShape are inaccessible
private:
    double x;
public:
    Cube():x(0)
    {

    }
    Cube(double side):x(side)
    {

    }
    void SurfaceArea() //overrides the surfacearea() of ThreeDimensionalShape(its base class)
    {
        cout<<"Surface area of cube= "<<6*x*x<<endl;
    }
    void volume() //overrides the volume() of ThreeDimensionalShape(its base class)
    {
        cout<<"Volume of cube= "<<x*x*x<<endl;
    }
    string whoAmI()
    {
        return ThreeDimensionalShape::whoAmI() + ("I am a cube\n");
    }
};

class Sphere: public ThreeDimensionalShape
{
private:
    double rad;
public:
    Sphere():rad(0)
    {

    }
    Sphere(double r):rad(r)
    {

    }
    void SurfaceArea() //overrides the surfacearea() of ThreeDimensionalShape(its base class)
    {
        cout<<"Surface area of sphere= "<<4*PI*rad*rad<<endl;
    }
    void volume() //overrides the volume() of ThreeDimensionalShape(its base class)
    {
        cout<<"Volume of sphere= "<<(4*PI*rad*rad*rad)/3<<endl;
    }
    string whoAmI()
    {
        return ThreeDimensionalShape::whoAmI() + ("I am a sphere\n");
    }
};

class Cylinder: private ThreeDimensionalShape
{              ///public of ThreeDimensionalShape treated as private and accessible
               ///protected of ThreeDimensionalShape treated as private and accessible
               ///private of ThreeDimensionalShape is inaccessible

               ///Accessible members can be used inside the member function of Cylinder.
               ///But the accessible members of ThreeDimensionalShape cannot be accessed outside using
               ///Cylinder object neither can any derived class of Cylinder can access them. For this,
               ///those members are overridden in public of Cylinder(derived) class.
private:
    double r,h;
public:
    Cylinder():r(0),h(0)
    {

    }
    Cylinder(double radius, double height):r(radius),h(height)
    {

    }
    void SurfaceArea() ///function overridden regardless of access specifier
    {
        double a= 2*PI*r*h+2*PI*r*r;
        cout<<"Surface area of cylinder= "<<a<<endl;
    }
    void volume() ///function overridden regardless of access specifier
    {
        cout<<"Volume of cylinder= "<<PI*r*r*h<<endl;
    }
    string whoAmI() ///function overridden regardless of access specifier
    {
        return ThreeDimensionalShape::whoAmI() + ("I am a cylinder\n");
    }
};

class Cone: protected ThreeDimensionalShape
{               ///public and protected members of ThreeDimensionalShape are protected and
                ///accessible in Cone class
                ///private of ThreeDimensionalShape are inaccessible in Cone class.
private:
    double r,h;
//protected:
//    string whoAmI()
//    {   can't be accessed outside class
//        return ThreeDimensionalShape::whoAmI() + ("I am a cone\n");
//    }
public:
    Cone():r(0),h(0)
    {

    }
    Cone(double cor, double coh):r(cor),h(coh)
    {

    }
    void SurfaceArea()
    {
        double a=PI*r*(r+sqrt(h*h+r*r));
        cout<<"Surface area of cone= "<<a<<endl;
    }
    void volume()
    {
        double v=(PI*r*r*h)/3;
        cout<<"Volume of cone= "<<v<<endl;
    }
    string whoAmI()
    {
        return ThreeDimensionalShape::whoAmI() + ("I am a cone\n");
    }
};
int main()
{
    double x,y,z;
    cout<<"Enter three sides of a triangle= ";
    cin>>x>>y>>z;
    Triangle t1(x,y,z);
    t1.area();
    t1.perimeter();
    cout<<t1.whoAmI();

    double r;
    cout<<"Enter radius of a circle= ";
    cin>>r;
    Circle c1(r);
    c1.area();
    c1.perimeter();
    cout<<c1.whoAmI();

    double length, bredth;
    cout<<"Enter two sides of a rectangle= ";
    cin>>length>>bredth;
    Rectangle r1(length,bredth);
    r1.area();
    r1.perimeter();
    cout<<r1.whoAmI();

    double side;
    cout<<"Enter side of a square= ";
    cin>>side;
    Square s1(side);
    s1.area();
    s1.perimeter();
    cout<<s1.whoAmI();

    double sc;
    cout<<"Enter side of a cube= ";
    cin>>sc;
    Cube cu1(sc);
    cu1.SurfaceArea();
    cu1.volume();
    cout<<cu1.whoAmI();

    double rs;
    cout<<"Enter radius of a sphere= ";
    cin>>rs;
    Sphere sp1(rs);
    sp1.SurfaceArea();
    sp1.volume();
    cout<<sp1.whoAmI();

    double rc,hc;
    cout<<"Enter radius and height of a cylinder= ";
    cin>>rc>>hc;
    Cylinder cy1(rc,hc);
    cy1.SurfaceArea();
    cy1.volume();
    cout<<cy1.whoAmI();

    double coneR, coneH;
    cout<<"Enter radius and height of a cone= ";
    cin>>coneR>>coneH;
    Cone co1(coneR,coneH);
    co1.SurfaceArea();
    co1.volume();
    cout<<co1.whoAmI();
}
