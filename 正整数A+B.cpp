#include<bits/stdc++.h>
using namespace std;

bool judge(char* a)
{
    long n = atol(a);
    if(n>=1&&n<=1000)
        return true;
    else
        return false;
}
int main(void)
{
    char a[1000],b[1000],c;
    int len=0,len2=0;
    bool flag1 = true,flag2 = true;
    //将两个字符串读取进来
    while((c=getchar())!=' ')
    {
        a[len++] = c;
        if(!(c>='0'&&c<='9'))
            flag1 = false;
    }
    a[len] = 0;
    while((c=getchar())!='\n')
    {
        b[len2++] = c;
        if(!(c>='0'&&c<='9'))
            flag2 = false;
    }
    //都是数字，判断范围是否正确
    if(flag1)
        flag1 = judge(a);
    if(flag2)
        flag2 = judge(b);
    //根据不同的情况进行输出。
    if(flag1&&flag2)
        cout<<atol(a)<<" + "<<atol(b)<<" = "<<atol(a)+atol(b)<<endl;
    else if(flag1&&!flag2)
        cout<<atol(a)<<" + "<<"?"<<" = "<<"?"<<endl;
    else if(!flag1&&flag2)
        cout<<"?"<<" + "<<atol(b)<<" = "<<"?"<<endl;
    else
        cout<<"?"<<" + "<<"?"<<" = "<<"?"<<endl;
    return 0;
}