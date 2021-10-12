#include<iostream>
using namespace std;

template<class T>
T amax(T *arr, int sz)
{
    T m=arr[0];
    for(int i=0;i<sz;i++)
    {
        if(arr[i]>m)
        {
            m=arr[i];
        }
    }
    return m;
}

int main()
{
    int arr1[]={5,8,6,41,23,18};
    int sz1= sizeof(arr1)/sizeof(arr1[0]);
    int larg1=amax(arr1,sz1);
    cout<<"For int max is: "<<larg1<<endl;

    float arr2[]={5.12,8.16,9.99};
    int sz2= sizeof(arr2)/sizeof(arr2[0]);
    float larg2=amax(arr2,sz2);
    cout<<"For float max is: "<<larg2<<endl;
}
