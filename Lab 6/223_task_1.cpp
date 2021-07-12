#include<iostream>
using namespace std;

class Counter
{
private:
    int count;
    int steps;
public:
    Counter():count(0),steps(1)
    {

    }
    Counter(int c, int s):count(c),steps(s)
    {

    }
    void setIncrementStep(int step_val)
    {
        steps=step_val;
    }
    int getCount()
    {
        return count;
    }
    int getSteps()
    {
        return steps;
    }
    void increment()
    {
        count+=steps;
    }
    void resetCount()
    {
        count=0;
    }
    Counter operator+ (const Counter&)const; //c2+c3
    Counter operator+ (const int)const; //c2+4
    friend Counter operator+ (int v, Counter l); //4+c2
    void operator+= (const Counter&);
    Counter operator++();
    Counter operator++(int);
};
Counter Counter::operator++(int)
{
    return Counter(count++,steps);
}
Counter Counter::operator++()
{
    return Counter(++count,steps);
}
void Counter::operator+=(const Counter& c)
{
    count+=c.count;
}
Counter operator+ (int v, Counter r) //4+c2
{
    Counter temp;
    temp.count=v+r.count;
    temp.steps=r.steps;
    return temp;
}
Counter Counter::operator+ (const int v)const //c2+4
{
    Counter temp;
    temp.count = count+v;
    temp.steps = steps;
    return temp;
}
Counter Counter::operator+ (const Counter& c)const //c2+c3
{
    Counter temp;
    temp.count=count+c.count;
    temp.steps=min(steps,c.steps);
    return temp;
}

int main()
{
    Counter c1,c2(4,4),c3(6,3);
    int var;

    c1.setIncrementStep(1);
    c1.increment();
    cout<<"c1 count= "<<c1.getCount()<<endl;
    cout<<"c1 step= "<<c1.getSteps()<<endl;
//c1+=c2+c3;

    c1=c2+c3;
    cout<<"c1=c2+c3"<<endl;
    cout<<"c1 count= "<<c1.getCount()<<endl;
    cout<<"c1 step= "<<c1.getSteps()<<endl;

    cout<<"Enter variable: ";
    cin>>var;
    c1 = c2+var;
    cout<<"c1=c2+"<<var<<endl;
    cout<<"c1 count= "<<c1.getCount()<<endl;
    cout<<"c1 step= "<<c1.getSteps()<<endl;

    c1=var+c2;
    cout<<"c1="<<var<<"+c2"<<endl;
    cout<<"c1 count= "<<c1.getCount()<<endl;
    cout<<"c1 step= "<<c1.getSteps()<<endl;

    c1+=c2;
    cout<<"c1+=c2"<<endl;
    cout<<"c1 count= "<<c1.getCount()<<endl;

    c1=++c2;
    cout<<"c1=++c2"<<endl;
    cout<<"c1 count= "<<c1.getCount()<<endl;
    cout<<"c1 step= "<<c1.getSteps()<<endl;

    c1=c2++;
    cout<<"c1=c2++"<<endl;
    cout<<"c1 count= "<<c1.getCount()<<endl;
    cout<<"c1 step= "<<c1.getSteps()<<endl;

    c1.resetCount();
    cout<<c1.getCount()<<endl;
}
