#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int n;
    int height,weight;
    cin>>n;
    for(int i = 0;i < n;i++)
    {
        cin>>height>>weight;
        double perfect = (height-100)*1.8;
        if(fabs(perfect-weight)<perfect/10)
            cout<<"You are wan mei!"<<endl;
        else if(perfect>weight)
            cout<<"You are tai shou le!"<<endl;
        else
            cout<<"You are tai pang le!"<<endl;
    }
    return 0;
}