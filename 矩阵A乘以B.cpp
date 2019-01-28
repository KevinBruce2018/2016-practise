#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int ra,ca,rb,cb;
    //输入数据
    cin>>ra>>ca;
    vector<vector<int>>a(ra,vector<int>(ca,0));
    for(int i = 0;i < ra;i++)
        for(int j = 0;j < ca;j++)
            cin>>a[i][j];
    cin>>rb>>cb;
    vector<vector<int>>b(rb,vector<int>(cb,0));
    for(int i = 0;i < rb;i++)
        for(int j = 0;j < cb;j++)
            cin>>b[i][j];
    if(ca!=rb)
        cout<<"Error: "<<ca<<" != "<<rb<<endl;
    else
    {
        vector<vector<int>>c(ra,vector<int>(cb,0));
        //计算矩阵乘积
        for(int i = 0;i < ra;i++)
            for(int j = 0;j < cb;j++)
                for(int k = 0;k<ca;k++)
                    c[i][j] += a[i][k]*b[k][j];
        //输出
        cout<<ra<<" "<<cb<<endl;
        for(int i = 0;i < ra;i++)
        {
            for(int j = 0;j < cb;j++){
                if(j)
                    cout<<" ";
                cout<<c[i][j];
            }
            cout<<endl;
        }
    }
}