#include<bits/stdc++.h>
using namespace std;

void heap(int* a,int n) //以插入的方式建立一个小顶堆
{
    for(int i = 1;i <= n;i++)
    {
        cin>>a[i];
        int tmp = i;
        while(tmp/2>0 && a[tmp]<a[tmp/2])
        {
            int t = a[tmp];
            a[tmp] = a[tmp/2];
            a[tmp/2] = t;
            tmp/=2;
        }
    }
}
int main(void)
{
    int n,m,num1,num2;
    string s;
    map<int,int>ma;
    cin>>n>>m;
    int a[1001]={0};
    heap(a,n);
    for(int i = 1;i <= n;i++)
        ma[a[i]] = i;//建立值与下标的对应关系
    for(int i = 0;i < m;i++){     
        cin>>num1>>s;
        if(s=="is")
        {
            cin>>s>>s;
            if(s=="root")
            {
                if(ma[num1]==1)
                    cout<<"T"<<endl;
                else
                    cout<<"F"<<endl;
            }
            else if(s=="parent")
            {
                cin>>s>>num2;
                if(ma[num2]/2!=ma[num1])
                    cout<<"F"<<endl;
                else
                    cout<<"T"<<endl;
            }
            else
            {
                cin>>s>>num2;  
                if(ma[num1]/2==ma[num2])
                    cout<<"T"<<endl;
                else
                    cout<<"F"<<endl;
            }
        }
        else
        {
            cin>>num2;
            getline(cin,s);
            if(ma[num1]/2==ma[num2]/2)
                cout<<"T"<<endl;
            else
                cout<<"F"<<endl;
        }
    }
    return 0;
}