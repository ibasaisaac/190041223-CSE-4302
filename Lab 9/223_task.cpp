#include<iostream>
using namespace std;

class Furniture
{
protected:
    int regPrice,discPrice;
    string material;
    string productName;
public:
    Furniture()
    {
        regPrice=0;
        discPrice=0;
        material="";
    }
    virtual void getData()
    {
        cout<<"Enter Regular Price= ";
        cin>>regPrice;
        cout<<"Enter discount price= ";
        cin>>discPrice;
        cout<<"Enter type of material= ";
        cin>>material;
    }
    virtual void putData()
    {
        cout<<"Regular price: "<<regPrice<<endl;
        cout<<"Discount price: "<<discPrice<<endl;
        cout<<"Material: "<<material<<endl;
    }
    virtual void productDetail() ///task 3
    {
        cout<<"Furniture"<<endl;
    }
    int getDiscount() ///task 4 to sort
    {
        return discPrice;
    }
};

class Bed:public Furniture
{
private:
    string BedSize;
public:
    Bed()
    {
        BedSize="";
    }
    void getData()
    {
        Furniture::getData();
        cout<<"Enter bed size (Single/SemiDouble/Double)= ";
        cin>>BedSize;
    }
    void putData()
    {
        Furniture::putData();
        cout<<"Bed size: "<<BedSize<<endl;
    }
    void productDetail()
    {
        cout<<"Product name: Bed"<<endl;
    }
};

class Sofa: public Furniture
{
private:
    string SeatNumber;
public:
    Sofa()
    {
        SeatNumber="";
    }
    void getData()
    {
        Furniture::getData();
        cout<<"Enter seat number(One/Two/Three/Four/Five)= ";
        cin>>SeatNumber;
    }
    void putData()
    {
        Furniture::putData();
        cout<<"Seat number: "<<SeatNumber<<endl;
    }
    void productDetail()
    {
        cout<<"Product name: Sofa"<<endl;
    }
};

class DiningTable:public Furniture
{
private:
    string ChairCount;
public:
    DiningTable()
    {
        ChairCount="";
    }
    void getData()
    {
        Furniture::getData();
        cout<<"Enter chair count(Two/Four/Six)= ";
        cin>>ChairCount;
    }
    void putData()
    {
        Furniture::putData();
        cout<<"Chair count: "<<ChairCount<<endl;
    }
    void productDetail()
    {
        cout<<"Product name: Dining table"<<endl;
    }
};

void order(Furniture **f1, Furniture **f2)
{          ///passing the pointer of the base class. To pass pointers, we need double pointer.

    if((*f1)->getDiscount() < (*f2)->getDiscount())
    {
        Furniture *temp;
        temp=*f1;
        *f1 = *f2;
        *f2 = temp;
        //not moving the objects, rather moving the pointers to objects.
    }
}

void sort_furniture_price(Furniture **ff, int n)
{                         //passing the address of the array furptr.
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            order(ff+i,ff+j);
        }
    }
}

int main()
{
    Furniture *furptr[100]; //base class pointer
    char choice;
    int n=0; //keep track of the no. of furniture

    do
    {
        cout<<"Which furniture (b for bed/s for sofa/d for dining table): ";
        cin>>choice;

        //using base class pointer to access derived class object
        if(choice=='b')
        {
            furptr[n]=new Bed;
        }
        else if(choice=='s')
        {
            furptr[n]=new Sofa;
        }
        else
        {
            furptr[n]=new DiningTable;
        }

        furptr[n]->getData();
        n++;

        cout<<"Enter another furniture(y/n): ";
        cin>>choice;
    }while(choice=='y');

    sort_furniture_price(furptr,n);///sorting

    ///printing in descending order of discount price
    for(int i=0;i<n;i++)
    {
        cout<<"\n---------------------------------\n";
        furptr[i]->productDetail();
        furptr[i]->putData();
        cout<<"#################################\n\n";
    }

    //deallocating the memory space
    for(int i=0;i<n;i++)
    {
        delete furptr[i];
        //cout<<"d"<<endl;
    }
}
