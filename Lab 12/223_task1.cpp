// arrover3.cpp
// creates safe array (index values are checked before access)
// uses overloaded [] operator for both put and get
#include <iostream>
using namespace std;
const int LIMIT = 100; //array size

template<class T>
class safearay
{
private:
    T arr[LIMIT];
public:
    T& operator [](T n) //note: return by reference
    {

        if( n< 0 || n>=LIMIT )
        {
            cout << "\nIndex out of bounds";
            exit(1);
        }
        return arr[n];
    }
};

int main()
{
    safearay<int> sa1;
    for(int j=0; j<LIMIT ; j++) //insert elements
        sa1[j] = j*10; //*left* side of equal sign
    for(int j=0; j<LIMIT; j++) //display elements
    {
        int temp = sa1[j]; //*right* side of equal sign
        cout << "Element " << j << " is " << temp << endl;
    }
    cout<<"\n\n";

    safearay<char> sa2;
    for(int j=0; j<LIMIT; j++) //insert elements
        sa2[j] = 'a'+j; //*left* side of equal sign
    for(int j=0; j<LIMIT; j++) //display elements
    {
        char temp = sa2[j]; //*right* side of equal sign
        cout << "Element " << j << " is " << temp << endl;
    }

    return 0;
}
