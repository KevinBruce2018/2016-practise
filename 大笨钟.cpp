#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int hour,min,n;
    scanf("%d:%d",&hour,&min);
    if((hour>=0&&hour<12) || (hour==12&&min==0))
        printf("Only %02d:%02d.  Too early to Dang.\n",hour,min);
    else
    {
        n = min==0?hour - 12:hour - 12 +1;
        for(int i = 0;i < n;i++)
            cout<<"Dang";
        cout<<endl;
    }
    return 0;
}
