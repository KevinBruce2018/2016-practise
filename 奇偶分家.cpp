#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n,count=0;
    cin>>n;
    for(int i = 0;i < n;i++)
    {
        int num;
        cin>>num;
        if(num%2!=0)
            count++;
    }
    cout<<count<<" "<<n - count<<endl;
    return 0;
}
