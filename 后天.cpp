#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;
    cin>>n;
    n = n>5?(n+2)%7:n+2;
    cout<<n;
    return 0;
}
