#include<iostream>
using namespace std;

class Matrix3D
{
private:
    //int a,b,c,d,e,f,g,h,i;
    double arr[3][3];
public:
    Matrix3D()
    {
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                arr[i][j]=0;
            }
        }
    }
    Matrix3D(double a, double b, double c, double d, double e, double f, double g, double h, double i)
    {
        arr[0][0]=a;
        arr[0][1]=b;
        arr[0][2]=c;
        arr[1][0]=d;
        arr[1][1]=e;
        arr[1][2]=f;
        arr[2][0]=g;
        arr[2][1]=h;
        arr[2][2]=i;
    }
    ~Matrix3D()
    {

    }
    void getValues()
    {
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                cin>>arr[i][j];
            }
        }
    }
    void display()
    {
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    double det()const;
    Matrix3D inverse();
    Matrix3D operator+(const Matrix3D)const;
    Matrix3D operator-(const Matrix3D)const;
    Matrix3D operator*(const Matrix3D)const;
};
Matrix3D Matrix3D::operator*(const Matrix3D m)const
{
    Matrix3D temp;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            temp.arr[i][j]=arr[i][j]*m.arr[i][j];
        }
    }
    return temp;
}
Matrix3D Matrix3D::operator-(const Matrix3D m)const
{
    Matrix3D temp;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            temp.arr[i][j]=arr[i][j]-m.arr[i][j];
        }
    }
    return temp;
}
Matrix3D Matrix3D::operator+(const Matrix3D m)const
{
    Matrix3D temp;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            temp.arr[i][j]=arr[i][j]+m.arr[i][j];
        }
    }
    return temp;
}
double Matrix3D::det()const
{
    double a,b,c,d,e,f,g,h,i;
    a=arr[0][0];
    b=arr[0][1];
    c=arr[0][2];
    d=arr[1][0];
    e=arr[1][1];
    f=arr[1][2];
    g=arr[2][0];
    h=arr[2][1];
    i=arr[2][2];
    //cout<<arr[0][0]<<b<<c;
    double dt;
    dt=a*(e*i-f*h)-b*(d*i-f*g)+c*(d*h-e*g);
    return dt;
}

Matrix3D Matrix3D::inverse()
{
    Matrix3D temp,inv;
    double dt=det();
    //cout<<dt;
    if(dt!=0)
    {
        double a,b,c,d,e,f,g,h,i;
        a=arr[0][0];
        b=arr[0][1];
        c=arr[0][2];
        d=arr[1][0];
        e=arr[1][1];
        f=arr[1][2];
        g=arr[2][0];
        h=arr[2][1];
        i=arr[2][2];

        temp.arr[0][0]=e*i-h*f;
        temp.arr[0][1]=(-b*i+c*h);
        temp.arr[0][2]=b*f-c*e;
        temp.arr[1][0]=(-d*i+f*g);
        temp.arr[1][1]=a*i-c*g;
        temp.arr[1][2]=(-a*f+c*d);
        temp.arr[2][0]=d*h-e*g;
        temp.arr[2][1]=(-a*h+b*g);
        temp.arr[2][2]=(a*e-b*d);
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                inv.arr[i][j]=temp.arr[i][j]/dt;
            }
        }
        return inv;
    }
    else
    {
        cout<<"Inverse can't be found as determinant=0"<<endl;
        exit(1);
    }
}
int main()
{
    Matrix3D m1,m3,m4;
    Matrix3D m2(2,1,0,4,0,1,2,0,0);
    cout<<"Enter values: ";
    m1.getValues();
    cout<<"m1"<<endl;
    m1.display();
    cout<<"m2"<<endl;
    m2.display();

    cout<<"Determinant= "<<m1.det()<<endl;

    cout<<"Inverse: "<<endl;
    m4=m1.inverse();
    m4.display();

    cout<<"Addition:"<<endl;
    m3=m1+m2;
    m3.display();

    cout<<"Subtraction:"<<endl;
    m3=m1-m2;
    m3.display();

    cout<<"Multiplication:"<<endl;
    m3=m1*m2;
    m3.display();
}
