#include<bits/stdc++.h>
using namespace std;

int gys(int a,int b)
{
    return a%b==0?b:gys(b,a%b);
}
void simple(int* a,int* b)
{
    int g = gys(abs(*a),abs(*b));
    *a/=g;
    *b/=g;
}

int main(void)
{
    //freopen("1.txt","r",stdin);
    int a,b,n;
    cin>>n;
    scanf("%d/%d",&a,&b);
    
    simple(&a,&b);

    for(int i = 0;i < n-1;i++)
    {
        int c,d;
        scanf("%d/%d",&c,&d);
        //及时化简，防止数值太大而溢出
        simple(&c,&d);
        a = (a*d+b*c);
        b = (b*d);
        simple(&a,&b);
    }
    b *= n;
    simple(&a,&b);
    if(b==1)
        cout<<a<<endl;
    else
        cout<<a<<"/"<<b<<endl;
    
    return 0;
}