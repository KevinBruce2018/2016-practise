#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    string phone;
    cin>>phone;
    int a[10] = {0},n=0;
    queue<int>q;//存储所有号码
    map<int,int>m;//存储号码和下标
    //记录所有出现的数字
    for(int i = 0;i < phone.length();i++)
        a[phone[i]-'0']++;
    for(int i = 9;i >= 0;i--)
        if(a[i]){
            q.push(i);
            n++;
        }
    cout<<"int[] arr = new int[]{";
    //存储号码和下标的对应关系，并打印所有号码
    for(int i = 0;i < n;i++)
    {
        m[q.front()] = i;
        cout<<q.front();
        if(i!=n-1)
            cout<<",";
        q.pop();
    }
    cout<<"};\nint[] index = new int[]{";
    for(int i = 0;i<11;i++)
    {
        cout<<m[phone[i]-'0'];
        if(i!=10)
            cout<<",";
    }
    cout<<"};"<<endl;
    return 0;
}