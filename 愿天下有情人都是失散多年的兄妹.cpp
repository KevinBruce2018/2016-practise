#include<bits/stdc++.h>
using namespace std;
typedef struct family
{
	int dad = -1,mom = -1;
	char sex = 'M';
}fmy;
fmy *f = new fmy[100000];

bool ishandw(int n,int id1,int id2)
{
    //往上走了4代都没关系 或者某支的父母已不可考
    if(n>4 || id1==-1 ||id2==-1)
        return true;
    //注意处理-1的情况
    if((f[id1].dad!=-1&&f[id1].dad==f[id2].dad) || (f[id1].mom!=-1&&f[id1].mom==f[id2].mom))
        return false;
    return ishandw(n+1,f[id1].mom,f[id2].mom)&&ishandw(n+1,f[id1].dad,f[id2].dad)&&ishandw(n+1,f[id1].mom,f[id2].dad)&&ishandw(n+1,f[id1].dad,f[id2].mom);
    
}
int main(void)
{
	int n,m;
	scanf("%d",&n);
	
	for(int i = 0;i < n;i++)
	{
		int id;
        scanf("%d ",&id);
        scanf("%c %d %d%*c",&f[id].sex,&f[id].dad,&f[id].mom);
        //修改母亲性别  母亲不一定出现在输入数据里 要修改默认值
        if(f[id].mom!=-1)
            f[f[id].mom].sex = 'F';
	}
    scanf("%d",&m);
    for(int i = 0;i < m;i++)
    {
        int id1,id2;
        scanf("%d %d",&id1,&id2);
        if(f[id1].sex == f[id2].sex)
            printf("Never Mind\n");
        else
        {
            bool flag = ishandw(1,id1,id2);
            if(flag)
                printf("Yes\n");
            else
                printf("No\n");
        }
        
    }
	return 0;
}