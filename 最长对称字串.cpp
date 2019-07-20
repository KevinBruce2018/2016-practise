#include<bits/stdc++.h>
using namespace std;

int main(void)
{
	string str;
    int longest,long2;
	int max = 0;

	getline(cin,str);

	for(int i = 0;i < str.length();i++)
	{
		//分奇数串和偶数串两种情况考虑
        longest = 1;
		for(int j =i+1 ;j <str.length();j++)
		{
			if(j-2*i>0 || str[j]!=str[2*i-j])
				break;
			longest += 2;
		}	
		if(longest>max)
			max = longest;
        //偶数串
		long2 = 0;
		for(int  j = i;j < str.length();j++)
		{
			if(j-2*i-1>0 || str[j]!=str[2*i-j-1])
				break;
			long2 += 2;
		}

		if(long2>max)
			max = long2;
	}
	
	cout<<max<<endl;

	return 0;
}