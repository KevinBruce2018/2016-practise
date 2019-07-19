#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    vector<char>cs;
    char c;
    int t;
    while((c=getchar())!='\n')
        cs.push_back(c);
    cin>>t;
    t = t%cs.size();
    for(int i = t;i < cs.size();i++)
        cout<<cs[i];
    for(int i = 0;i < t;i++)
        cout<<cs[i];
    cout<<endl;
    return 0;
}