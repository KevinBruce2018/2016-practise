#include<bits/stdc++.h>
using namespace std;
typedef struct{
    int current;
    int next;
    int value;
}node,*linklist;
linklist lists = (linklist)malloc(sizeof(node)*100000);
int main(void)
{
    //freopen("input.txt","r",stdin);
    int head,n,tmp;
    std::ios::sync_with_stdio(false);
    set<int>snum;
    cin>>head>>n;
    queue<node>q1;//不重复的结点
    queue<node>q2;//所有重复节点
    //构建一个假链表
    for(int i = 0;i < n;i++)
    {
        int current;
        cin>>current;
        lists[current].current = current;
        cin>>lists[current].value>>lists[current].next;
    }
    tmp = head;
    //避开多余结点
    while(tmp!=-1)
    {
        if(snum.count(abs(lists[tmp].value))==0)
        {
            snum.insert(abs(lists[tmp].value));
            q1.push(lists[tmp]);
        }
        else
            q2.push(lists[tmp]);
        tmp = lists[tmp].next;
    }
    while(!q1.empty())
    {
        printf("%05d %d",q1.front().current,q1.front().value);
        q1.pop();
        if(q1.empty())
            printf(" -1\n");
        else
            printf(" %05d\n",q1.front().current);
    }
    while(!q2.empty())
    {
        printf("%05d %d",q2.front().current,q2.front().value);
        q2.pop();
        if(q2.empty())
            printf(" -1\n");
        else
            printf(" %05d\n",q2.front().current);
    }
    return 0;
}