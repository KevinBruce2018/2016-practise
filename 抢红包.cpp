#include<bits/stdc++.h>
using namespace std;

typedef struct Person
{
    int code;
	int redbag = 0;
	int money = 0;
}person;
bool cmp(person p1,person p2)
{

	if(p1.money != p2.money)
		return p1.money > p2.money;//降序
	else if(p1.redbag != p2.redbag)
		return p1.redbag > p2.redbag;//降序
	else
		return p2.code > p1.code;//升序
}
int main(void)
{
    int n;
    cin>>n;
    person* p = new person[n+1];
    //读取数据
    for(int i = 1;i <= n;i++)
    {
        int k,money,code;
        p[i].code = i;
        cin>>k;
        for(int j = 0;j < k;j++)
        {
            cin>>code>>money;
            p[i].money-=money;
            p[code].money+=money;
            p[code].redbag++;
        }
    }
    sort(p+1,p+n+1,cmp);
    for(int i = 1;i <= n;i++)
		printf("%d %.2lf\n",p[i].code,p[i].money/100.0f);
    return 0;
}
