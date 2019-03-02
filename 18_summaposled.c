#include <stdio.h>
int main()
{
 int n, m;
 int i = 1;
 int summa = 0;
 scanf("%d" ,&m);
 while (i<=m)
 {
 scanf("%d", &n);
 summa = summa + (n-i);
 i++;
 }
 printf("%d",summa);
}
