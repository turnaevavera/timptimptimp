#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int sorting_function(int *rrr, int *ooo) {//пирамидальная
	int tmp = *rrr;
	*rrr = *ooo;
	*ooo = tmp;
	return 0;
}
int main() {
	clock_t start, stop;
	double rez, sr_itog = 0;
	double comp_avg = 0, perm_avg = 0;
	int comparison, permutation;
	start = clock();
	for (int ch = 0; ch < 1; ch++) {
		comparison = 0, permutation = 0;
		int n = 200, step = 0, ooo;
		int rrr[n];
		for (int i = 0; i < n; i++) { rrr[i] = rand() % (2 * n) + 1; } // наилучший {a[i]=n + i - 199;} // наихудший {a[i]=n-i;}
		while (1) {
			ooo = 0;
			for (int i = 0; i < n; ++i) {
				if (i * 2 + 2 + step < n) {
					if (rrr[i + step] > rrr[i * 2 + 1 + step] || rrr[i + step] > rrr[i * 2 + 2 + step]) {
						comparison++;
						if (rrr[i * 2 + 1 + step] < rrr[i * 2 + 2 + step]) {
							sorting_function(&rrr[i + step], &rrr[i * 2 + 1 + step]);
							ooo = 1;
							permutation++;
						}
						else {
							comparison++;
							if (rrr[i * 2 + 2 + step] < rrr[i * 2 + 1 + step]) {
								sorting_function(&rrr[i + step], &rrr[i * 2 + 2 + step]);
								ooo = 1;
								permutation++;
							}
						}
					}
				}
				else if (i * 2 + 1 + step < n) {
					comparison++;
					if (rrr[i + step] > rrr[i * 2 + 1 + step]) {
						sorting_function(&rrr[i + step], &rrr[i * 2 + 1 + step]);
						ooo = 1;
						permutation++;
					}
				}
			}
			if (!ooo) step++;
			if (step + 2 >= n) break;
			comp_avg += comparison;
			perm_avg += permutation;
		}
		for (int i = 0; i < n; i++) printf("%d ", rrr[i]);
		printf("\n");
	}
	stop = clock();

	long double clock_itog = (stop - start) / (long double)CLOCKS_PER_SEC;
	printf("%Lf \n", clock_itog / 1000);
	start, stop = 0;
	clock_itog = 0;

	comp_avg = comp_avg / 100;
	perm_avg = perm_avg / 100;
	printf("Average Sravn: %.2f\n", comp_avg);
	printf("Average Perest: %.2f\n", perm_avg);
	return 0;
}
