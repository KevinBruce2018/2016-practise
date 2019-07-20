#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a,b;
    getline(cin,a);
    getline(cin,b);

    int c[128] ={0};

    for(int i = 0;i< b.length();i++)
        c[(int)b[i]] = 1;
    for(int i = 0;i < a.length();i++)
        if(!c[(char)a[i]])
            cout<<a[i];
    
    return 0;
}