#include<bits/stdc++.h>
using namespace std;
typedef struct blog{
    string name;
    int count = 0;//点赞总次数
    set<int>s;//所有标签
}blog;
bool cmp(blog b1,blog b2)
{
    int size1 = b1.s.size(),size2 = b2.s.size();
    if(size1!=size2)
        return size1 > size2;
    else
        return b1.count*1.0/size1 < b2.count*1.0/size2;
}
int main(void)
{
    int n;
    cin>>n;
    blog* b = new blog[n];
    for(int i = 0;i < n;i++)
    {
        getchar();
        int k,m;
        cin>>b[i].name>>k;
        for(int j = 0;j < k;j++)
        {
            cin>>m;
            b[i].s.insert(m);
        }
        b[i].count = k;
    }
    sort(b,b+n,cmp);
    if(n<=3)
    {
        for(int i = 0;i < n-1;i++)
            cout<<b[i].name<<" ";
        cout<<b[n-1].name;
        for(int i = 0;i < 3-n;i++)
            cout<<" -";
        cout<<endl;
    }
    else
    {
        for(int i = 0;i < 2;i++)
            cout<<b[i].name<<" ";
        cout<<b[2].name<<endl;
    }
    
    return 0;
}