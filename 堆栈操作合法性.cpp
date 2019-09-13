#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n,m;
    cin>>n>>m;
    getchar();
    stack<int>stk;
    for(int i = 0;i < n;i++)
    {
        //初始化操作
        string s;
        bool flag = true;
        while (!stk.empty())
            stk.pop();
        cin>>s;
        
        //进行出栈和入栈操作
        for(int j = 0;j < s.length();j++)
        {
            if(s[j]=='S')
            {
                if(stk.size()==m)
                {
                    flag = false;
                    break;
                }
                else
                    stk.push(1);
            }
            else
            {
                if(stk.empty())
                {
                    flag = false;
                    break;
                }
                else
                    stk.pop();
            }
            
        }
        //状态正常且栈空
        if(flag&&stk.empty())
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
