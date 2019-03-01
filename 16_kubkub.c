#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(void)
{
int itog= 0;
int count = 0 ;
int nomer= 0 ;
scanf ("%d",&count);
for (int i=1;i<=count;i++)
{
scanf("%d",&nomer);
nomer = abs(nomer);
itog = itog + (pow(-1,i+1)*pow(nomer,3));
nomer = 0;
}
printf("%d",itog);
}
