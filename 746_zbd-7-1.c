#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void sort_ras(int *m,int n)
{
int tmp,k,i;
int s=n;
while (s>1){
s/=1.2473309;
if (s<1) s=1;
        for (i=0;i+s<n;++i){
        if(m[i]>m[i+s]){
        tmp=m[i]; m[i]=m[i+s];m[i+s]=tmp;
        }
        }
}
return;
}
int main(){
int n,i;
scanf("%d",&n);
int arr[n];
int *p=arr;
srand(time(NULL));
for (i=0;i<n;i++){
scanf("%d",&arr[i]);
}
sort_ras(p,n);
for (i=0;i<n;i++){
printf("%d ",arr[i]);
}
printf("\n");
}
