#include<iostream>
using namespace std;
class Calculator
{
private:
    int value;
public:
    Calculator():value(0)
    {

    }
    Calculator(int val):value(val)
    {

    }
    ~Calculator()
    {
        cout<<"Calculator object is destroyed."<<endl;
    }
    int getValue()
    {
        return value;
    }
    void setValue(int Value)
    {
        value=Value;
    }
    void add(int Value)
    {
        value+=Value;
    }
    void subtract(int Value)
    {
        value-=Value;
    }
    void multiply(int Value)
    {
        value*=Value;
    }
    void divideBy(int Value)
    {
        value/=Value;
    }
    void clear()
    {
        value=0;
    }
    void display()
    {
        cout<<"Calculator display: "<<value<<endl;
    }
};
int main()
{
    Calculator c;
    string str;
    int x;
    while(1)
    {
        cout<<"Enter function and value: \n";
        cin>>str;
        if(str=="clear")
        {
            c.clear();
            c.display();
            break;
        }
        cin>>x;
        if(str=="add")
        {
            c.add(x);
            c.display();
        }
        else if(str=="subtract")
        {
            c.subtract(x);
            c.display();
        }
        else if(str=="multiply")
        {
            c.multiply(x);
            c.display();
        }
        else if(str=="divideby")
        {
            if(x==0)
            {
                cout<<"Error: divide by 0 is undefined."<<endl;
                c.display();
                continue;
            }
            c.divideBy(x);
            c.display();
        }
    }
}
