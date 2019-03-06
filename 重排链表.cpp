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
    int head,n;
    stack<node>stak;
    queue<node>q;
    cin>>head>>n;
    //构建链表
    
    for(int i = 0;i < n;i++)
    {
        int current;
        cin>>current;
        lists[current].current = current;
        cin>>lists[current].value>>lists[current].next;
    }
    n = 1;
    int tmp=head;
    //可能有多余结点
    while(lists[tmp].next!=-1)
    {
        tmp = lists[tmp].next;
        n++;
    }
    tmp = head;
    for(int i = 1;i<= n/2;i++)
    {
        q.push(lists[tmp]);
        tmp = lists[tmp].next;
    }
    for(int i = n/2+1;i<=n;i++)
    {
        stak.push(lists[tmp]);
        tmp = lists[tmp].next;
    }
    while(!q.empty()){
        printf("%05d %d %05d\n",stak.top().current,stak.top().value,q.front().current);
        printf("%05d %d ",q.front().current,q.front().value);
        q.pop();
        stak.pop();
        if(stak.empty())
            cout<<"-1"<<endl;
        else
            printf("%05d\n",stak.top().current);
    }
    //如果栈中的数据有奇数个
    if(!stak.empty())
        printf("%05d %d %d\n",stak.top().current,stak.top().value,-1);
    return 0;
}