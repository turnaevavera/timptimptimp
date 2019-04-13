#include <stdio.h>
#include <stdlib.h>
void sort_func(int *num, int root, int lenght)
{
    int max;
    int acc = 0;
    while ((root * 2 <= lenght) && (!acc))
    {
        if (root * 2 == lenght){
            max = root * 2;
        }
        else if (num[root * 2] > num[root * 2 + 1]){
            max = root * 2;
        }else{
            max = root * 2 + 1;
        }
        if (num[root] < num[max])
        {
            int temp = num[root];
            num[root] = num[max];
            num[max] = temp;
            root = max;
        }else
            acc = 1;
    }
}
void sort_function(int *num, int array_size)
{
    for (int i = (array_size / 2) - 1; i >= 0; i--)
        sort_func(num, i, array_size);
    for (int i = array_size - 1; i >= 1; i--)
    {
        int temp = num[0];
        num[0] = num[i];
        num[i] = temp;
        sort_func(num, 0, i - 1);
    }
}
int main()
{
    int a, i;
    scanf("%d", &a);
    int m[a];
    for(i=0; i<a; i++){
        scanf("%d", &m[i]);
    }
    sort_function(m, a);
    for (i = 0; i<a; i++){
        printf("%d ", m[i]);
    }
    printf("\a");
    return 0;
}
