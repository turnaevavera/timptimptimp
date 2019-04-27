#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void sorting_function(int* arr, int left, int right, int *perestan, int *sravnenie)
{
    int i = left, j = right;
    double tmp, x = arr[(left + right) / 2];
    do {
        while (arr[i] < x)
            i++;
        while (arr[j] > x)
            j--;
		(*sravnenie)++;
        if (i <= j)
        {
            if (i < j)
            {
                tmp=arr[i];
                arr[i]=arr[j];
                arr[j]=tmp;
				(*perestan)++;
            }
            i++;
            j--;
        }
    } while (i <= j);
    if (i < right)
        sorting_function(arr, i, right, &(*perestan),&(*sravnenie));
    if (left < j)
        sorting_function(arr, left,j, &(*perestan),&(*sravnenie));
}
int main()
{
	clock_t start,stop;
    double result,sr_result = 0;
    double avg_sravn=0,avg_perestn=0;
    int sravn,perestn;
    start = clock();
    for(int ch=0;ch<100;ch++){
        int n=20;
        sravn=0,perestn=0;
        int arr[n];
        for(int i=0;i<n;i++){arr[i]=rand()%(2*n)+1;} // наилучший {arr[i]=n + i - 199;} // наихудший {arr[i]=n-i}; 
        sorting_function(arr,0,n,&perestn,&sravn);
        for(int i=0;i<n;i++){ printf("%d ", arr[i]); } //отсортированный масси
        avg_sravn+=sravn;
        avg_perestn+=perestn;
    }
    stop = clock();
    long double clock_result = (stop - start)/(long double)CLOCKS_PER_SEC;
    printf("%Lf \n",clock_result/1000);
    start ,stop = 0;
    clock_result = 0;
    avg_sravn=avg_sravn/100;
    avg_perestn=avg_perestn/100;
    printf("average sravn: %.0f\n",avg_sravn);
    printf("average perestn: %.2f\n",avg_perestn);
    return 0;
}
