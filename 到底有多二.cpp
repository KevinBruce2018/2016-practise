#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    string s;
    int count = 0,len;
    double mul = 1;//倍数
    getline(cin,s);
    if(s[0]=='-')
        mul *= 1.5;
    len = s[0]=='-'?s.length()-1:s.length();//数字位数

    for(int i = 0;i < s.length();i++)
        if(s[i]=='2')
            count++;
    if((s[s.length()-1]-'0')%2==0)
        mul *= 2;
    printf("%.2lf%%\n",count*1.0/len*mul*100);
    return 0;
}
