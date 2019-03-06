#include<bits/stdc++.h>
using namespace std;
//使用并查集
vector<int>parent(10000,-1);
int find(int v)
{
    int t = v;
    while(parent[t]!=-1)
        t = parent[t];
    int i = v,j; 
    while(i!=t){
        j = parent[i];
        parent[i] = t;
        i = j;
    }
    return t;
}

int main(void)
{
    int n,m,count=0,count2=0;
    cin>>n;
    //计算不相交的种群的数量
    for(int i = 0;i < n;i++)
    {
        int k,code,code2;
        cin>>k>>code;
        if(code>count)
            count = code;
        for(int j = 0;j < k - 1;j++)
        {
            cin>>code2;
            if(code2>count)
                count = code2;
            if(find(code2)==code2)
                parent[code2] = code;
            else
                parent[find(code2)] = code;
        }
    }
    for(int i = 1;i <= count;i++)
    {
        if(parent[i]==-1)
            count2++;
    }
    cout<<count<<" "<<count2<<endl;
    cin>>m;
    for(int i = 0;i < m;i++)
    {
        int code1,code2;
        cin>>code1>>code2;
        code1 = find(code1);
        code2 = find(code2);
        if(code1==code2)
            cout<<"Y"<<endl;
        else
            cout<<"N"<<endl;
    }
    return 0;
}