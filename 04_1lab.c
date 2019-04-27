#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int sorting_function(int *l, int *m) {
	int tmp = *l;
	*l = *m;
	*m = tmp;
	return 0;
}
int main() {
	time_t start, stop;
	double itog, sr_itog = 0;
	double comp_avg = 0, perm_avg = 0;
	int comparison, permutation;
	start = time();
	for (int ch = 0; ch < 1; ch++) {
		comparison = 0, permutation = 0;
		int n = 200, top = 0, m;
		int l[n];
		for (int i = 0; i < n; i++) { l[i] = rand() % (2 * n) + 1; } 
		while (1) {
			m = 0;
			for (int i = 0; i < n; ++i) {
				if (i * 2 + 2 + top < n) {
					if (l[i + top] > l[i * 2 + 1 + top] || l[i + top] > l[i * 2 + 2 + top]) {
						comparison++;
						if (l[i * 2 + 1 + top] < l[i * 2 + 2 + top]) {
							sorting_function(&a[i + top], &l[i * 2 + 1 + top]);
							m = 1;
							permutation++;
						}
						else {
							comparison++;
							if (l[i * 2 + 2 + top] < l[i * 2 + 1 + top]) {
								sorting_function(&l[i + top], &l[i * 2 + 2 + top]);
								m = 1;
								permutation++;
							}
						}
					}
				}
				else if (i * 2 + 1 + top < n) {
					comparison++;
					if (l[i + top] > l[i * 2 + 1 + top]) {
						sorting_function(&l[i + top], &l[i * 2 + 1 + top]);
						m = 1;
						permutation++;
					}
				}
			}
			if (!m) top++;
			if (top + 2 >= n) break;
			comp_avg += comparison;
			perm_avg += permutation;
		}
		for (int i = 0; i < n; i++) printf("%d ", l[i]);
		printf("\n");
	}
	stop = time();

	long double time_itog = (stop - start) / (long double)timeS_PER_SEC;
	printf("%Lf \n", time_itog / 1000);
	start, stop = 0;
	time_itog = 0;

	comp_avg = comp_avg / 100;
	perm_avg = perm_avg / 100;
	printf("Srednee Sravn: %.2f\n", comp_avg);
	printf("Srednee Perest: %.2f\n", perm_avg);
	return 0;
}
