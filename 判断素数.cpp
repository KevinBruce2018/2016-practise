#include<bits/stdc++.h>
using namespace std;

bool isprime(long n)
{
    if(n==1)
        return false;
    long k = sqrt(n);
    for(long i = 2;i <= k;i++)
        if(n%i==0)
            return false;
    return true;
}

int main(void)
{
    int n;
    cin>>n;
    for(int i = 0;i < n;i++)
    {
        long num;
        cin>>num;
        if(isprime(num))
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
