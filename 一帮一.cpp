#include<bits/stdc++.h>
using namespace std;
struct student {
    int sex;//性别
    string name;
    int flag = 0;//匹配标记
};
int main(void)
{
    int n;
    cin>>n;
    struct student* s = new struct student[n];
    //下标来起到排名的作用
    for(int i = 0;i < n;i++)
        cin>>s[i].sex>>s[i].name;
    for(int i = 0;i < n;i++)
    {
        if(!s[i].flag)//排名靠前且未被标记
        {
            for(int j = n-1;j > i;j--)
            {
                if(!s[j].flag && s[j].sex!=s[i].sex)//排名靠后，性别不同且未被标记
                {
                    cout<<s[i].name<<" "<<s[j].name<<endl;
                    s[j].flag = 1;
                    break;
                }
            }
        }
        s[i].flag = 1;
    }
    return 0;
}