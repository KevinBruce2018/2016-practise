#include <bits/stdc++.h>
using namespace std;

typedef struct person
{
	string name;
	int num;
}person;
bool cmp(person a,person b)
{
	return a.num > b.num;
}
bool cmp2(person a,person b)
{
	return a.name<b.name;
}
int main(void)
{
	set<string>name;
	int n,m,sum=0,flag=0;
	cin>>n;
	for(int i = 0;i < n;i++)
	{
		string temp;
		cin>>temp;
		name.insert(temp);
	}
	cin>>m;
	person* p = new person[m];
	for(int i = 0;i < m;i++){
		cin>>p[i].name>>p[i].num;
		sum+=p[i].num;
	}
	sum/=m;
	sort(p,p+m,cmp);
	int all = 0;
	for(int i = 0;i < m;i++)
		if(p[i].num>sum)
			all++;
	sort(p,p+all,cmp2);
	for(int i = 0;i < all;i++)
	{
		int nsize = name.size();
		name.insert(p[i].name);
		if(name.size()!=nsize){
			cout<<p[i].name<<endl;
			flag = 1;
		}
	}
	if(!flag)
		cout<<"Bing Mei You"<<endl;
	return 0;
}