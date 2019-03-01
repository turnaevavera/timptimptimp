#include <stdio.h>

int main()
{
unsigned int n;
int s, m=0;
scanf ("%d",&n);
for(int i=0; i<n; i++)
{
scanf ("%d", &s);
if (s>0) 
{
m++;
}
}
printf ("%d\n", m);
return 0;
}
