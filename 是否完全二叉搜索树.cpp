#include<bits/stdc++.h>

using namespace std;
typedef struct bitnode{
    struct bitnode *lchild = NULL;
    struct bitnode *rchild = NULL;
    int data;
}bitnode,*bitree;
bitree CreateTree(bitree root,int data)//建立一棵二叉排序树
{
    if(!root)
    {
        root = new bitnode;//要想初始化有数据的话只能用new
        root->data = data;
    }
    else if(data > root->data)
        root->lchild = CreateTree(root->lchild,data);
    else
        root->rchild = CreateTree(root->rchild,data);
    return root;
}
int main(void)
{
    bitree root = NULL;
    int n,data,count=0;
    bool isfull = true,mark = false;//mark代表少孩子
    cin>>n;
    for(int i = 0;i < n;i++){
        cin>>data;
        root = CreateTree(root,data);
    }
    //利用队列遍历，顺便检查一下这个树是不是完全二叉树
    queue<bitree>q;
    q.push(root);
    while(!q.empty())
    {
        bool flag1 = false,flag2 = false;//判断树是不是缺孩子
        if(count)
            cout<<" ";
        cout<<q.front()->data;
        count++;
        if(q.front()->lchild)
            q.push(q.front()->lchild);
        else//左子树缺
            flag1 = true;
        
        if(q.front()->rchild)
            q.push(q.front()->rchild);
        else//右子树缺
            flag2 = true;

        if(flag1&&flag2)//两棵树都缺
            mark = true;
        else if(flag1)//缺右不缺左，完蛋
            isfull = false;
        else if(flag2)
        {
            if(mark)
                isfull = false;
            mark = true;
        }
        else//都不缺
            if(mark)
                isfull = false;
        q.pop();
    }
    if(isfull)
        cout<<endl<<"YES"<<endl;
    else
        cout<<endl<<"NO"<<endl;
    return 0;
}