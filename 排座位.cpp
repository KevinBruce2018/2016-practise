#include<bits/stdc++.h>
using namespace std;
//并查集大法非常适合表示集合关系
int find(int value,vector<int>parent)
{
    while(parent[value]>-1)
        value = parent[value];
    return value;
}

int main(void)
{
    int n,m,k,code;
    cin>>n>>m>>k;
    int real[101][101]={0};//利用邻接矩阵存储敌对关系
    vector<int>parent(n+1,-1);//借助树确定是不是在一个集合中
    for(int i = 0;i < m;i++)
    {
        int a,b,r;
        cin>>a>>b>>r;
        if(r==-1)
            real[a][b] = real[b][a] = -1;
        else//朋友关系借助并查集来存到一个集合中
        {
            int v1 = find(a,parent);
            int v2 = find(b,parent);
            if(v1!=v2)
                parent[v2] = v1;
        }
    }
    for(int i = 0;i < k;i++)
    {
        int a,b;
        cin>>a>>b;
        int v1 = find(a,parent);
        int v2 = find(b,parent);
        if(real[a][b]==-1)//敌对
        {
            if(v1==v2)//确定有无公共朋友
                cout<<"OK but..."<<endl;
            else
                cout<<"No way"<<endl;
        }
        else//不敌对
        {
            if(v1==v2)
                cout<<"No problem"<<endl;
            else
                cout<<"OK"<<endl;
        }
    }
    return 0;
}
