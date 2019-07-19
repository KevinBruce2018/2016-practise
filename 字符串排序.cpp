#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    vector<string>arr(5);
    for(int i = 0;i < 5;i++)
        cin>>arr[i];
    sort(arr.begin(),arr.end());
    cout<<"After sorted:\n";
    for(int i = 0;i < 5;i++)
        cout<<arr[i]<<endl;
    return 0;
}