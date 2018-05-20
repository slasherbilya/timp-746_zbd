#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void sort_shell(int *m,int n)
{
int tmp,k,i,j;
int s=n;
while (s>0){
s/=2;
for (i=0;i<n-s;++i){
        j=i;
        while((j>=0)&&(m[j]>m[j+s])){
        tmp=m[j]; m[j]=m[j+s];m[j+s]=tmp;
        j--;
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
sort_shell(p,n);
for (i=0;i<n;i++){
printf("%d ",arr[i]);
}
printf("\n");
}

