#include<iostream>
using namespace std;

class Distance
{
private:
    float feet, inches;
    ///if we overload the copy constructor and assignment operator in private then the
    ///class will be restricted to copy one object with another.
//    Distance(const Distance &d)
//    { //only copying the inches value
//        inches=d.inches;
//        feet=0;
//    }
//    Distance operator= (const Distance &d) //assignment operator overloading
//    { //only copying the feet value
//        feet=d.feet;
//        return Distance(feet,inches);
//    }
public:
    Distance():feet(0),inches(0)
    {

    }
    Distance(float f, float i):feet(f),inches(i)
    {

    }
    Distance(const Distance &d)
    { //only copying the inches value
        inches=d.inches;
        feet=0;
    }
    Distance operator= (const Distance &d) //assignment operator overloading
    { //only copying the feet value
        feet=d.feet;
        return Distance(feet,inches);
    }
    void print()
    {
        cout<<feet<<"'"<<inches<<"''"<<endl;
    }
};

int main()
{
    Distance d1(5,2);
    Distance d2;
    Distance d3(d1); //initialization- store value at the time of creation
                    //using copy constructor

    d2=d1; //assignment operation- store value after creation
    Distance d4,d5;
    d5=d4=d2;

    d1.print();
    d2.print();
    d3.print();
    d4.print();
    d5.print();
}
