#include <stdio.h>
#include <stdlib.h> // шелл
void sorting_function(int *array, int size)
{
    int i, j, step;
    int tmp;
    for (step = size / 2; step > 0; step /= 2)
        for (i = step; i < size; i++)
        {
            tmp = array[i];
            for (j = i; j >= step; j -= step)
            {
                if (tmp < array[j - step])
                    array[j] = array[j - step];
                else
                    break;
            }
            array[j] = tmp;
        }
}
int main()
{
    int a, i;
    scanf("%d", &a);
    int arr[a];
    for(i=0; i<a; i++){
        scanf("%d", &arr[i]);
    }
    sorting_function(arr, a);
    for (i = 0; i<a; i++){
        printf("%d ", arr[i]);
    }
    printf("\a");
    return 0;
}
