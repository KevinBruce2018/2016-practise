#include<bits/stdc++.h>
using namespace std;
int visit[501];
int a[501][501]={0};
void dfs(int n,int i)//深度优先遍历
{
    visit[i] = 1;
    for(int j = 0;j < n;j++)
        if(a[i][j]==1&&!visit[j])
            dfs(n,j);
}
int connect(int n)//求联通分支数
{
    int count = 0;
    for(int i = 0;i < n;i++)
    {
        if(!visit[i])
            count++;
        dfs(n,i);
        bool flag = false;
        for(int j = 0;j < n;j++)
        {
            if(visit[j]==0)
            {
                flag = true;
                break;
            }
        }
        if(!flag)
            break;
    }
    memset(visit,0,sizeof(visit));
    return count;
}
int main(void)
{
    int n,m,k,count=0;
    cin>>n>>m;
    for(int i = 0;i < m;i++)//建立邻接矩阵存储的图
    {
        int x,y;
        cin>>x>>y;
        a[x][y] = a[y][x] = 1;
    }
    cin>>k;
    count = connect(n);//记录初始的连通分支数
    for(int i = 0;i < k;i++)
    {
        int x;
        cin>>x;
        for(int j = 0;j < n;j++)//切断失去城市和其他城市的联系
            a[x][j] = a[j][x] = 0;
        int num = connect(n);
        if(num>count+1)
            cout<<"Red Alert: City "<<x<<" is lost!"<<endl;
        else//如果连通分支数量不变(删掉了一个孤立城市)或连通分支数+1(失去了一个普通的城市)
            cout<<"City "<<x<<" is lost."<<endl;
        count = num;//更新连通分支的数量
        if(i==n-1)
            cout<<"Game Over."<<endl;
    }
    return 0;
}