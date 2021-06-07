#include<bits/stdc++.h>
using namespace std;

class BankAccount
{
private:
    string name;
    int account_number;
    string type;
    int amount;
public:
    BankAccount() //:name(""),account_number(0),type(""),amount(0)
    {
        name="";
        account_number=0;
        type="";
        amount=0;
    }
    void customerDetails(string cname, int ac)
    {
        name=cname;
        account_number=ac;
    }
    void accountType(string t)
    {
        type=t;
    }
    void balance()
    {
        cout<<amount<<endl;
    }
    void deposit(int m)
    {
        amount+=m;
        cout<<amount<<endl;
    }
    void withdraw(int w)
    {
        cout<<amount<<endl;
        amount-=w;
    }
    void display()
    {
        cout<<"Customer Information"<<endl;
        cout<<"Name of the customer: "<<name<<endl;
        cout<<"Account number: "<<account_number<<endl;
        cout<<"Type of account: "<<type<<endl;
        cout<<"Balance amount in the account: "<<amount<<endl;
    }
};

int main()
{
    BankAccount cus;
    string cname,t;
    int ac,m,w;
    cin>>cname>>ac>>t>>m>>w;
    //name, account number, type of account, deposit, withdraw
    cus.customerDetails(cname,ac);
    cus.accountType(t);
    cus.balance();
    cus.deposit(m);
    cus.withdraw(w);
    cus.display();
}
