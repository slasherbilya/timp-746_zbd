#include <stdio.h>
#include<stdbool.h>
#include<stdlib.h>
typedef struct _node {
int value;
struct _node *next;
struct _node *prev;
} node;
typedef struct  _klist{
size_t size;
node *head;
node *tail;
} klist;
klist *createklist(){
klist *tmp = (klist*) malloc(sizeof(klist));
tmp->size=0;
tmp->head=NULL;
tmp->tail=NULL;
return tmp;
}
bool empty(klist *list){
if ((list)=NULL)return true; else return false;
}
void deleteklist(klist *list){
while(list->head){
        list->tail=list->head->next;
        free(list->head);
        list->head=list->tail;
}free(list);
list=NULL;
}
void push(klist *list,int value){
node *tmp =(node*)malloc(sizeof(node));
tmp->value=value;
tmp->next=NULL;
tmp->prev=list->tail;
if(list->tail){list->tail->next=tmp;}
list->tail=tmp;
if(list->head==NULL){list->head=tmp;}
list->size++;
}
node *getval(klist *list,int val){
node *tmp=list->head;
node *tmp1=list->tail;
int p=tmp->value;
while((tmp)&&(p!=val))
{
        tmp=tmp->next;
        p=tmp->value;
}
if (p!=val) return tmp=NULL;
return tmp;
}
node *getN(klist *list,size_t index){
node *tmp=list->head;
size_t i=1;
while((tmp)&&(i<index)){
        tmp=tmp->next;
        i++;
        }
return tmp;
}
void pushfr(klist *list,int val1){
node *tmp=(node*)malloc(sizeof(node));
tmp->prev=NULL;
tmp->value=val1;
if(list->head){list->head->prev=tmp; tmp->next=list->head;}
list->head=tmp;
if (list->tail==NULL){list->tail=tmp;}
list->size++;
}
void insert(klist *list,size_t index, int value)
{
node *l=NULL;
node *ins=NULL;
l=getN(list,index);
if (l==NULL) {exit(0);}
ins=(node*)malloc(sizeof(node));
ins->value=value;
ins->prev=l;
ins->next=l->next;
if (l->next){l->next->prev=ins;}
l->next=ins;
if(!l->prev){list->head=l;}
if(!l->next){list->tail=l;}
list->size++;
}
void *deleteNumb(klist *list,size_t index){
node *l=NULL;
node *tmp=NULL;
l=getN(list,index);
if (l==NULL){exit(0);}
if(l->prev){l->prev->next=l->next;}
if(l->next){l->next->prev=l->prev;}
if(!l->prev){list->head=l->next;}
if(!l->next){list->tail=l->prev;}
free(l);
list->size--;
}
void *deleteval(klist *list,int value){
node *l=NULL;
node *tmp=NULL;
l=getval(list,value);
if (l==NULL){exit(0);}
if(l->prev){l->prev->next=l->next;}
if(l->next){l->next->prev=l->prev;}
if(!l->prev){list->head=l->next;}
if(!l->next){list->tail=l->prev;}
free(l);
list->size--;
}
void show(klist *list){
node *tmp=list->head;
while(tmp){
        printf("%d",tmp->value);
        if(tmp->next) printf(" ");
tmp=tmp->next;
}
printf("\n");
}
void main(){
klist *kek=createklist();
int x,a,b,c,d,k,m,n,prov;
scanf("%d",&n);
for (int i=0;i<n;i++)
{
scanf("%d",&x);
push(kek,x);
}
show(kek);
scanf("%d",&k);
deleteNumb(kek,k);
show(kek);
scanf("%d",&m);
deleteval(kek,m);
show(kek);
scanf("%d%d",&a,&b);
insert(kek,a,b);
show(kek);
scanf("%d%d",&c,&d);
if (c==1){pushfr(kek,d);}else insert(kek,c-1,d);
show(kek);
deleteklist(kek);
}
