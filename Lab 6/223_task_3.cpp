#include<bits/stdc++.h>
using namespace std;

class Coordinate
{
private:
    float x,y;
public:
    Coordinate():x(0),y(0)
    {

    }
    Coordinate(float cx,float cy):x(cx),y(cy)
    {

    }
    ~Coordinate()
    {

    }
    void display()
    {
        cout<<x<<" "<<y<<endl;
    }
    float getDistance()
    {
        float d;
        d=sqrt(x*x+y*y);
        cout<<"Distance from origin: "<<d<<endl;
    }
    float getDistance(Coordinate c)
    {
        float d;
        d=sqrt((x-c.x)*(x-c.x)+(y-c.y)*(y-c.y));
        cout<<"Distance from object: "<<d<<endl;
    }
    void move_x(float val)
    {
        x+=val;
    }
    void move_y(float val)
    {
        y+=val;
    }
    void move(float val)
    {
        move_x(val);
        move_y(val);
    }
    Coordinate operator++()
    {
        return Coordinate(++x,++y);
    }
    Coordinate operator++(int)
    {
        return Coordinate(x++,y++);
    }
    Coordinate operator--()
    {
        return Coordinate(--x,--y);
    }
    Coordinate operator--(int)
    {
        return Coordinate(x--,y--);
    }
    bool operator>(Coordinate)const;
    bool operator<(Coordinate)const;
    bool operator>=(Coordinate)const;
    bool operator<=(Coordinate)const;
    bool operator==(Coordinate)const;
    bool operator!=(Coordinate)const;
};
bool Coordinate::operator==(Coordinate c)const
{
    float d1,d2;
    d1=sqrt(x*x+y*y);
    d2=sqrt(c.x*c.x+c.y*c.y);
    return(d1==d2);
}
bool Coordinate::operator!=(Coordinate c)const
{
    float d1,d2;
    d1=sqrt(x*x+y*y);
    d2=sqrt(c.x*c.x+c.y*c.y);
    return(d1!=d2);
}
bool Coordinate::operator>(Coordinate c)const
{
    float d1,d2;
    d1=sqrt(x*x+y*y);
    d2=sqrt(c.x*c.x+c.y*c.y);
    return(d1>d2);
}
bool Coordinate::operator<(Coordinate c)const
{
    float d1,d2;
    d1=sqrt(x*x+y*y);
    d2=sqrt(c.x*c.x+c.y*c.y);
    return(d1<d2);
}
bool Coordinate::operator>=(Coordinate c)const
{
    float d1,d2;
    d1=sqrt(x*x+y*y);
    d2=sqrt(c.x*c.x+c.y*c.y);
    return(d1>=d2);
}
bool Coordinate::operator<=(Coordinate c)const
{
    float d1,d2;
    d1=sqrt(x*x+y*y);
    d2=sqrt(c.x*c.x+c.y*c.y);
    return(d1<=d2);
}

int main()
{
    Coordinate c1(1,1), c2(-1,-1),c3,c4;
    c1.display();
    c2.display();
    c1.getDistance();
    c1.getDistance(c2);
    c1.move_x(1);
    c1.move_y(1);
    c1.display();
    c2.move(-1);
    c2.display();

    cout<<"c3:"<<endl;
    c3=++c1;
    c3.display();
    c3=c1++;
    c3.display();
    c3=--c1;
    c3.display();
    c3=c1--;
    c3.display();

    cout<<"c1:"<<endl;
    c1.display();
    cout<<"c2:"<<endl;
    c2.display();
    if(c1>c3) cout<<":c1>c3\n";
    if(c2<c3) cout<<":c2<c3\n";
    if(c1>=c2) cout<<":c1>=c2\n" ;
    if(c1<=c2) cout<<":c1<=c2\n";
    if(c1==c2) cout<<":c1==c2\n";
    if(c1!=c2) cout<<":c1!=c2\n";
}
