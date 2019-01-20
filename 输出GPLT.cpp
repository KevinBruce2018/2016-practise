#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    string s;
    int g = 0,p = 0,l = 0,t = 0;
    getline(cin,s);
    for(int i = 0;i < s.length();i++)
    {
        if(tolower(s[i])=='g')
            g++;
        else if(tolower(s[i])=='p')
            p++;
        else if(tolower(s[i])=='l')
            l++;
        else if(tolower(s[i])=='t')
            t++;
    }
    while(g||p||l||t)
    {
        if(g) {
            cout<<'G';
            g--;
        }
        if(p) {
            cout<<'P';
            p--;
        }
        if(l) {
            cout<<'L';
            l--;
        }
        if(t) {
            cout<<'T';
            t--;
        }
    }
    return 0;
}
