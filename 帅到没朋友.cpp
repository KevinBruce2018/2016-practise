#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n,m,k,code;
    cin>>n;
    vector<int>num(100000,0);//出现次数
    for(int i = 0;i < n;i++)
    {
        cin>>k;
        if(k!=1) {
            for(int j = 0; j < k;j++)
            {
                cin>>code;
                num[code]++;
            }
        }
        else
            cin>>code;//只有一个人的数据也要读进来
    }
    int count = 0;
    cin>>m;
    for(int i = 0;i < m;i++)
    {
        cin>>code;
        if(num[code]!=-1)//用-1来标记被查询过的数据
        {
            if(num[code]==0){
                if(count)
                    cout<<" ";
                count++;
                printf("%05d",code);//如果数据较小的话需要补0
            }
            num[code] = -1;
        }
    }
    if(!count)
        cout<<"No one is handsome"<<endl;
    return 0;
}
