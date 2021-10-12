#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[]={4,6,12,88,2};
    sort(arr,arr+5);
    set<int>s;
    s.insert(5);
    s.insert(11);
    s.insert(3);
    vector<int>v(8);
    vector<int>::iterator it;
    merge(arr,arr+5,s.begin(),s.end(),v.begin());
    for(it=v.begin();it!=v.end();it++)
    {
        cout<<*it<<" ";
    }
}
