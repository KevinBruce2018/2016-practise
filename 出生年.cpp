#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    //没啥好说的，注意细节就好
    //小规模去重用set比较方便
	int year,temp,diff,count=0;
    set<int>s;
	cin>>year>>diff;
    while(s.size()!=diff){
        temp = year;
        s.clear();
        for(int i = 0;i < 4;i++,temp/=10)
            s.insert(temp%10);
        year++;
        count++;
    }
    printf("%d %04d\n",count-1,year-1);
	return 0;
}