#include<bits/stdc++.h>
using namespace std;

class RationalNumber
{
private:
    int p,q;
public:
    RationalNumber():p(1),q(1)
    {

    }
    void assign(int numerator, int denominator)
    {
        p=numerator;
        q=denominator;
        if(p==0)
        {
            cout<<"error"<<endl;
        }
    }
    double convert()
    {
        double d = ((double)p/(double)q);
        return d;
    }
    void print()
    {
        cout<<p<<"/"<<q<<endl;
    }
    void invert()
    {
        int temp;
        temp=p;
        p=q;
        q=temp;
    }
};

int main()
{
    RationalNumber r1;
    int n,d;
    cin>>n>>d;
    r1.assign(n,d);
    r1.print();
    cout<<r1.convert()<<endl;
    r1.invert();
    cout<<r1.convert()<<endl;
}
