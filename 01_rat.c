#include <stdio.h>
void sorting_function(int* arr, int left, int right)
{
    int i = left, j = right;
    double tmp, x = arr[(left + right) / 2];
    do {
        while (arr[i] < x)
            i++;
        while (arr[j] > x)
            j--;
        if (i <= j)
        {
            if (i < j)
            {
                tmp=arr[i];
                arr[i]=arr[j];
                arr[j]=tmp;
            }
            i++;
            j--;
        }
    } while (i <= j);
    if (i < right)
        sorting_function(arr, i, right);
    if (left < j)
        sorting_function(arr, left,j);
}
int main()
{
    int a, i;
    scanf("%d", &a);
    int arr[a];
    for(i=0; i<a; i++){
        scanf("%d", &arr[i]);
    }
    sorting_function(arr,0,a-1);
    for(i=0; i<a; i++){
        printf("%d ", arr[i]);
    }
    printf("\a");
}
