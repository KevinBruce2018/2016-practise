#include<bits/stdc++.h>

using namespace std;

int main(void)
{
    int n,num=0,count=0;
    string s;
    char a[101][101]={0};
    cin>>n;//读取行
    getchar();
    getline(cin,s);
    //求得列
    if(s.length()%n!=0)
        s += string(n-s.length()%n,' ');
    num = s.length()/n;
    for(int i = num-1;i >= 0;i--) //列遍历
        for(int j = 0;j < n;j++)
            a[j][i] = s[count++];
    for(int i = 0;i < n;i++)
        cout<<a[i]<<endl;
}