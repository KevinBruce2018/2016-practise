#include<iostream>
using namespace std;
typedef struct family{
    int fid = -1;
    int mid = -1;
    string sex = "M";
}family;
family* f = new family[100000];
bool check(int id1,int id2,int n)
{
    //某个人的父亲或母亲无法考证或者超过代数了
    if(id1==-1||id2==-1||n>4)
        return true;
    if((f[id1].fid!=-1&&f[id1].fid==f[id2].fid)||(f[id1].mid!=-1&&f[id1].mid==f[id2].mid))
        return false;
    return check(f[id1].fid,f[id2].fid,n+1)&&check(f[id1].mid,f[id2].mid,n+1)&&check(f[id1].mid,f[id2].fid,n+1)&&check(f[id1].fid,f[id2].mid,n+1);
}
int main()
{
    int n,k;
    cin>>n;
    for(int i = 0;i < n;i++)
    {
        int id,fid,mid;
        string sex;
        cin>>id>>sex>>fid>>mid;
        f[id].sex = sex;
        f[id].fid = fid;
        f[id].mid = mid;
        //注意修改母亲的性别，因为默认值是男性
        if(f[id].mid!=-1)
            f[f[id].mid].sex = "F";
    }
    cin>>k;
    for (int i = 0; i < k; i++)
    {
        int id1,id2;
        cin>>id1>>id2;
        if(f[id1].sex==f[id2].sex)
            cout<<"Never Mind"<<endl;
        else
        {
            bool flag =  check(id1,id2,1);
            if(flag) cout<<"Yes\n";
            else    cout<<"No\n";
        }   
    }
    return 0;
}
