///Inheritance contains "is a" relationship
#include<iostream>
using namespace std;

class Seat
{
private:
    string comf;
    bool warmer;
public:
    Seat(string s, bool wm):comf(s),warmer(wm)
    {

    }
    void setComfortability (string c)
    {
        comf=c;
    }
    void setWarmer(bool w)
    {
        warmer=w;
    }
    string getComfortability()
    {
        return comf;
    }
    bool getWarmer()
    {
        return warmer;
    }

};

class Wheel
{
private:
    double radius;
public:
    Wheel(double r):radius(r)
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
    Engine(double mf, double me, double r):maxFuel(mf),maxEnergy(me),rpm(r)
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
    Door(string open):mode(open)
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

class Car: public Seat, public Wheel, public Engine, public Door
{
private:
    double maximum_acceleration, fuel_capacity;
public:
    Car(string c,bool w,double rd,double mf,double me,double r,string o,double a,double fcp)
        :Seat(c,w),Wheel(rd),Engine(mf,me,r),Door(o),maximum_acceleration(a),fuel_capacity(fcp)
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
    void display()
    {
        cout<<"\nDisplaying car info:"<<endl;
        cout<<"Seats' comfortability is "<<getComfortability()<<endl;
        if(getWarmer())
            cout<<"Seat warmer present"<<endl;
        else
            cout<<"Seat warmer not present"<<endl;

        cout<<"Circumference of wheels= "<<getCircumference()<<endl;

        cout<<"Maximum Fuel Consumption Rate= "<<getFuel()<<endl;
        cout<<"Maximum Energy Production Rate= "<<getEnergy()<<endl;
        cout<<"Average RPM= "<<getRPM()<<endl;

        cout<<"Opening mode: "<<getmode()<<endl;

        cout<<"Maximum acceleration= "<<getAcceleration()<<endl;
        cout<<"Fuel capacity= "<<getFuelCap()<<endl;
    }
};

int main()
{
    cout<<"Seats' comfortability= ";
    string st;
    int yn;
    cin>>st;
    cout<<"Is seat warmer present? (1/0): ";
    cin>>yn;
    double rad;
    cout<<"Radius of wheel= ";
    cin>>rad;
    double mf,me,r;
    cout<<"Maximum Fuel Consumption Rate= ";
    cin>>mf;
    cout<<"Maximum Energy Production Rate= ";
    cin>>me;
    cout<<"Average RPM= ";
    cin>>r;
    string op;
    cout<<"Opening mode: ";
    cin>>op;
    double ma,fcp;
    cout<<"Maximum acceleration= ";
    cin>>ma;
    cout<<"Fuel capacity= ";
    cin>>fcp;
    Car c(st,yn,rad,mf,me,r,op,ma,fcp);
    c.display();
}
