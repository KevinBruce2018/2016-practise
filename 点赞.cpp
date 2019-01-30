#include<bits/stdc++.h>
using namespace std;
typedef struct blog{
    int label;
    int count = 0;
}blog;
bool cmp(blog b1,blog b2)
{
    if(b1.count!=b2.count)
        return b1.count > b2.count;
    else
        return b1.label > b2.label;
}
int main(void)
{
  int n;
  cin>>n;
  blog* b = new blog[1001];
  for(int i = 0;i < 1001;i++)
    b[i].label = i;
  for(int i = 0;i < n;i++)
  {
      int m,k;
      cin>>m;
      for(int j = 0;j < m;j++){
        cin>>k;
        b[k].count++;
      }
  }
  sort(b,b+1001,cmp);
  cout<<b[0].label<<' '<<b[0].count<<endl;
  return 0;
}