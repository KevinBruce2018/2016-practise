#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int n;
    string c;
    cin>>n>>c;
    //先求沙漏的层数
    int k = sqrt((n+1)/2);
    //多余的字符
    int left = n - (2*k*k-1);
    //打印沙漏
    for(int i = 0;i < k;i++)
    {
        for(int j = 0;j < i;j++)
            cout<<" ";
        for(int j = 0;j < 2*(k-i)-1;j++)
            cout<<c;
        cout<<endl;
    }
    for(int i = 1;i <= k-1;i++)
    {
        for(int j = 0;j < k - i - 1;j++)
            cout<<" ";
        for(int j = 0;j < 2*(i+1)-1;j++)
            cout<<c;
        cout<<endl;
    }
    cout<<left<<endl;
    return 0;
}