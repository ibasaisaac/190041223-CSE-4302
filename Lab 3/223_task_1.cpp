#include<bits/stdc++.h>
using namespace std;

class Counter
{
private:
    int count;
    int steps;
public:
    Counter():count(0)
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
    void increment()
    {
        count+=steps;
    }
    void resetCount()
    {
        count=0;
    }
};

int main()
{
    Counter c1;
    cout<<c1.getCount()<<endl;
    int x;
    while(1)
    {
        cin>>x;
        if(x==-1)
            break;
        c1.setIncrementStep(x);
        c1.increment();
        cout<<c1.getCount()<<endl;
    }
    c1.resetCount();
    cout<<c1.getCount()<<endl;
}
