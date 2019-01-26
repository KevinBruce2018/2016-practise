#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;
    char c;
    string s;
    cin>>n>>c;
    getchar();//该死的回车必须要清理掉啊
    getline(cin,s);
    if(s.length()>=n)
        for(int i = s.length()-n;i < s.length();i++)
            cout<<s[i];
    else
    {
        for(int i = n-s.length();i > 0;i--)
            cout<<c;
        cout<<s;
    }
    cout<<endl;
    return 0;
}