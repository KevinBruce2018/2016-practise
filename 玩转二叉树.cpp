#include<bits/stdc++.h>
using namespace std;
typedef struct bitnode{
    struct bitnode *lchild,*rchild;
    int data;
}bitnode,*bitree;
int in[30],pre[30];
void preorder(bitree root)//镜面翻转
{
    if(root==NULL)
        return;
    bitree t = root->lchild;
    root->lchild = root->rchild;
    root->rchild = t;
    preorder(root->lchild);
    preorder(root->rchild);
}
bitree restore(int i1,int i2,int p1,int p2)//二叉树恢复
{
    bitree root = (bitree)malloc(sizeof(bitnode));
    root->lchild = root->rchild = NULL;
    root->data = pre[p1];
    for(int i = i1;i <= i2;i++)
    {
        if(in[i]==pre[p1])
        {
            if(i!=i1)//存在左子树
                root->lchild = restore(i1,i-1,p1+1,p1+i-i1);
            if(i!=i2)//存在右子树
                root->rchild = restore(i+1,i2,p1+i-i1+1,p2);
            break;
        }
    }
    return root;
}

int main(void)
{
    int n,count=0;
    queue<bitree>bt;
    cin>>n;
    for(int i = 0;i < n;i++)
        cin>>in[i];
    for(int i = 0;i < n;i++)
        cin>>pre[i];
    bitree root = restore(0,n-1,0,n-1);
    preorder(root);
    bt.push(root);
    while(!bt.empty())//借助队列实现层次遍历
    {
        if(count)
            cout<<" ";
        count++;
        cout<<bt.front()->data;
        bitree temp = bt.front();
        bt.pop();
        if(temp->lchild)
            bt.push(temp->lchild);
        if(temp->rchild)
            bt.push(temp->rchild);
    }
    return 0;
}
