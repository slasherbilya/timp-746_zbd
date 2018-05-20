
#include <stdio.h>
int main()
{
    int x,n,count=0,i;
    scanf("%d",&n);
for (i=1;i<=n;i++)
        {
        scanf("%d",&x);
        if (x>0) {count++;}
        }
        printf("%d\n",count);
        return 0;
}
