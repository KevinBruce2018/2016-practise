#include <bits/stdc++.h>
using namespace std;

vector<int>parent(100001,-1);
vector<int>beifen(100001,0);
int find(int i)
{
    //及时记录有效数据 防止超时
    if(parent[i]==-1)
        beifen[i] = 1;
    if(beifen[i]==0)
        beifen[i]  = 1+find(parent[i]);
    return beifen[i];
}
int main(void)
{
    int n;
    cin>>n;

    for(int i = 1;i<=n;i++)
        cin>>parent[i];
    int max = 0;
    //确定辈分
    for(int i = 1;i <=n;i++)
        find(i);
    for(int i = 1;i<=n;i++)
        if(beifen[i]>max)
            max = beifen[i];
    cout<<max<<endl;
    int tmp = 0;
    //输出最小辈分
    for(int i = 1;i <=n;i++)
    {
        if(beifen[i]==max)
        {
            if(tmp)
                cout<<" ";
            cout<<i;
            tmp++;
        }
    }
    return 0;
}
