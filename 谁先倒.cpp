#include<bits/stdc++.h>
using namespace std;
struct guess{
	int voice;//喊
	int out;//划
	int volume;//酒量
	int drink = 0;//已经喝的酒
}per[2];

int main(void)
{
	int n;
	cin>>per[0].volume>>per[1].volume>>n;
	for(int i = 0;i < n;i++)
	{
		int sum;
        cin>>per[0].voice>>per[0].out>>per[1].voice>>per[1].out;
		sum = per[0].voice+per[1].voice;
		if(!((per[0].out==sum && per[1].out==sum) || per[0].out!=sum&&per[1].out!=sum))
		{
			if(per[0].out==sum) {
				per[0].drink++;
				if(per[0].drink==per[0].volume+1)
				{
                    cout<<"A\n"<<per[1].drink<<endl;
					break;
				}
			}
			if(per[1].out==sum) {
				per[1].drink++;
				if(per[1].drink==per[1].volume+1)
				{
					cout<<"B\n"<<per[0].drink<<endl;
					break;
				}
			}
		}
	}
	return 0;
}
