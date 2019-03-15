#include <stdio.h>
#include<stdlib.h>

struct pampam {
	int zna4;
	struct pampam *next;
	struct pampam *prev;
} pampam;

struct lisstt {
	struct pampam* first;
	struct pampam* last;
} lisstt;

int isEmpty(struct lisstt* spissokk)
{
	return spissokk->first == NULL && spissokk->last == NULL;
}

struct pampam* find(struct lisstt* spissokk, int k)
{
	struct pampam *nnn = spissokk->first;
	while (nnn->zna4 != k) {
		if (nnn->next != NULL) {
			nnn = nnn->next;
		}
		else {
			return 0;
		}
	}
	return nnn;
}

struct pampam* find_invers(struct lisstt* spissokk, int k)
{
	struct pampam *nnn = spissokk->last;
	while (nnn->zna4 != k) {
		if (nnn->prev != NULL) {
			nnn = nnn->prev;
		}
		else {
			return 0;
		}
	}
	return nnn;
}

void init(struct lisstt* spissokk, int zna4)
{
	struct pampam* nnn;
	nnn = (struct pampam*)malloc(sizeof(struct pampam));
	nnn->zna4 = zna4;
	nnn->next = NULL;
	nnn->prev = NULL;
	spissokk->first = nnn;
	spissokk->last = nnn;
}

int push_back(struct lisstt* spissokk, int x)
{
	if (isEmpty(spissokk) == 1)
		init(spissokk, x);
	else
	{
		struct pampam *nnn = (struct pampam*)malloc(sizeof(struct pampam));
		nnn->zna4 = x;
		nnn->prev = spissokk->last;
		nnn->next = NULL;
		spissokk->last = nnn;
		nnn->prev->next = nnn;
	}
	return 0;
}

int push_front(struct lisstt* spissokk, int x)
{
	if (isEmpty(spissokk) == 1)
		init(spissokk, x);
	else
	{
		struct pampam *nnn = (struct pampam*)malloc(sizeof(struct pampam));
		nnn->zna4 = x;
		nnn->prev = NULL;
		nnn->next = spissokk->first;
		spissokk->first = nnn;
		nnn->next->prev = nnn;
	}
	return 0;
}

int clear(struct lisstt* spissokk)
{
	if (isEmpty(spissokk) == 1)
	{
		struct pampam *nnn = spissokk->first;
		struct pampam *nana = NULL;
		while (nnn != NULL)
		{
			nana = nnn->next;
			free(nnn);
			nnn = nana;
		}
		spissokk->first = NULL;
		spissokk->last = NULL;
	}
}

void _remove(struct lisstt* spissokk, struct pampam *nnn) {
	if (nnn != NULL) {
		if (nnn == spissokk->first && nnn == spissokk->last) {
			clear(spissokk);
			return;
		}
		if (nnn == spissokk->first)
		{
			spissokk->first = nnn->next;
			nnn->next->prev = NULL;
		}
		else if (nnn == spissokk->last)
		{
			spissokk->last = nnn->prev;
			nnn->prev->next = NULL;
		}
		else if (nnn != spissokk->first && nnn != spissokk->last)
		{
			nnn->next->prev = nnn->prev;
			nnn->prev->next = nnn->next;
		}
		free(nnn);
	}
}

int removeLast(struct lisstt* spissokk, int x)
{
	struct pampam* element = find_invers(spissokk, x);
	if (element != NULL) {
		_remove(spissokk, element);
		return 0;
	}
	return -1;
}

int removeFirst(struct lisstt* spissokk, int x)
{
	struct pampam* element = find(spissokk, x);
	if (element != NULL) {
		_remove(spissokk, element);
		return 0;
	}
	return -1;
}

int insertAfter(struct lisstt* spissokk, int num, int data)
{
	struct pampam* nnn = spissokk->first;
	for (int i = 1; i < num; i++)
	{
		nnn = nnn->next;
		if (nnn == NULL)
			return -1;
	}
	struct pampam *nana = malloc(sizeof(pampam));
	nana->zna4 = data;
	nana->next = nnn->next;
	nana->prev = nnn;
	nnn->next->prev = nana;
	nnn->next = nana;
	return 0;
}

int insertBefore(struct lisstt* spissokk, int num, int data)
{
	struct pampam* nnn = spissokk->first;
	for (int i = 1; i < num; i++)
	{
		nnn = nnn->next;
		if (nnn == NULL)
			return -1;
	}
	struct pampam *nana = malloc(sizeof(pampam));
	nana->zna4 = data;
	nana->prev = nnn->prev;
	nana->next = nnn;
	nnn->prev = nana;
	nana->prev->next = nana;
	return 0;
}

void print(struct lisstt* spissokk)
{
	struct pampam* nnn = spissokk->first;
	while (nnn->next != NULL)
	{
		printf("%d ", nnn->zna4);
		nnn = nnn->next;
	}
	printf("%d\n", nnn->zna4);
}

void print_invers(struct lisstt* spissokk)
{
	struct pampam* nnn = spissokk->last;
	while (nnn->prev != NULL)
	{
		printf("%d ", nnn->zna4);
		nnn = nnn->prev;
	}
	printf("%d\n", nnn->zna4);
}



int main()
{
	int n, a;
	struct lisstt* struc = (struct lisstt*)malloc(sizeof(struct lisstt));
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a);
		push_back(struc, a);
	}
	print(struc);

	int k[3];
	scanf("%d%d%d", &k[0], &k[1], &k[2]);
	for (int i = 0; i < 3; i++) {
		if (find(struc, k[i]) != NULL)
			printf("1 ");
		else
			printf("0 ");
	}
	printf("\n");

	int m;
	scanf("%d", &m);
	push_back(struc, m);
	print_invers(struc);

	int t;
	scanf("%d", &t);
	push_front(struc, t);
	print(struc);

	int j, x;
	scanf("%d%d", &j, &x);
	insertAfter(struc, j, x);
	print_invers(struc);

	int u, y;
	scanf("%d%d", &u, &y);
	insertBefore(struc, u, y);
	print(struc);
	int z;
	scanf("%d", &z);
	removeFirst(struc, z);
	print_invers(struc);
	int r;
	scanf("%d", &r);
	removeLast(struc, r);
	print(struc);

	clear(struc);
	return 0;
}
