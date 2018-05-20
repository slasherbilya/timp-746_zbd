#include <stdio.h>
#include <stdlib.h>
typedef struct _node{
int key;
int val;
struct _node *l;
struct _node *r;
struct _node *parent;
} node;
node *getnode (int k,int v){
node *tmp=(node*)malloc(sizeof(node));
tmp->l=NULL;
tmp->r=NULL;
tmp->key=k;
tmp->val=v;
return tmp;
}
void add(node **root,int k,int v){
node* tmp=NULL;
if ((*root)==NULL){ (*root)=getnode(k,v);return;}
tmp=(*root);
if ((tmp->key)>k) {add(&(tmp->l),k,v);}else
if ((tmp->key)<=k) {add(&(tmp->r),k,v);}

}
node *search(node *root,int k){
if (!root) return NULL;
if ((root->key)>k){search(root->l,k);}else
if ((root->key)<k){search(root->r,k);}else
return root;
}
int searchlvl(node *root,int k,int lvl){
if (root==NULL){lvl=-1; return lvl;}else{
if ((root->key)>k){lvl++; searchlvl(root->l,k,lvl);}else
if ((root->key)<k){lvl++; searchlvl(root->r,k,lvl);}else
return lvl;}
}
void pre(node* root){
if(root){
printf("%d ",root->val);
pre(root->l);
pre(root->r);
}
}

int main(){
node *kek=NULL;
node *find=NULL;
int i,n,a,k1,v1,lv,lvl;
scanf("%d",&n);
for( i=0;i<n;i++){
scanf("%d%d",&k1,&v1);
add((&kek),k1,v1);
}
pre(kek);
printf("\n");
return 0;
}

