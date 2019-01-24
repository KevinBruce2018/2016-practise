#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int n,m,k;
    cin>>n>>m>>k;
    double a[10001];
    for(int i = 0;i < n;i++)
    {
        int sum = 0,score;
        int min = 999,max=-1;
        for(int j = 0;j < m;j++){
            cin>>score;
            sum+=score;
            if(score>max)
                max = score;
            if(score<min)
                min = score;
        }
        a[i] = (sum-min-max)*1.0/(m-2);
    }
    sort(a,a+n);
    for(int i = n-k;i<n;i++)
    {
        if(i!=n-1)
            printf("%.3lf ",a[i]);
        else
            printf("%.3lf\n",a[i]);
    }
    return 0;
}