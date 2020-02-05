#include<iostream>
#include<vector>
#define INF 0x3f3f3f3f
using namespace std;
int n;
vector<int> pre(600,-1);
int team_num[600];//每个城市拥有的救援队的数量
int visit[600]={0};
vector<int> dis(600,INF);
vector< vector<int> >graph(600,vector<int>(600,INF));
int sec_team[600];//最多能到的救援队
vector<int> load(600,1);//最短路径的条数

void dijkstra(int source)
{
    //初始化
    visit[source] = 1;
    for(int i = 0;i < n;i++)
    {
        dis[i] = graph[source][i];
        pre[i] = source;
        sec_team[i] = team_num[i];
        if(graph[source][i]!=INF&&source!=i)
            sec_team[i]+=team_num[source];
    }
    pre[source] = -1;
    //加入其他点
    for(int i = 0;i < n-1;i++)
    {
        int min_value = INF+1,min_pos = 0;
        for(int j = 0;j < n;j++)
        {
            if(dis[j]<min_value&&!visit[j])
            {
                min_value = dis[j];
                min_pos = j;
            }
        }
        visit[min_pos] = 1;
        for(int j = 0;j < n;j++)
        {
            if(min_pos==j) continue;
            if(graph[min_pos][j]+dis[min_pos]<dis[j])
            {
                pre[j] = min_pos;
                dis[j] = graph[min_pos][j]+dis[min_pos];
                load[j] = load[min_pos];
                sec_team[j]=sec_team[min_pos]+team_num[j];
            }
            else if(graph[min_pos][j]+dis[min_pos]==dis[j])
            {
                load[j] += load[min_pos];
                if(sec_team[min_pos]+team_num[j]>sec_team[j])
                {
                    sec_team[j]=sec_team[min_pos]+team_num[j];
                    pre[j] = min_pos;
                }
            }
        }
    }
}
int main()
{
    int m,s,d;
    cin>>n>>m>>s>>d;
    for(int i = 0;i < n;i++){
        cin>>team_num[i];
        graph[i][i] = 0;
    }
    for(int i = 0;i < m;i++)
    {
        int a,b,t;
        cin>>a>>b>>t;
        graph[a][b] = graph[b][a] = t;
        //graph[i][i] = 0;
    }
    dijkstra(s);
    cout<<load[d]<<" "<<sec_team[d]<<endl;
    int rlt[600],tmp=d,index=0;
    while (tmp!=-1)
    {
        rlt[index++] = tmp;
        tmp = pre[tmp];
    }
    tmp = 0;
    for(int i = index-1;i>=0;i--)
    {
        if(tmp++) cout<<" ";
        cout<<rlt[i];
    }
    cout<<endl;
    return 0;
}
