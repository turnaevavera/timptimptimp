#include <stdio.h>
int main()
{
 int summa = 0;
 int i = 1;
 int n, m;
 scanf("%d" ,&m);
 while (i<=m)
 {
 scanf("%d", &n);
 summa = summa + (n-i);
 i++;
 }
 printf("%d",summa);
}
