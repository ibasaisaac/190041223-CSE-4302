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
        if(p==0)
        {
            cout<<"error"<<endl;
        }
        p=numerator;
        q=denominator;
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
    r1.print();
}
