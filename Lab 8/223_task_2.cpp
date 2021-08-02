///Since car and its components have a "consists of" relationship.
///for ex- car consists of doors. So used composition.
///But inheritance contains "is a" relationship.
#include<iostream>
using namespace std;

class Seat
{
private:
    string comf;
    int warmer;
public:
    Seat():comf(""),warmer(0)
    {

    }
    void setComfortability (string c)
    {
        comf=c;
    }
    void setWarmer(int w)
    {
        warmer=w;
    }
    string getComfortability()
    {
        return comf;
    }
    int getWarmer()
    {
        return warmer;
    }

};

class Wheel
{
private:
    double radius;
public:
    Wheel():radius(0)
    {

    }
    void setRadius(double r)
    {
        radius = r;
    }
    double getRadius()
    {
        return radius;
    }
    double getCircumference()
    {
        return (2*3.1416*radius);
    }
};

class Engine
{
private:
    double maxFuel;
    double maxEnergy;
    double rpm;
public:
    Engine():maxFuel(0),maxEnergy(0),rpm(0)
    {

    }
    void setFuel(double f)
    {
        maxFuel=f;
    }
    void setEnergy(double e)
    {
        maxEnergy=e;
    }
    void setRPM(double r)
    {
        rpm=r;
    }
    double getFuel()
    {
        return maxFuel;
    }
    double getEnergy()
    {
        return maxEnergy;
    }
    double getRPM()
    {
        return rpm;
    }
};

class Door
{
private:
    string mode;
public:
    Door():mode("")
    {

    }
    void setmode(string m)
    {
        mode=m;
    }
    string getmode()
    {
        return mode;
    }
};

class Car
{
private:
    double maximum_acceleration, fuel_capacity;
public:
    Car():maximum_acceleration(0), fuel_capacity(0)
    {

    }
    void setAcceleration(double acc)
    {
        maximum_acceleration=acc;
    }
    void setFuelCap(double fc)
    {
        fuel_capacity=fc;
    }
    double getAcceleration()
    {
        return maximum_acceleration;
    }
    double getFuelCap()
    {
        return fuel_capacity;
    }
    Seat s;
    Wheel w;
    Engine e;
    Door d;
    void display()
    {
        cout<<"\nDisplaying car info:"<<endl;
        cout<<"Seats' comfortability is "<<s.getComfortability()<<endl;
        if(s.getWarmer())
            cout<<"Seat warmer present"<<endl;
        else
            cout<<"Seat warmer not present"<<endl;

        cout<<"Circumference of wheels= "<<w.getCircumference()<<endl;

        cout<<"Maximum Fuel Consumption Rate= "<<e.getFuel()<<endl;
        cout<<"Maximum Energy Production Rate= "<<e.getEnergy()<<endl;
        cout<<"Average RPM= "<<e.getRPM()<<endl;

        cout<<"Opening mode: "<<d.getmode()<<endl;

        cout<<"Maximum acceleration= "<<getAcceleration()<<endl;
        cout<<"Fuel capacity= "<<getFuelCap()<<endl;
    }
};
int main()
{
    Car c;
    cout<<"Seats' comfortability= ";
    string st;
    int yn;
    cin>>st;
    c.s.setComfortability(st);
    cout<<"Is seat warmer present? (1/0): ";
    cin>>yn;
    c.s.setWarmer(yn);
    double rad;
    cout<<"Radius of wheel= ";
    cin>>rad;
    c.w.setRadius(rad);
    double mf,me,r;
    cout<<"Maximum Fuel Consumption Rate= ";
    cin>>mf;
    c.e.setFuel(mf);
    cout<<"Maximum Energy Production Rate= ";
    cin>>me;
    c.e.setEnergy(me);
    cout<<"Average RPM= ";
    cin>>r;
    c.e.setRPM(r);
    string op;
    cout<<"Opening mode: ";
    cin>>op;
    c.d.setmode(op);
    double ma,fcp;
    cout<<"Maximum acceleration= ";
    cin>>ma;
    c.setAcceleration(ma);
    cout<<"Fuel capacity= ";
    cin>>fcp;
    c.setFuelCap(fcp);

    c.display();
}
