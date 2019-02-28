#include <bits/stdc++.h>

using namespace std;
double energy[100005]= {0};
vector<int>parent(100005,0);
double getEnergy(int i,double r)
{
    if(energy[i]==0)
            energy[i] = (1-r/100)*getEnergy(parent[i],r);
    return energy[i];
}
int main(void)
{
    int n;
    double first,r;
    scanf("%d %lf %lf",&n,&first,&r);
    //标记得道者
    vector<int>flag(n,0);
    energy[0] = first;
    for(int i = 0;i < n;i++)
    {
        int k;
        scanf("%d",&k);
        if(k==0){
            int N;
            scanf("%d",&N);
            flag[i] = N;
        }
        else
        {
            int student;
            for(int tmp = 0;tmp < k;tmp++)
            {
                scanf("%d",&student);
                parent[student] = i;
            }
        }
    }
    //为避免师傅没出现就被计算的情况，不能边读取边计算
    double sum = 0;
    //为提升计算速度，将每次的中间结果都保存起来
    //具体情况见getEnergy函数定义
    for(int i = 0;i < n;i++)
        if(flag[i]!=0)
            sum += getEnergy(i,r)*flag[i];
    cout<<(int)sum<<endl;
    return 0;
}
