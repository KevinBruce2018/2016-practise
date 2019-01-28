#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n,count = 0;
    cin>>n;
    getchar();
    string s;
    //利用map来表示对应关系简直在适合不过了
    map<string,string>m;
    m["ChuiZi"] = "Bu";
    m["Bu"] = "JianDao";
    m["JianDao"] = "ChuiZi";
    while(cin>>s && s!="End")
    {
        if(count == n){
            cout<<s<<endl;
            count = 0;
        }
        else{
            cout<<m[s]<<endl;
            count++;
        }
    }
}