#include <stdio.h>
#include <stdlib.h>
#include <time.h> // шелл
void sorting_function(int *mass, int razmer, int *perestan, int *sravn)
{
    int i, j, step;
    int tmp;
    for (step = razmer / 2; step > 0; step /= 2)
        for (i = step; i < razmer; i++)
        {
            tmp = mass[i];
            for (j = i; j >= step; j -= step)
            {
				(*sravn)++;
                if (tmp < mass[j - step])
                    mass[j] = mass[j - step];
                else
                    break;
            }
            mass[j] = tmp;
			(*perestan)++;
        }
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
        sorting_function(arr,n,&perestn,&sravn);
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
