#include<iostream>
#include<fstream>
using namespace std;

class Person
{
private:
    string name;
    int age;
public:
    Person():name(""),age(0)
    {

    }
    virtual void getdata()
    {
        cout<<"Name: ";
        cin>>name;
        cout<<"Age: ";
        cin>>age;
    }
    virtual void print()
    {
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
    }
    virtual void diskIn()
    {
        ifstream infile;
        infile.open("person.dat",ios::binary);
        infile.read(reinterpret_cast<char*>(this), sizeof(*this));
    }
    virtual void diskOut()
    {
        ofstream outfile;
        outfile.open("person.txt",ios::binary|ios::app);
        outfile.write(reinterpret_cast<char*>(this),sizeof(*this));
    }

};
class Student: public Person
{
private:
    string dept;
    float cgpa;
public:
    Student():dept(""),cgpa(0)
    {

    }
    void getdata()
    {
        Person::getdata();
        cout<<"Department: ";
        cin>>dept;
        cout<<"CGPA: ";
        cin>>cgpa;
    }
    void print()
    {
        cout<<"\nDisplaying student info"<<endl;
        Person::print();
        cout<<"Department: "<<dept<<endl;
        cout<<"CGPA: "<<cgpa<<endl;
    }
};
class Faculty: public Person
{
private:
    string des;
public:
    void getdata()
    {
        Person::getdata();
        cout<<"Designation: ";
        cin>>des;
    }
    void print()
    {
        cout<<"\nDisplaying faculty info"<<endl;
        Person::print();
        cout<<"Designation: "<<des<<endl;
    }
};

int main()
{
    //Person pers;
    Person *p[10];
    char ch;
    int i=0;
    do
    {
        cout<<"\ns or f?\n";
        cin>>ch;
        if(ch=='s')
        {
            cout<<"Student Info"<<endl;
            p[i]=new Student;
        }
        else if(ch=='f')
        {
            cout<<"Faculty Info"<<endl;
            p[i]=new Faculty;
        }
        p[i]->getdata();
        p[i]->diskOut();
        p[i]->diskIn();
        p[i]->print();
        i++;

    }while(ch=='s'||ch=='f');
    for(int i=0;i<10;i++)
    {
        delete p[i];
    }
}
