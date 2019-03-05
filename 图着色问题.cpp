#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>graph(501,vector<int>(501,0));

int main(void)
{
    int v,edge,num;
    cin>>v>>edge>>num;
    bool flag;
    vector<int>color(v+1,0);
    for(int i = 0;i < edge;i++)
    {
        int x,y;
        cin>>x>>y;
        graph[x][y] = graph[y][x] = 1;
    }
    int n;
    cin>>n;
    for(int i = 0;i < n;i++)
    {
        set<int>s;
        for(int j = 1;j <= v;j++){
            cin>>color[j];
            s.insert(color[j]);
        }
        //颜色与所需颜色不同是不可以的
        if(s.size()!=num){
            cout<<"No"<<endl;
            continue;
        }
        flag = true;
        //看每两个点之间联通的点之间颜色是否相同
        for(int j = 1;j <= v &&flag;j++)
        {
            for(int k=1;k < j;k++)
            {
                if(graph[j][k])
                    if(color[j]==color[k])
                        flag = false;
            }
        }
        if(flag)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}