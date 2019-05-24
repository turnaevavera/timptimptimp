#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

int* Dextree(int arr[5][5], int size, int v) {
	int *pyti ;
	pyti= (int*)malloc(size * sizeof(int));
	for (int i = 0; i < size; i++) {
		if (i == v) pyti[i] = 0;
		else pyti[i]= 100000;
	}
	int t, min, mid, pos[5] = { 1,1,1,1,1 };
	do {
		min = 100000; mid = 100000;
		for (int i = 0; i < size; i++) {
			if ((pos[i] == 1) && (pyti[i] < 100000)) {
				min = pyti[i];
				mid = i;
			}
		}
		if (mid != 100000) {
			for (int i = 0; i < size; i++) {
				if (arr[mid][i] > 0) {
					t = min + arr[mid][i];
					if (t < pyti[i]) pyti[i] = t;
				}
			}
			pos[mid] = 0;
		}
	} while (mid < 100000);
	return pyti;
}

void swap(int *a, int *b)
{
    int t;
    
    t = *a, *a = *b, *b = t;
}

int TSP(int *a, int graph[5][5], int n, int cost)
{
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (i == j) graph[i][j] = 0;
			else {
				if (graph[i][j] == 0) graph[i][j] = 100000;
			}
		}
	}
	int temp = 0;
	int g = 0;
	int sum = 0;
	for (int i = 0; i <= n - 1; i++) sum += graph[a[i % 5]][a[(i + 1) % 5]];
	if (cost > sum) cost = sum;
	while (g < 119) {
		sum = 0;
		int j = n - 2;
		while (j != -1 && a[j] >= a[j + 1]) j--;
		if (j == -1) g = 119;
		int k = n - 1;
		while (a[j] >= a[k]) k--; {
			swap(&a[j], &a[k]);
		}
		int l = j + 1, r = n - 1;
		while (l < r) swap(&a[l++], &a[r--]);
		for (int i = 0; i <= n - 1; i++) sum += graph[a[i % 5]][a[(i + 1) % 5]];
		if (cost > sum) cost = sum;
		g++;
	};
	return cost;
}

int main() {
	const int V = 5;
	int graf[V][V];
	int *arr;
	arr =  (int*)malloc(V * sizeof(int));
	int counter = 1;
	for (int i = 0; i < V; i++) {
	    arr[i] += i;
		for (int j = 0; j < V; j++) {
			if (i != j) {
				printf( "Если вершина %d соеденина с вершиной %d введите вес ребра, если они не соеденены введите 0: ",i+1,j+1);
				scanf("%d",&graf[i][j]);
			}
			else graf[i][j] = 0;
		}
	}
	printf("Матрица смежности:\n") ;
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			printf ("%d " ,graf[i][j]);
		}
		printf("\n");
	}
	int nv;
	printf("Введите номер начальной вершины:");
	scanf("%d",&nv);
	int *p = Dextree(graf, V, nv-1);
	for (int i = 0; i < 5; i++) {
		if (p[i] >= 100000) {
		    printf("Из вершины %d невозможно попасть в вершину %d \n",nv,i+1);
		}
		else {
		    printf("Кратчайший путь от вершины %d до вершины %d : %d \n",nv,counter,p[i]);
		}
		counter++;
	}
	int p2 = TSP(arr, graf, V, 100000);
	if (p2 >= 100000) {
	    printf("Невозможно пройти через все вершины!");
	}
	else {
	    printf("Контур минимальной длины равен: %d\n" ,p2);
	}
}
