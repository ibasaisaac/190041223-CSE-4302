#include<iostream>
using namespace std;
class Array
{
private:
    int *p;
    int len;
public:
    Array()
    {
        len=0;
        p=nullptr;
    }
    Array(int l)
    {
        len=l;
        if(len>0)
        {
            p=new int[len];
            for(int i=0; i<len; i++)
            {
                p[i]=0;
            }
        }
    }
    ~Array()
    {
        delete[] p;
    }
    void putdata()
    {
        int x;
        for(int i=0; i<len; i++)
        {
            cin>>x;
            p[i]=x;
        }
    }
    void print()
    {
        for(int i=0; i<len; i++)
        {
            cout<<p[i]<<" ";
        }
        cout<<endl;
    }
    Array operator= (const Array &a)
    {
        len=a.len;

        p=new int[len];

        for(int i=0; i<len; i++)
        {
            p[i]=a.p[i];
        }
        return *this;
    }
    Array(const Array &a)
    {
        len=a.len;

        p=new int[len];

        for(int i=0; i<len; i++)
        {
            p[i]=a.p[i];
        }
    }
};
int main()
{
    Array a1(3);
    a1.putdata();
    Array a2;
    a2=a1; //assignment
    a1.putdata();
    Array a3=a1; //copy constructor
    a1.print();
    a2.print();
    a3.print();
}
