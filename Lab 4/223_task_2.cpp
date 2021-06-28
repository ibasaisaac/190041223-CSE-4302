#include<iostream>
using namespace std;

class FlightInfo
{
private:
    int FlightNumber;
    string Destination;
    float Distance;
    float MaxFuelCapacity;
    int CalFuel()
    {
        int Fuel;
        if(Distance<=1000)
            Fuel=500;
        else if(Distance>1000 && Distance<=2000)
            Fuel=1100;
        else if(Distance>2000)
            Fuel=2200;
        return Fuel;
    }
public:
    int Fuel;
    FlightInfo()
    {
        FlightNumber=0;
        Destination="";
        Distance=0.0;
        MaxFuelCapacity=0.0;
    }
    void FeedInfo()
    {
        cout<<"Flight Number: ";
        cin>>FlightNumber;
        cout<<"Destination: ";
        cin>>Destination;
        cout<<"Distance: ";
        cin>>Distance;
        Fuel=CalFuel();
    }
    void ShowInfo()
    {
        cout<<"Flight Number: "<<FlightNumber<<endl;
        cout<<"Destination: "<<Destination<<endl;
        cout<<"Distance: "<<Distance<<endl;
        cout<<"Max fuel capacity: "<<Fuel<<endl;
    }
};

int main()
{
    FlightInfo f;
    f.FeedInfo();
    f.ShowInfo();
}
