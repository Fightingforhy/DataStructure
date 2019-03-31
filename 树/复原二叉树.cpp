#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
struct node{
    char data;
    node *lchild;
    node *rchild;
};
string pre,in,post;
int n;
void postorder(node *root);
 
node* creat(int prel,int prer,int inl,int inr){
    if(prel>prer)    return  NULL;
    node *root=new node;
    root->data=pre[prel];
    int k;
    for(k=inl;k<=inr;k++){
        if(in[k]==pre[prel]){
            break;
        }
    }
    int numleft=k-inl;
    root->lchild =creat(prel+1,prel+numleft,inl,k-1);
    root->rchild =creat(prel+numleft+1,prer,k+1,inr);
    return root;
}
void postorder(node *root){
    if(root==NULL){
        return ;
    }
    postorder(root->lchild );
    postorder(root->rchild );
    printf("%c",root->data);
}
int main(){
    while(cin>>pre>>in){
        node *root=creat(0,pre.size()-1,0,in.size()-1);
        postorder(root);
        printf("\n");
    }
    return 0;
}
