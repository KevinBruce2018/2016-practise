#include <bits/stdc++.h>

using namespace std;
double energy[100005]= {0};
vector<int>parent(100005,0);
double getEneygy(int i,double r)
{
    if(energy[i]==0){
            energy[i] = (1-r/100)*getEneygy(parent[i],r);
        return energy[i];
    }
    else
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

    double sum = 0;
    for(int i = 0;i < n;i++)
    {
        if(flag[i]!=0)
            sum += getEneygy(i,r)*flag[i];
    }
    cout<<(int)sum<<endl;
    return 0;
}
